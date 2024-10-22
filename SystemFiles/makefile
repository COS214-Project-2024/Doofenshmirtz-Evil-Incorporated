CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = main 

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
SRC := $(SRC) 

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run:
	./main	

rum:
	valgrind --leak-check=full --track-origins=yes ./TestingMain