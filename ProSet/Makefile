GXX = g++
main.exe: main.o
	$(GXX) main.o -o main.exe
main.o: main.cpp set.h
	$(GXX) -c main.cpp -o main.o
.PHONY: clean
clean:
	rm -rf *.exe *.o
