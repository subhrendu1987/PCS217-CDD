# CMake based compilation of Calculator program

## 📁 Project Structure
calculator/
├── src/
│ ├── main.c # Entry point of the application
│ ├── add.c # Addition logic
│ ├── sub.c # Subtraction logic
│ ├── mul.c # Multiplication logic
│ ├── div.c # Division logic
│ └── calc.h # Function declarations
├── CMakeLists.txt # CMake build configuration
└── README.md # Project documentation

## Compilation Procedure
```
mkdir build
cd build
cmake ..
make
./calculator
```
