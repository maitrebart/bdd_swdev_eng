#!/bin/bash
if [ -d ./src/tst2 ]; then
    cd src/tst2 && \
    mkdir -p ./build && \
    c++ -std=c++23 -DUSE_FILESYSIO_LIB -o build/thebestts2 -I ./include -I ../tst2/lib/include -I ../tst/include -I ../lib/include -I ./lib/include \
        ./ts_config/parse.cpp ./lib/fake_filesysio.cpp ../tst/main.cpp ../tst/fake_factory.cpp ../tst/ts_common.cpp ../lib/config_parser.cpp ../lib/factory.cpp ../lib/facade.cpp && \
    ls -l ./build
else
    echo "Error: No ./src/tst2 directory found in current folder"
    exit 1
fi
