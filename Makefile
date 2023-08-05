# Makefile

all: main

main: Main.o libCppInterface.a
	gcc -o main Main.o -L. -lCppInterface -lstdc++

Main.o: Main.c CppInterface.h
	gcc -c Main.c

libCppInterface.a: CppInterface.o
	ar rvs libCppInterface.a CppInterface.o

CppInterface.o: CppInterface.cpp CppInterface.h
	g++ -c CppInterface.cpp

clean:
	rm -f main *.o *.a

