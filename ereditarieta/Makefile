CCFLAGS = -Wall -pedantic

main.exe:  main.o  ereditarieta.o
	g++  main.o ereditarieta.o -o main.exe

main.o: main.cpp 
	g++ $(CCFLAGS) -c main.cpp -o main.o

ereditarieta.o: ereditarieta.cpp 
	g++ $(CCFLAGS) -c ereditarieta.cpp -o ereditarieta.o

clean:
	rm *.o *.exe