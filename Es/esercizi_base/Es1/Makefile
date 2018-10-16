CXX = g++
main.exe: main.o nsqrt.o
	$(CXX) main.o nsqrt.o -o main.exe
main.o: test_nsqrt.cpp nsqrt.h
	$(CXX) -c test_nsqrt.cpp -o main.o
nsqrt.o: nsqrt.cpp nsqrt.h
	$(CXX) -c nsqrt.cpp -o nsqrt.o
.PHONY:
clean:
	rm *.o *.exe
