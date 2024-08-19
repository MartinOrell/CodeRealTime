## helloUserLibrary
This is a project to showcase using a library. In this case the library is called sumLib and contains a sum function.

### Building sumLib
Before usage, the library needs to be built. Use a terminal inside sumLib folder to first generate the makefiles and then build the library
```
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build/
```

### Linking to the library
The library is linked in the .tcjs file:
```
tc.userLibraries = [
    "../../sumLib/build/libsumLib.a"
];
tc.inclusionPaths = [
    "../../sumLib/include"
]
```
### usage
Lastly the library can be used in a capsule:
```
[[rt::header_preface]]
`
    #include "sum.h"
`
```