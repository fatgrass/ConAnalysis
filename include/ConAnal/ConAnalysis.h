//===---------------------------- ConAnalysis.h ---------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is a skeleton of an implementation for the ConAnalysis
// pass of Columbia University in the City of New York. For this program,
// our goal is to find those particular concurrency bugs that will make
// the system vulnerable to malicious actions.
//
//===----------------------------------------------------------------------===//

#ifndef CONANAL_H
#define CONANAL_H

#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/CallSite.h"
#include "llvm/IR/DebugInfo.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Analysis/CallGraph.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
#include <cstdint>
#include <list>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <map>

using namespace llvm;

/* <functionName, fileName, lineNum> */
typedef std::list<std::tuple<std::string, std::string, uint32_t>> CallStackInput;

typedef struct {
  char fileName[200];
  char funcName[100];
  int lineNum;
  Instruction * danOpI;
} part2_input;

namespace ConAnal {
  class ConAnalysis : public ModulePass {
    public:
      static char ID; // Pass identification, replacement for typeid
      ConAnalysis() : ModulePass(ID) {
      }

      ///
      void printList(std::list<Value *> &inputset);
      ///
      void printSet(std::set<BasicBlock *> &inputset);
      /// This method reads the initial value of callstack from 
      /// the associated file that belongs to each part of the analysis.
      void parseInput(std::string inputfile,
                      CallStackInput &csinput);
      /// This method intialize the call stack for our analysis
      void initializeCallStack(CallStackInput &csInput);
      ///
      virtual bool runOnModule(Module &M);
      /// This method create two maps.
      /// The first map is:
      /// Instruction -> Number
      /// The second map is:
      /// <FileName, lineNum> -> Instruction
      virtual bool createMaps(Module &M);
      ///
      virtual bool printMap(Module &M);
      /// 
      virtual bool part1_getCorruptedIRs(Module &M);
      ///
      virtual bool intra_dataflow_analysis(Function *, Instruction *, 
                                           std::set<uint32_t>& corruptedparams);
      ///
      virtual bool part2_getDominantFrontiers(Module &M, 
                                              CallStackInput &csinput);
      ///
      virtual bool part3_getFeasiblePath(Module &M, 
                                         std::list<Value *> &dominantfrontiers);
      ///
      void computeDominators(Function &F, std::map<BasicBlock *,
                             std::set<BasicBlock *>> & dominators);
      ///
      void printDominators(Function &F, std::map<BasicBlock *,
                           std::set<BasicBlock *>> & dominators);
      ///
      void get_corruptedMap(Instruction *I);

      ///
      bool cmp_Maps(Instruction * I);

      //**********************************************************************
      // print (do not change this method)
      //
      // If this pass is run with -f -analyze, this method will be called
      // after each call to runOnModule.
      //**********************************************************************
      virtual void print(std::ostream &O, const Module *M) const;

      //**********************************************************************
      // getAnalysisUsage
      //**********************************************************************

      // We don't modify the program, so we preserve all analyses
      virtual void getAnalysisUsage(AnalysisUsage &AU) const {
        AU.setPreservesAll();
      };
    private:
      std::string corruptedVar_;
      std::map<Instruction *, int> ins2int_;
      uint64_t ins_count_ = 1;
      /// <fileName, lineNum> -> list<Instruction *>
      std::map<std::pair<std::string, uint32_t>,
               std::list<Instruction *>> sourcetoIRmap_;
      std::set<Value *> corruptedIR_;
      std::list<Value *> orderedcorruptedIR_;
      //std::list<Value *> dominantfrontiers_;
      /*std::list<Value *> feasiblepath_;*/
      std::list<std::pair<Function *, Instruction *>> callstack_;
      std::map<Value *, std::list<Value *>> corruptedMap_;
  };
}

#endif
