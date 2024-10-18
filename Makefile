CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra -pedantic 

TARGET = main

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run with valgrind
run: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) 2> valgrind_log.txt

# Run with gdb
debug: $(TARGET)
	gdb -ex run --args ./$(TARGET) 2>&1 | tee gdb_log.txt

clean:
	rm -f $(OBJS) $(TARGET) valgrind_log.txt gdb_log.txt

.PHONY: all run debug clean