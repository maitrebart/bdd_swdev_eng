#!/bin/bash
echo "Checking docker service..."
docker ps >&/dev/null
if [ $? != 0 ]; then
    echo "Error: No docker service running"
    exit 1
fi
if [ ! -f ./Dockerfile ]; then
    echo "Error: No Dockerfile in current folder"
    exit 2
fi
docker run -it --rm --name filesysio -v "$PWD":/home/project -w /home/project abeimler/simple-cppbuilder /bin/bash
