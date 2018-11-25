CXX = g++
DEBG = -DNDEBUG
main.exe: main.o
	$(CXX) main.o -o main.exe
main.o: main.cpp fifo.h
	$(CXX) $(DEBG) -c main.cpp -o main.o
.PHONY: clean
clean:
	rm -rf *.o *.exe
