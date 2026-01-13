.PHONY: all say_hello generate clean
# Compiler definitions
CC      = gcc
CXX     = g++
CFLAGS  = -Wall -Wextra -O2
CXXFLAGS= -Wall -Wextra -O2

# Target executable
TARGET = calculator

# Source files
C_SRC   = calc.c
CPP_SRC = main.cpp

# Object files
OBJ = calc.o main.o

# Phony targets
.PHONY: all clean rebuild

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile C source
calc.o: calc.c calc.h
	$(CC) $(CFLAGS) -c calc.c

# Compile C++ source
main.o: main.cpp calc.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild everything
rebuild: clean all
