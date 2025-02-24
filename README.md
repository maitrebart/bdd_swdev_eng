# BDD/TDD-based Software Development for Engineering Projects <!-- omit from toc -->

## Table of contents  <!-- omit from toc -->

<!-- This TOC is generated using the "Markdown All in One" vscode extension -->
- [Introduction](#introduction)
- [Class diagram](#class-diagram)
- [Directory structure](#directory-structure)
	- [Under `./thebest`](#under-thebest)
	- [Under `./fileio`](#under-fileio)
- [To build](#to-build)
	- [Step 1: Docker setup](#step-1-docker-setup)
	- [Step 2a: Building `thebestapp`](#step-2a-building-thebestapp)
	- [Step 2b: Building `thebestts`](#step-2b-building-thebestts)

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
	class "ParseTest2" as pt2
	class "test's\nmain.cpp" as m
	hide m circle

	m *..> pt1
	m *..> pt2

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
@endfiles
```
<!--
-->
![](./thebest_dir_struct.svg)

### Under `./fileio`

(TODO)

## To build

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
c++ -std=c++23 -I ../lib/include/ -o thebestapp main.cpp ../lib/facade.cpp ../lib/factory.cpp ../lib/config_parser.cpp
```

### Step 2b: Building `thebestts`

From within `./src/tst`, run:

```bash
c++ -std=c++23 -I ./include -I ../lib/include/ -o thebestts main.cpp ts_common.cpp fake_factory.cpp ts_config/parse.cpp ../lib/facade.cpp ../lib/factory.cpp ../lib/config_parser.cpp
```
