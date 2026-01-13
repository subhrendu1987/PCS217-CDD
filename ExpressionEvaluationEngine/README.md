# Description
The `ExpressionEvaluationEngine` is a multi-language project that demonstrates the integration of C, C++, and Java using JNI (Java Native Interface). The engine allows evaluating mathematical expressions by combining the performance of C/C++ with the portability and interface of Java.

## Key things to observe
1. Building and linking C and C++ static libraries
1. Generating JNI headers from Java classes
1. Creating a shared library (.so) to be loaded from Java
1. Handling cross-language function calls and data marshalling
1. Managing build dependencies using CMake

## Project Structure
```
ExpressionEngine/
│
├── c/
│   ├── math_kernel.c
│   └── math_kernel.h
│
├── cpp/
│   ├── expression_engine.cpp
│   └── expression_engine.h
│
├── java/
│   └── ExpressionApp.java
│
├── jni/
│   └── ExpressionJNI.cpp
│
├── Makefile
```

## Build and Run
```
mkdir build
cd build
cmake ..
make
make run
```

## Clean up
```
cd ..
rm -rf build
```