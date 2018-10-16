CXX = g++
main.exe: main.o utils.o
	$(CXX) main.cpp utils.cpp -o main.exe
main.o: main.cpp utils.h
	$(CXX) -c main.cpp -o main.o
utils.o: utils.h utils.cpp
	$(CXX) -c utils.cpp -o utils.o
.PHONY: clean
clean:
	rm -rf *.exe *.o
