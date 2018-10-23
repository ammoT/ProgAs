main.exe: main.o dbuff.o
	g++ main.o dbuff.o -o main.exe
main.o: main.cpp dbuff.h
	g++ -c main.cpp
dbuff.o: dbuff.cpp dbuff.h
	g++ -c dbuff.cpp
.PHONY: clean
clean:
	rm -rf *.exe *.o
