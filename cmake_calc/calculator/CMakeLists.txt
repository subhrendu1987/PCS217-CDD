# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define project name and language
project(Calculator C)

# Specify C language standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Create executable target with source files
add_executable(calculator
    src/main.c
    src/add.c
    src/sub.c
    src/div.c
    src/mul.c
)

