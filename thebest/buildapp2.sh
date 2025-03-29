#!/bin/bash
if [ -d ./src/app ]; then
    cd src/app && \
    mkdir -p ./build && \
    c++ -g -O0 -std=c++23 -DUSE_FILESYSIO_LIB -I ../lib/include/ -I ../tst2/lib/include -o ./build/thebestapp2 `find . ../lib -name '*.cpp' -print` -L ../tst2/build -lfilesysio && \
    ls -l ./build
else
    echo "Error: No ./src/app directory found in current folder"
    exit 1
fi
