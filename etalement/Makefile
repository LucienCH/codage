
testEtal : testEtal.o hadamard.o
	gcc testEtal.o hadamard.o -o testEtal

testEtal.o : testEtal.c 
	gcc -c testEtal.c -o testEtal.o

hadamard.o : hadamard.c hadamard.h
	gcc -c hadamard.c -o hadamard.o

all : testEtal

clean : 
	rm *.o
