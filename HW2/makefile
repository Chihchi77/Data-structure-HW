CXX := g++

CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

SRC := 113511013_hw2.cpp
TARGET := hw2

all: $(TARGET)

$(TARGET) : $(SRC) 113511013_hw2.h
    $(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
    ./$(TARGET)

clean:
  rm -f $(TARGET)