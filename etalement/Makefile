
etalement : etalement.o hadamard.o
	gcc etalement.o hadamard.o -o etalement

etalement.o : etalement.c
	gcc -c etalement.c -o etalement.o

hadamard.o : hadamard.c hadamard.h
	gcc -c hadamard.c -o hadamard.o

all : etalement

clean : 
	rm *.o
