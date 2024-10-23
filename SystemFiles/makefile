CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Targets
DEMO_TARGET = DemoMain
TEST_TARGET = UnitTesting

# Source files
COMMON_SRC = $(filter-out DemoMain.cpp UnitTesting.cpp, $(wildcard *.cpp))
DEMO_SRC = DemoMain.cpp $(COMMON_SRC)
TEST_SRC = UnitTesting.cpp $(COMMON_SRC)

# Object files
DEMO_OBJ = $(DEMO_SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Default target: compile both
all: $(DEMO_TARGET) $(TEST_TARGET)

# Compile demo executable
$(DEMO_TARGET): $(DEMO_OBJ)
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(DEMO_OBJ)

# Compile test executable
$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ)

# Compile .o files from .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(DEMO_OBJ) $(TEST_OBJ) $(DEMO_TARGET) $(TEST_TARGET)

# Run demo
run_demo:
	./$(DEMO_TARGET)

# Run unit tests
run_tests:
	./$(TEST_TARGET)
