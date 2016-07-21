#!/usr/bin/python2.7

import lldb
import sys
import random
import time
import threading

# USER SET GLOBAL VARIABLES
# Stable state wait time (in seconds, ie. 0.1 = 100ms), default = 1
WAIT_TIME = 1

# DO NOT CHANGE
LAST_BREAK = 0
RUNNING = False
OBJ_ARR = []
THREAD_ARR = []

FILE_READ = ""
LINE_NUM_READ = 0
COLUMN_NUM_READ = 0
FILE_WRITE = ""
LINE_NUM_WRITE = 0
COLUMN_NUM_WRITE = 0

# Locks
# TODO: Right now locking mechanism is very coarse grained.  Future work should aim
# to improve the granularity of locks to increase performance
timer_lock = threading.Lock()
process_lock = threading.Lock()


def set_trigger():
	print "Setting breakpoints..."
	target = lldb.debugger.GetSelectedTarget()

	global FILE_READ
	global LINE_NUM_READ
	global COLUMN_NUM_READ
	global FILE_WRITE
	global LINE_NUM_WRITE
	global COLUMN_NUM_WRITE

	in_read = "cache_util.c:284:11"
	in_write = "mod_mem_cache.c:885:9"

	tokens_read = in_read.split(":")
	tokens_write = in_write.split(":")

	FILE_READ = tokens_read[0]
	LINE_NUM_READ = int(tokens_read[1])
	COLUMN_NUM_READ = int(tokens_read[2])

	FILE_WRITE = tokens_write[0]
	LINE_NUM_WRITE = int(tokens_write[1])
	COLUMN_NUM_WRITE = int(tokens_write[2])

	bp_read = target.BreakpointCreateByLocation(FILE_READ, LINE_NUM_READ)
	bp_write = target.BreakpointCreateByLocation(FILE_WRITE, LINE_NUM_WRITE)

	bp_read.SetScriptCallbackFunction("trigger.read_callback")
	bp_write.SetScriptCallbackFunction("trigger.write_callback")

	update_timer()
	timer()

	print("Configuration done!")


# Release a thread if stable state is reached
def timer():
	process_lock.acquire()

	global RUNNING

	if RUNNING and time.time() - LAST_BREAK > WAIT_TIME:
		process = lldb.debugger.GetSelectedTarget().GetProcess()

		RUNNING = False

		update_timer()
		release_bp()

		RUNNING = True
		process.Continue()

	process_lock.release()

	# We don't care about timing drift, we just want timer() to be called periodically
	threading.Timer(0.1, timer).start()

def update_timer():
	timer_lock.acquire()

	global LAST_BREAK
	LAST_BREAK = time.time()

	timer_lock.release()


# Check to see if every thread is at a breakpoint
# TODO: We need a better way to check if all threads are currently suspended..
# Sometimes not all threads will be suspended but program still stops, leaving 
# the job of releasing BPs to fall back to the timeout
def all_bp_hit():
	# Old mechanism. Just check if all threads are suspended..
#	for t in lldb.debugger.GetSelectedTarget().GetProcess():
#		if not t.IsSuspended():
#			return False
#
#	return True

	c = 0
	res = False

	for t in lldb.debugger.GetSelectedTarget().GetProcess():
		if t.IsSuspended():
			c += 1

	if c >= 10:
		res = True
	
	return res

# Expects process to already be stopped.  Will resume thread, but expects 
# process.Continue() to be called by calling function
def release_bp():
	process = lldb.debugger.GetSelectedTarget().GetProcess()

	# Check if process is invalid, can cause errors
	if process.IsValid() == False:
		print "######## WARNING: PROCESS IS INVALID ########"
		return

	global OBJ_ARR
	global THREAD_ARR

	obj_arr_len = len(OBJ_ARR)

	# No more suspended threads...
	if obj_arr_len == 0:
		return

	# Make sure process is stopped before modifying thread states

	rand = random.randrange(0, obj_arr_len)
	thread = process.GetThreadByID(THREAD_ARR[rand])

	process.SetSelectedThreadByID(thread.GetThreadID())

	print str(time.time()) + " >>>>>>>>>> INFO: Releasing thread " + str(thread.GetThreadID())

#	if process.state == lldb.eStateRunning:
	if not process.is_stopped:
		process.Stop()

	if thread.Resume() == False:
		print "### ERROR IN THREAD.RESUME() ###"
		return

	del OBJ_ARR[rand]
	del THREAD_ARR[rand]


# TSAN will sometimes not report accurate line numbers causing get_addr to fail
def get_addr(frame, filename, line_num, column_num):
	filespec = lldb.SBFileSpec(filename, False)
	if not filespec.IsValid():
		print " ####### FILESPEC INVALID ####### "
	
	source_mgr = lldb.debugger.GetSelectedTarget().GetSourceManager()
	stream = lldb.SBStream()
	source_mgr.DisplaySourceLinesWithLineNumbers(filespec, line_num, 0, 0, "", stream)

	# Needs some refinement.  Hacky so just exit on error
	try:
		# Ad-hoc way of getting source code, SourceManager isn't working...
		# Go through lldb command line, store result in res
		#
		# res = lldb.SBCommandReturnObject()
		# ci = lldb.debugger.GetCommandInterpreter()
		# ci.HandleCommand("source list -f " + filename + " -l " + str(line_num), res)

		# Get first line from output and cut out line number which is padded to one tab (8 spaces)
		# Unintended consequence is that this only supports line numbers up to 5 digits = 99,999
		# We don't think this is really that big of a deal because source files with > 100,000 lines
		# of code are very, very, very rare
		#
		# src_line = res.GetOutput().split("\n")[0]

		src_line = stream.GetData().split("\n")[0]
		obj_name = src_line[7 + column_num:]
		tmp = obj_name

		start = 0
		# This parsing mechanism assumes the use standard C coding styles, ie.
		# Spaces between operators, unambigious code, etc.
		break_chars = [" ", "\n", ",", ";", ")"]
		for i, char in enumerate(obj_name):
			if char == "(":
				start = i + 1

			if char in break_chars:
				obj_name = obj_name[start:i]
				break

		# Cut out any variable operator prefixes and postfixes
		break_misc = ["++", "--", "!", "*", "&"]
		for op in break_misc:
			obj_name = obj_name.replace(op, "")
	
	except (KeyboardInterrupt, SystemExit):
		raise

	except:
		print "####### ERROR: Unable to extract variable name from source #######"
		print sys.exc_info()[0]
		exit()

	# Debug info
#	print "[" + filename + ":" + str(line_num) + ":" + str(column_num) + "] >>> " + src_line
#	print "Sliced Variable >>> " + tmp
#	print "Extracted Variable >>> " + obj_name

	# Get SBValue object from extracted variable name
	obj = frame.EvaluateExpression(obj_name)

	# TODO: Exit on "No value", print error message
	return str(obj.GetAddress())


# True if addresses match and instructions differ
def match(addr):
	for obj in OBJ_ARR:
		if obj[0] == addr[0] and obj[1] != addr[1]:
			return True

	return False


def read_callback(frame, bp_loc, dict):
	thread = frame.GetThread()
	process = thread.GetProcess()
	ID = thread.GetThreadID()

	global OBJ_ARR
	global THREAD_ARR
	global RUNNING

	process_lock.acquire()

	RUNNING = False
	thread.Suspend()

	obj = get_addr(frame, FILE_READ, LINE_NUM_READ, COLUMN_NUM_READ)
	print str(time.time()) + " READ:  [" + str(ID) + "] Checking " + obj + "..."

	obj = [obj, "R"]

	if match(obj):
		print ">>>>>>>>>> READ:  [" + str(ID) + "] Found match!"

		tid = str(THREAD_ARR[OBJ_ARR.index([obj[0], "W"])])
		print "addr=" + obj[0] + "  tid1=" + tid + "  tid2=" + str(ID)
		print "**************************************************************"
		print "**************************** HALT ****************************"
		print "**************************************************************"
		process.Stop()

	else:
		update_timer()

		OBJ_ARR.append(obj)
		THREAD_ARR.append(ID)

		# Randomly select a thread to be released if all threads are suspended
		if all_bp_hit():
			release_bp()

		RUNNING = True
		process.Continue()

	process_lock.release()


def write_callback(frame, bp_loc, dict):
	thread = frame.GetThread()
	process = thread.GetProcess()
	ID = thread.GetThreadID()

	global OBJ_ARR
	global THREAD_ARR
	global RUNNING

	process_lock.acquire()

	RUNNING = False
	thread.Suspend()

	obj = get_addr(frame, FILE_WRITE, LINE_NUM_WRITE, COLUMN_NUM_WRITE)
	print str(time.time()) + " WRITE: [" + str(ID) + "] Setting  " + obj + "..."

	obj = [obj, "W"]

	if match(obj):
		print ">>>>>>>>>> WRITE: [" + str(ID) + "] Found match!"

		tid = str(THREAD_ARR[OBJ_ARR.index([obj[0], "R"])])
		print "addr=" + obj[0] + "  tid1=" + tid + "  tid2=" + str(ID)
		print "**************************************************************"
		print "**************************** HALT ****************************"
		print "**************************************************************"
		process.Stop()

	else:
		update_timer()

		OBJ_ARR.append(obj)
		THREAD_ARR.append(ID)

		# Randomly select a thread to be released if all threads are suspended
		if all_bp_hit():
			release_bp()

		RUNNING = True
		process.Continue()

	process_lock.release()


def __lldb_init_module(debugger, dict):
	print "Setting trigger..."
	set_trigger()

	# TODO: Let user specify program flags
	debugger.HandleCommand('run -k start -X')




