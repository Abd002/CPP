# Compiler settings
CXX = g++
CXXFLAGS = -Wall -g

# Find all .cpp files in the current directory
SRCS = $(wildcard *.cpp)

# Generate the corresponding .o files for each .cpp file
OBJS = $(SRCS:.cpp=.o)

# The output executable name (you can change this as needed)
TARGET = program

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony target to avoid conflicts with filenames
.PHONY: clean

