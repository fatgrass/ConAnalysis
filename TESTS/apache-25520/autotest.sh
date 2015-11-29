#!/bin/bash
set -x

if [ ! $# -eq 1 ]; then
  echo -e "Please input the argument"
  exit -1
fi

# The command will be called at top level of build folder
CONANAL_DIR=lib/ConAnal
DOL_DIR=lib/DOL
BITCODE_DIR=TESTS/${1}

cd ${BITCODE_DIR} && opt -mem2reg ${1}.bc -o ${1}.mem2reg && mv ${1}.mem2reg ${1}.bc
opt -load ../../$DOL_DIR/libDOL.so -load ../../$CONANAL_DIR/libConAnalysis.so -ConAnalysis ../../../TESTS/${1}/${1}.bc --ptrderef | grep ''
