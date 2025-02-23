## build stage
FROM abeimler/simple-cppbuilder as build
COPY . .
CMD ["task", "-t", "/home/taskfiles/Taskfile.yml", "build"]

## test stage
FROM build as test
CMD ["task", "-t", "/home/taskfiles/Taskfile.yml", "test"]