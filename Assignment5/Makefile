PROJECT = tests
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -Werror -pthread
GTEST_LIBS = -lgtest -lgtest_main -pthread 
SRC = gcd.cpp rational.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean cleanall

all: $(PROJECT)

$(PROJECT): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(GTEST_LIBS) 

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJ)

cleanall:
	rm -f $(OBJ) $(PROJECT)

