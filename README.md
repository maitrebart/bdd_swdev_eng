# BDD/TDD-based Software Development for Engineering Projects

Design guidelines for starting a new app/lib with BDD/TDD in mind.

## Class diagram

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

## To build

### thebestapp

From within thebest/src/app, run:

```bash
c++ -std=c++23 -I ../lib/include/ -o thebestapp main.cpp ../lib/facade.cpp ../lib/factory.cpp ../lib/config_parser.cpp
```

### thebestts

From within thebest/src/tst, run:

```bash
c++ -std=c++23 -I . -I ../lib/include/ -o thebestts main.cpp ts_common.cpp fake_factory.cpp ts_config/parse.cpp ../lib/facade.cpp ../lib/factory.cpp ../lib/config_parser.cpp
```
