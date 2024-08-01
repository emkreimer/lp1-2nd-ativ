# Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = main
OBJS = main.o Vetor.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp Vetor.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Vetor.o: Vetor.cpp Vetor.h Node.h
	$(CXX) $(CXXFLAGS) -c Vetor.cpp

clean:
	rm -f $(TARGET) $(OBJS)