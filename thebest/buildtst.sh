#!/bin/bash
if [ -d ./src/tst ]; then
    cd src/tst && \
    mkdir -p ./build && \
    c++ -g -O0 -std=c++23 -I ./include -I ../lib/include/ -o ./build/thebestts `find . ../lib -name '*.cpp' -print` && \
    ls -l ./build
else
    echo "Error: No ./src/tst directory found in current folder"
    exit 1
fi
