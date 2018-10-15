CXX = g++
main.exe: main.o
	$(CXX) main.o -o main.exe
main.o: main.cpp
	$(CXX) -c  main.cpp -o main.o
.PHONY: clean
clean:
	rm -rf *.o *.exe
