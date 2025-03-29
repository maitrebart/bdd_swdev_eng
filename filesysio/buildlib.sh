#!/bin/bash
if [ -d ./src/lib ]; then
    cd src/lib && \
    mkdir -p ./build && \
    find . -maxdepth 1 -name '*.cpp' -exec c++ -c -g -O0 -fPIC -std=c++23 -I ./include -o build/{}.o {} \; && \
    ar rfs ./build/libfilesysio.a build/*.o && \
    ls -l ./build
else
    echo "Error: No ./src/lib directory found in current folder"
    exit 1
fi
