CXX = g++
main.exe: main.o roman.o
	$(CXX) main.o roman.o -o main.exe
main.o: test_roman.cpp roman.h
	$(CXX) -c test_roman.cpp -o main.o
roman.o: roman.cpp roman.h
	$(CXX) -c roman.cpp -o roman.o
.PHONY:
clean:
	rm *.o *.exe
