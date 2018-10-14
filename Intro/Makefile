CXX = g++	#variabile
main.exe: utils.o main.o
	$(CXX) -o main.exe utils.o main.o
utils.o: utils.cpp utils.h
	$(CXX) -o utils.o -c utils.cpp
main.o: main.cpp
	$(CXX) -o main.o -c main.cpp

.PHONY: clean
clean:
	rm -rf *.o *.exe
