#!/bin/bash
if [ -d ./src/app ]; then
    cd src/app && \
    mkdir -p ./build && \
    c++ -g -O0 -std=c++23 -I ../lib/include/ -o ./build/thebestapp `find . ../lib -name '*.cpp' -print` && \
    ls -l ./build
else
    echo "Error: No ./src/app directory found in current folder"
    exit 1
fi
