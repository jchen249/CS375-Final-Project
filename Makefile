GCC = g++
FLAGS = -c -g -ggdb -Wall -std=c++0x
EXECUTABLE = test
SOURCES = Driver.cpp Hash.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: Driver

Driver: $(OBJECTS)
	$(GCC) $(OBJECTS) -o $(EXECUTABLE)

target:
	number=0; while [[ $$number -le 49 ]] ; do \
		./test; \
		sleep 2; \
		((number = number +1)); \
		done
Driver.o: Driver.cpp
	$(GCC) $(FLAGS) Driver.cpp

Hash.o: Hash.cpp Hash.h
	$(GCC) $(FLAGS) Hash.cpp

clean:
	rm *.o $(EXECUTABLE)
