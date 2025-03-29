# BDD/TDD-based Software Development for Engineering Projects <!-- omit from toc -->

## Table of contents  <!-- omit from toc -->

<!-- This TOC is generated using the "Markdown All in One" vscode extension -->
- [Introduction](#introduction)
- [Class diagram](#class-diagram)
- [Directory structure](#directory-structure)
	- [Under `./thebest`](#under-thebest)
	- [Under `./filesysio`](#under-filesysio)
- [To build thebest repo](#to-build-thebest-repo)
	- [Step 1: Docker setup for thebest](#step-1-docker-setup-for-thebest)
	- [Step 2a: Building `thebestapp`](#step-2a-building-thebestapp)
	- [Step 2b: Building `thebestts`](#step-2b-building-thebestts)
- [To build the filesysio repo](#to-build-the-filesysio-repo)
	- [Step 1: Docker setup for filesysio](#step-1-docker-setup-for-filesysio)
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
Otherwise, cd to `./thebest` and do Step 2 (a, or b, or both).

### Step 1: Docker setup for thebest

From within `./thebest`, run:

```bash
./runbuildenv.sh
```

This will start a container and you'll end up in `/home/project`). Then do Step 2 (a, or b, or both).

### Step 2a: Building `thebestapp`

From within the container, in `/home/project`, run:

```bash
./buildapp.sh
```

### Step 2b: Building `thebestts`

From within the container, in `/home/project`, run:

```bash
./buildtst.sh
```

If you run the test-app:

```bash
./src/tst/build/thebestts
```

it should output:

```text
INFO: Starting ParseTest1
ERROR: ParseTest1: Could not open file: ts_artifacts/config1.xml
FAILED : ParseTest1

FAILURE: At least one test didn't pass
```

## To build the filesysio repo

If you don't have an up-to-date GCC compiler suite already installed, do Step 1.  
Otherwise, cd to `./filesysio` and do Step 2 (a, or b, or both).

### Step 1: Docker setup for filesysio

From within `./filesysio`, run:

```bash
./runbuildenv.sh
```

This will start a container and you'll end up in `/home/project`). Then do Step 2 (a, or b, or both).

### Step 2: Building `filesysio.a`

From within the container, in `/home/project`, run:

```bash
./buildlib.sh
```

## To build the thebest repo using the filesysio lib

> Note: You need to build the filesysio repo first.

### Step 1: Copy the filesysio's files

From outside any container, in `./thebest`, run:

```bash
./copyfilesysio.sh
```

Notes:
- You may need to *chown* `libfilesysio.a` before you can copy it.

### Step 2: Docker setup

If not already done, from within `./thebest`, run:

```bash
./runbuildenv.sh
```

This will start a container and you'll end up in `/home/project`). Then do Step 3.

### Step 3a: Building `thebestapp2`

From within the container, in `/home/project`, run:

```bash
./buildapp2.sh
```

If you run the app:

```bash
./src/app/build/thebestapp2
```

it should output:

```text
The file config.xml does not exist
```

### Step 3b: Building `thebestts2`

From within the container, in `/home/project`, run:

```bash
./buildtst2.sh
```

If you run the test-app:

```bash
./src/tst2/build/thebestts2
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
