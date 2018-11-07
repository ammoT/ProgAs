CXX = g++
main.exe: main.o complesso.o
	$(CXX) main.o complesso.o -o main.exe
main.o: main.cpp complesso.h
	$(CXX) -c main.cpp -o main.o
complesso.o: complesso.cpp complesso.h
	$(CXX) -c complesso.cpp -o complesso.o
.PHONY: clean
clean:
	rm -rf *.o *.exe
