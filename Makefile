# Makefile to compile source files in the src directory and send object files to obj directory

# Source directory
SRC_DIR := src

# Object directory
OBJ_DIR := obj

# List all CPP files in the src directory
CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)

# Generate the object file names with obj directory path
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CPP_FILES))

# The final executable name
TARGET := chess

# Compiler settings
CXX := g++
#-Wall -Wextra -Iinclude -O3 -Wpedantic -s -ffunction-sections -fdata-sections -Wl,--gc-section -fno-exceptions -flto 
CXXFLAGS := -Wall -Wextra -Iinclude -Wpedantic -lstdc++

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@
	strip $@

# Rule to compile CPP files into object files in the obj directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleanup rule
clean:
	rm -f $(OBJ_FILES) $(TARGET)