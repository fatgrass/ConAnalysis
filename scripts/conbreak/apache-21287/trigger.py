#!/usr/bin/python2.7

import lldb
import commands
import argparse
import sys
import random
import time
import threading

# USER SET GLOBAL VARIABLES
# Stable state wait time (in seconds, ie. 0.1 = 100ms), default = 1
WAIT_TIME = 1

# DO NOT CHANGE
LAST_BREAK = 0
RUNNING = True
OBJ_ARR = []
THREAD_ARR = []

FILE_READ = ""
LINE_NUM_READ = 0
COLUMN_NUM_READ = 0
FILE_WRITE = ""
LINE_NUM_WRITE = 0
COLUMN_NUM_WRITE = 0

def set_trigger():
	print "Setting breakpoints..."
	target = lldb.debugger.GetSelectedTarget()

	global FILE_READ
	global LINE_NUM_READ
	global COLUMN_NUM_READ
	global FILE_WRITE
	global LINE_NUM_WRITE
	global COLUMN_NUM_WRITE

	in_read = "apr_tables.c:597:14"
	in_write = "mod_mem_cache.c:690:11"

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
	print("Configuration done!")


# Release a thread if stable state is reached
def timer():
	threading.Timer(0.1, timer).start()

	if RUNNING and time.time() - LAST_BREAK > WAIT_TIME:
		release_bp()


def update_timer():
	global LAST_BREAK
	LAST_BREAK = time.time()


# Check to see if every thread is at a breakpoint
def all_bp_hit():
	for t in lldb.debugger.GetSelectedTarget().GetProcess():
		if not t.IsSuspended():
			return False

	return True


def release_bp():
	process = lldb.debugger.GetSelectedTarget().GetProcess()
	
	# Check if process is invalid, can cause errors
	if process.IsValid() == False:
		#print "######## WARNING: PROCESS IS INVALID ########"
		return

	global OBJ_ARR
	global THREAD_ARR

	obj_arr_len = len(OBJ_ARR)

	# No more suspended threads...
	if obj_arr_len == 0:
		return

	rand = random.randrange(0, obj_arr_len)
	thread = process.GetThreadByID(THREAD_ARR[rand])

	print str(time.time()) + " >>>>>>>>>> TIMEOUT: Releasing thread " + str(thread.GetThreadID())

	del OBJ_ARR[rand]
	del THREAD_ARR[rand]

	thread.Resume()
	process.Continue()


def get_addr(frame, filename, line_num, column_num):
	# filespec = lldb.SBFileSpec(filename, False)
	# if not filespec.IsValid():
	# 	print " ####### FILESPEC INVALID ####### "
	
	# source_mgr = lldb.debugger.GetSourceManager()
	# stream = lldb.SBStream()
	# source_mgr.DisplaySourceLinesWithLineNumbers(filespec, line_num, 0, 0, "", stream)


	# Needs some refinement.  Hacky so just exit on error
	try:
		# Ad-hoc way of getting source code, SourceManager isn't working...
		# Go through lldb command line, store result in res
		res = lldb.SBCommandReturnObject()
		ci = lldb.debugger.GetCommandInterpreter()
		ci.HandleCommand("source list -f " + filename + " -l " + str(line_num), res)

		# Get first line from output and cut out line number which is padded to one tab (8 spaces)
		# Unintended consequence is that this only supports line numbers up to 5 digits = 99,999
		# We don't think this is really that big of a deal because source files with > 100,000 lines
		# of code are very, very, very rare and should be avoided at all costs anyway
		src_line = res.GetOutput().split("\n")[0]
		obj_name = src_line[7 + column_num:]

		start = 0
		# This parsing mechanism assumes the use standard C coding styles, ie.
		# Spaces between operators, unambigious code, etc.
		break_chars = [" ", "\n", ",", ";", ")"] # what about '-' and '*'?  Also ! & * as prefix
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
	#print "[" + filename + ":" + str(line_num) + "] >>> " + src_line
	#print "Extracted Variable >>> " + obj_name

	# Get SBValue object from extracted variable name
	obj = frame.EvaluateExpression(obj_name)
	return str(obj.GetAddress())


def match(addr):
	return addr in OBJ_ARR


def read_callback(frame, bp_loc, dict):
	thread = frame.GetThread()
	process = thread.GetProcess()
	ID = thread.GetThreadID()

	global OBJ_ARR
	global THREAD_ARR
	global RUNNING

	thread.Suspend()

	obj = get_addr(frame, FILE_READ, LINE_NUM_READ, COLUMN_NUM_READ)
	print str(time.time()) + " READ:  [" + str(ID) + "] Checking " + obj + "..."

	if match(obj):
		print ">>>>>>>>>> READ:  [" + str(ID) + "] Found match!"
		print "addr=" + obj + "  tid1=" + str(THREAD_ARR[OBJ_ARR.index(obj)]) + "  tid2=" + str(ID)
		print "**************************** HALT ****************************"
		RUNNING = False
		process.Stop()

	else:
		update_timer()

		OBJ_ARR.append(obj)
		THREAD_ARR.append(ID)

		# Randomly select a thread to be released if all threads are suspended
		if all_bp_hit():
			release_bp()
		else:
			process.Continue()


def write_callback(frame, bp_loc, dict):
	thread = frame.GetThread()
	process = thread.GetProcess()
	ID = thread.GetThreadID()

	global OBJ_ARR
	global THREAD_ARR
	global RUNNING

	thread.Suspend()

	obj = get_addr(frame, FILE_WRITE, LINE_NUM_WRITE, COLUMN_NUM_WRITE)
	print str(time.time()) + " WRITE: [" + str(ID) + "] Setting  " + obj + "..."

	if match(obj):
		print ">>>>>>>>>> WRITE: [" + str(ID) + "] Found match!"
		print "addr=" + obj + "  tid1=" + str(THREAD_ARR[OBJ_ARR.index(obj)]) + "  tid2=" + str(ID)
		print "**************************** HALT ****************************"
		RUNNING = False
		process.Stop()

	else:
		update_timer()

		OBJ_ARR.append(obj)
		THREAD_ARR.append(ID)

		# Randomly select a thread to be released if all threads are suspended
		if all_bp_hit():
			release_bp()
		else:
			process.Continue()


def __lldb_init_module(debugger, dict):
	print "Setting trigger..."
	set_trigger()
	timer()
	debugger.HandleCommand('run -k start -X')




