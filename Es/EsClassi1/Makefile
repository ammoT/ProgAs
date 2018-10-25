CXX = g++
main.exe: main.o dbuffer.o
	$(CXX) main.o dbuffer.o -o main.exe
main.o: main.cpp dbuffer.h
	$(CXX) -c main.cpp -o main.o
dbuffer.o: dbuffer.cpp dbuffer.h
	$(CXX) -c dbuffer.cpp -o dbuffer.o
.PHONY: clean
clean:
	rm -rf *.o *.exe
