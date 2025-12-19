PROJECT = tests
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -Werror -pthread
GTEST_LIBS = -lgtest -lgtest_main -pthread
SRC = gcd.cpp rational.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
BINARIES = $(PROJECT)
ALL_OBJ = $(OBJ)
ALL_GENERATED = $(BINARIES) $(ALL_OBJ)

.PHONY: all clean cleanall distclean

all: $(PROJECT)

$(PROJECT): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(GTEST_LIBS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(ALL_OBJ)

cleanall: clean
	rm -f $(BINARIES)

distclean: cleanall
	rm -f *.gcov *.gcda *.gcno
	rm -f *.dSYM
	rm -f *.out
	@echo "All generated files removed"
