CXX = g++
main.exe: main.o voce.o rubrica.o
	$(CXX) main.o voce.o rubrica.o -o main.exe
main.o: main.cpp voce.h rubrica.h
	$(CXX) -c main.cpp -o main.o
voce.o: voce.cpp voce.h rubrica.h
	$(CXX) -c voce.cpp -o voce.o
rubrica.o: rubrica.cpp voce.h rubrica.h
	$(CXX) -c rubrica.cpp -o rubrica.o
.PHONY : clean
clean:
	rm -rf *.o *.exe
