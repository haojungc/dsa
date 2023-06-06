CXX := g++
CXXFLAGS := -std=c++11 -Wall
TARGETS := unionset

.PHONY: all clang-format clean
all: $(TARGETS)

unionset: unionset.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clang-format:
	clang-format -style=file -i *.cpp

clean:
	rm -f $(TARGETS)
