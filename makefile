# Compiler
CXX = g++


# Directories
HEADERS_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./build

# Source/Object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Compiler flags
CXXFLAGS = -Wall -Wextra -I. -Llib -std=c++17 -lGL -lglfw -lGLEW 

# Executable
TARGET = GameEngine

# Main rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create obj directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean