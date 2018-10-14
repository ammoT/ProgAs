CXX = g++
INCLUDES = includes/operazioni.h
SOURCE = source/operazioni.cpp
main.exe: main.o operazioni.o
	$(CXX) -o main.exe main.o operazioni.o
main.o: main.cpp
	$(CXX) -c main.cpp -o main.o
operazioni.o: $(SOURCE) $(INCLUDES)
	$(CXX) -c $(SOURCE) -o operazioni.o
.PHONY: clean
clean:
	rm -rf *.exe *.o
