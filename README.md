# Boost and conan

|CI|Status|
|---|---|
|Travis|[![Build Status](https://travis-ci.org/spjuanjoc/boost_ptree_conan_cpp.svg?branch=master)](https://travis-ci.org/spjuanjoc/boost_ptree_conan_cpp) |

---
Use `Boost 1.69` in a CMake project with Conan as package manager.

## PropertyTree

Use Conan to include `Boost.PropertyTree` library into a project, with
Boost version 1.69.  
Overload the operator `ptree()` to serialize data to a JSON.  
property_tree is a boost header-only library, does not require linkage.

## Install, compile, and run

Install the third-party libraries using conan, then configure, build, and run:  
```shell
mkdir "build"
cd build
conan install ../conanfile.txt
cmake -G"Unix Makefiles" -DCMAKE_MODULE_PATH=$PWD ../CMakeLists.txt
cmake --build . 
./boost_conan
```

# Test

Run all the tests:  
```shell
mkdir "build"
cd build
conan install ../conanfile.txt
cmake -G"Unix Makefiles" -DCMAKE_MODULE_PATH=$PWD -DENABLE_TESTS=True ../CMakeLists.txt
cmake --build . 
ctest .
```
