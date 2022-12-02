# ashrimp
Simple assembler for assembly like custom language using own implementation of malloc

**NOTE** : Opcodes are currently printed on standrad output (virtual machine for binaries execution isn't implemented yet)

## Requirements
- GCC/Clang
- CMake (version 3.0.0 minimum)
- Ninja
- Unix makefile (optionnal)
- CTest (optionnal)
- GCovr (optionnal)

## Build
To build the project you have multiples posibilities :
- Via makefile rules
- Manually
- Using an IDE that support CMake building

### Makefile
```
make                build the project
make debug          build the project with CTest files
make test           execute CTest and generate GCovr html coverage files
make cov            open GCovr index.html file in default browser
make re             clean rebuild the project
make clean/fclean   delete build folder
```
### Manually
```
mkdir build                                                         create build folder
cmake -B build/ -DCMAKE_GENERATOR=Ninja && cmake --build build/     create the ninja files in build folder and build
```

## Tests
To run unit test you have multiples posibilities :
- Via makefile rules
- Manually
- Using an IDE that support CTest

### Makefile
```
make test
```
### Manually
```
ninja -C build/ test
```

## Usage
```
ashrimp [-v] [-o <output file>] <ashrmp file>
```
You can also print the complete help page by using :
```
ashrimp -h
```
