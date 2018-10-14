CXX = g++
main.exe: main.o date.o
	$(CXX) main.o date.o -o main.exe
main.o: test_date.cpp date.h
	$(CXX) -c test_date.cpp -o main.o
date.o: date.cpp date.h
	$(CXX) -c date.cpp -o date.o
.PHONY:
clean:
	rm *.o *.exe
