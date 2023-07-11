#!/bin/bash
#exec bash

# Error-cases:
./Replace
./Replace "./testFile/testFile_basic"
./Replace "file" " " "abc"

# Test-files
./Replace "./testFile/testEmpty" "?" "!"
./Replace "./testFile/testFile_basic" "evaluator" "Peer"
./Replace "./testFile/testFile_longLine" "." "Dot"
./Replace "./testFile/testNothingReplace" "abc" "Found it?"
