#!/bin/bash
if [ ! -d ../filesysio ]; then
    echo "Error: No ../filesysio directory found from current folder"
    exit 1
fi
if [ ! -d ./src/tst2 ]; then
    echo "Error: No ./src/tst2 directory found from current folder"
    exit 1
fi

mkdir -p ./src/tst2/lib/include/filesysio && \
mkdir -p ./src/tst2/build && \
cp -f ../filesysio/src/lib/include/filesysio/*.h ./src/tst2/lib/include/filesysio/ && \
cp -f ../filesysio/src/lib/build/libfilesysio.a ./src/tst2/build/ && \
ls -l ./src/tst2/lib/include/filesysio/*.h ./src/tst2/build/libfilesysio.a
