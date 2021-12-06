OBJS	= hadamard.o testEtal.o
SOURCE	= hadamard.c testEtal.c
HEADER	= hadamard.h
OUT	= testEtal
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

hadamard.o: hadamard.c
	$(CC) $(FLAGS) hadamard.c 

testEtal.o: testEtal.c
	$(CC) $(FLAGS) testEtal.c 


clean:
	rm -f $(OBJS) $(OUT)