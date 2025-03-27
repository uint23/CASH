# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -MMD -MP

# Linker flags (for libraries)
LDFLAGS := -lreadline

# Source files and object files
SRC_DIR := src
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

# Output binary
TARGET := shell

# Default target
all: $(TARGET)

# Link final binary with readline
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile each source file to object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files
-include $(DEPS)

run:
	./$(TARGET)

# Clean build files
clean:
	rm -f $(SRC_DIR)/*.o $(SRC_DIR)/*.d $(TARGET)

.PHONY: all clean
