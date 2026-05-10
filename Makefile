CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2
SRC      = task46.cpp puzzle.cpp patterns.cpp puzzles.cpp
TARGET   = slitherlink

ifeq ($(OS), Windows_NT)
    TARGET = slitherlink.exe
    RM     = del /Q
else
    TARGET = slitherlink
    RM     = rm -f
endif


.PHONY: run clean

all:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: all
	./$(TARGET)

clean:
	$(RM) $(TARGET)
