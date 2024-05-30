CXX = g++
CXXFLAGS = -Wall -g -std=c++11  # Add the C++11 standard and other common flags

# Name of the executable
TARGET = Disco_execute

# All object files that will be generated
OBJS = Init.o Disco.o plato.o pista.o sector.o 

# Default rule
all: $(TARGET)

# How to link the program
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# How to compile each source file
Init.o: Init.cpp Init.h Disco.h plato.h pista.h sector.h 
	$(CXX) $(CXXFLAGS) -c Init.cpp -o Init.o

Disco.o: Disco.cpp 	Disco.h Init.h plato.h pista.h sector.h 
	$(CXX) $(CXXFLAGS) -c Disco.cpp -o Disco.o

plato.o: plato.cpp plato.h Disco.h
	$(CXX) $(CXXFLAGS) -c plato.cpp -o plato.o

pista.o: pista.cpp pista.h plato.h Disco.h
	$(CXX) $(CXXFLAGS) -c pista.cpp -o pista.o

sector.o: sector.cpp sector.h pista.h plato.h Disco.h
	$(CXX) $(CXXFLAGS) -c sector.cpp -o sector.o

# Command to clean compiled files (optional)
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
