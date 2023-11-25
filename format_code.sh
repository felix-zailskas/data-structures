#!/bin/bash

# get a list with all files with extension .c or .h
find . -type f \( -name "*.c" -o -name "*.h" \) > _found_files.txt

# format all found files
clang-format -i --files=_found_files.txt

rm _found_files.txt
