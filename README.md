# BDD/TDD-based Software Development for Engineering Projects <!-- omit from toc -->

## Table of contents  <!-- omit from toc -->

<!-- This TOC is generated using the "Markdown All in One" vscode extension -->
- [Introduction](#introduction)
- [Class diagram](#class-diagram)
- [Directory structure](#directory-structure)
	- [Under `./thebest`](#under-thebest)
	- [Under `./filesysio`](#under-filesysio)
- [To build thebest repo](#to-build-thebest-repo)
	- [Step 1: Docker setup](#step-1-docker-setup)
	- [Step 2a: Building `thebestapp`](#step-2a-building-thebestapp)
	- [Step 2b: Building `thebestts`](#step-2b-building-thebestts)
- [To build the filesysio repo](#to-build-the-filesysio-repo)
	- [Step 2: Building `filesysio.a`](#step-2-building-filesysioa)
- [To build the thebest repo using the filesysio lib](#to-build-the-thebest-repo-using-the-filesysio-lib)
	- [Step 1: Copy the filesysio's files](#step-1-copy-the-filesysios-files)
	- [Step 2: Docker setup](#step-2-docker-setup)
	- [Step 3a: Building `thebestapp2`](#step-3a-building-thebestapp2)
	- [Step 3b: Building `thebestts2`](#step-3b-building-thebestts2)

## Introduction

Design guidelines for starting a new app/lib with BDD/TDD in mind.

## Class diagram

<!--
```plantuml
@startuml
!theme spacelab
hide empty members
set separator ::

namespace TheBest {
	interface "IFactory" as if
	interface "IConfigParser" as icp
	
	class "Facade" as F
	class "Factory" as f
	class "ConfigParser" as cp
	
	if <|-- f
	icp <|-- cp
	F *-> if
	
	if ..> icp : <<create>>
}

namespace TsCommon {
	class "FakeFactory" as ff
	class "FakeConfigParser" as fcp

	TheBest::if <|-- ff
	TheBest::cp <|-- fcp
}

namespace TsConfig {
	class "ParseTest1" as pt1
	'class "ParseTest2" as pt2
	class "test's\nmain.cpp" as m
	hide m circle

	m *..> pt1
	'm *..> pt2

	pt1 ..> TheBest::F : <<instantiate>>
	pt1 ..> TsCommon::ff : <<create>>
}

class "app's\nmain.cpp" as am
hide am circle

am ..> TheBest::F : <<instantiate>>
am ..> TheBest::f : <<create>>
@enduml
```
<!--
-->
![](./bdd_swdev_eng_cd.svg)

## Directory structure

> Note: ts &rarr; test suite

### Under `./thebest`

<!--
```plantuml
@startfiles
/Dockerfile
/src/app/main.cpp
/src/lib/config_parser.cpp
/src/lib/facade.cpp
/src/lib/factory.cpp
/src/lib/include/config_parser.h
/src/lib/include/factory.h
/src/lib/include/thebest/facade.h
/src/lib/include/thebest/iconfig_parser.h
/src/lib/include/thebest/ifactory.h
/src/tst/fake_factory.cpp
/src/tst/include/fake_factory.h
/src/tst/include/ts_common.h
/src/tst/include/ts_config/fake_config_parser.h
/src/tst/include/ts_config/parse.h
/src/tst/main.cpp
/src/tst/ts_common.cpp
/src/tst/ts_config/parse.cpp
/src/tst2/include/ts_config/parse.h
/src/tst2/lib/fake_filesysio.cpp
/src/tst2/lib/include/fake_filesysio.h
/src/tst2/lib/include/filesysio/facade.h
/src/tst2/lib/include/filesysio/idir_service.h
/src/tst2/lib/include/filesysio/ifactory.h
/src/tst2/lib/include/filesysio/ifile_service.h
/src/tst2/lib/include/filesysio/types.h
/src/tst2/ts_config/parse.cpp
@endfiles
```
<!--
-->
![](./thebest_dir_struct.svg)

### Under `./filesysio`

<!--
```plantuml
@startfiles
/Dockerfile
/src/lib/dir_service.cpp
/src/lib/facade.cpp
/src/lib/factory.cpp
/src/lib/file_service.cpp
/src/lib/include/dir_service.h
/src/lib/include/factory.h
/src/lib/include/file_service.h
/src/lib/include/filesysio/facade.h
/src/lib/include/filesysio/idir_service.h
/src/lib/include/filesysio/ifactory.h
/src/lib/include/filesysio/ifile_service.h
/src/lib/include/filesysio/types.h
@endfiles
```
<!--
-->
![](./filesysio_dir_struct.svg)

## To build thebest repo

If you don't have an up-to-date GCC compiler suite already installed, do Step 1.  
Otherwise, cd to `./thebest` and do Step 2 (a, b, or both).

### Step 1: Docker setup

From within `./thebest`, run:

```bash
docker run -it --rm --name thebest -v "$PWD":/home/project -w /home/project abeimler/simple-cppbuilder /bin/bash
```

Then, once in the container (in `/home/project`), do Step 2 (a, b, or both).

### Step 2a: Building `thebestapp`

From within `./src/app`, run:

```bash
mkdir build
c++ -std=c++23 -I ../lib/include/ -o ./build/thebestapp `find . ../lib -name '*.cpp' -print`
```

### Step 2b: Building `thebestts`

From within `./src/tst`, run:

```bash
mkdir build
c++ -std=c++23 -I ./include -I ../lib/include/ -o ./build/thebestts `find . ../lib -name '*.cpp' -print`
```

If you run the test-app:

```bash
./build/thebestts
```

it should output:

```text
INFO: Starting ParseTest1
ERROR: ParseTest1: Could not open file: ts_artifacts/config1.xml
FAILED : ParseTest1

FAILURE: At least one test didn't pass
```

## To build the filesysio repo

Do Step 1 from previous section but replace `--name thebest` by `--name filesysio`.

From within `./filesyio`, run:

```bash
docker run -it --rm --name filesysio -v "$PWD":/home/project -w /home/project abeimler/simple-cppbuilder /bin/bash
```

### Step 2: Building `filesysio.a`

Once inside the container (in `/home/project`), from within `./src/lib`, run:

```bash
mkdir build
find . -maxdepth 1 -name '*.cpp' -exec c++ -c -fPIC -std=c++23 -I ./include/ -o build/{}.o {} \;
ar rfs ./build/libfilesysio.a build/*.o
```

## To build the thebest repo using the filesysio lib

> Note: You need to build the filesysio repo first.

### Step 1: Copy the filesysio's files

Since the thebest and filesysio porjects are not able to see each other when inside a container, from outside of any container, copy the following files:

- public `.h` files
  - from: filesysio's `src/lib/include/filesysio/`
  - to: thebest's `src/tst2/lib/include/filesysio/`
- the `libfilesysio.a` file
  - from: filesysio's `src/lib/build`
  - to: thebest's `./src/tst2/build/`

Notes:
- You may need to create the destination folders.
- You may need to chown `libfilesysio.a` before you can copy it.

### Step 2: Docker setup

From within `./thebest`, run:

```bash
docker run -it --rm --name thebest -v "$PWD":/home/project -w /home/project abeimler/simple-cppbuilder /bin/bash
```

Then, once in the container (in `/home/project`), do Step 3.

### Step 3a: Building `thebestapp2`

```bash
c++ -std=c++23 -DUSE_FILESYSIO_LIB -I ../lib/include/ -I ../tst2/lib/include -o ./build/thebestapp2 `find . ../lib -name '*.cpp' -print` -L ../tst2/build -lfilesysio
```

If you run the app:

```bash
./build/thebestapp2
```

it should output:

```text
The file config.xml does not exist
```

### Step 3b: Building `thebestts2`

From within `./src/tst2`, run:

```bash
c++ -std=c++23 -DUSE_FILESYSIO_LIB -o build/thebestts2 -I ./include -I ../tst2/lib/include -I ../tst/include -I ../lib/include -I ./lib/include ./ts_config/parse.cpp ./lib/fake_filesysio.cpp ../tst/main.cpp ../tst/fake_factory.cpp ../tst/ts_common.cpp ../lib/config_parser.cpp ../lib/factory.cpp ../lib/facade.cpp
```

If you run the test-app:

```bash
./build/thebestts2
```

it should output:

```text
INFO: Starting ParseTest1
ERROR: ParseTest1: Could not open file: ts_artifacts/config1.xml
FAILED : ParseTest1
INFO: Starting ParseTest2
This
is
a
test
SUCCESS: ParseTest2

FAILURE: At least one test didn't pass
```
