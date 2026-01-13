# Project Structure

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