# BDD/TDD-based Software Development for Engineering Projects

Design guidelines for starting a new app/lib with BDD/TDD in mind.

## Class diagram

<!--
```plantuml
@startuml
'!theme blueprint
'+!theme sketchy
!theme spacelab
'!theme toy

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
TheBest::icp <|-- fcp
}

namespace TsConfig {

class "ParseTest1" as pt1
class "ParseTest2" as pt2
class "test's\nmain.cpp" as m
hide m circle

m *..> pt1
m *..> pt2

pt1 ..> TheBest::F
pt1 ..> TsCommon::ff : <<create>>

}

class "app's\nmain.cpp" as am
hide am circle

am ..> TheBest::F
am ..> TheBest::f : <<create>>


@enduml
```
-->
![](./bdd_swdev_eng_cd.svg)

## To build

If you don't have an up-to-date GCC compiler suite already installed, do Step 1.  
Otherwise, cd to ./thebest and do Step 2 (a, b, or both).

### Step 1: Docker setup

From within ./thebest, run:

```bash
docker run -it --rm --name thebest -v "$PWD":/home/project -w /home/project abeimler/simple-cppbuilder /bin/bash
```

Then, once in the container (in /home/project), do Step 2 (a, b, or both).

### Step 2a: Building thebestapp

From within ./src/app, run:

```bash
c++ -std=c++23 -I ../lib/include/ -o thebestapp main.cpp ../lib/facade.cpp ../lib/factory.cpp ../lib/config_parser.cpp
```

### Step 2b: Building thebestts

From within ./src/tst, run:

```bash
c++ -std=c++23 -I . -I ../lib/include/ -o thebestts main.cpp ts_common.cpp fake_factory.cpp ts_config/parse.cpp ../lib/facade.cpp ../lib/factory.cpp ../lib/config_parser.cpp
```
