OBJS	= hadamard.o testEtal.o etalement.o message.o desetalement.o
SOURCE	= hadamard.c testEtal.c etalement.c message.c desetalement.c
HEADER	= hadamard.h etalement.h message.h desetalement.h
OUT	= testEtal
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

hadamard.o: hadamard.c
	$(CC) $(FLAGS) hadamard.c

etalement.o: etalement.c
	$(CC) $(FLAGS) etalement.c

desetalement.o: desetalement.c
	$(CC) $(FLAGS) desetalement.c

message.o: message.c
	$(CC) $(FLAGS) message.c

testEtal.o: testEtal.c
	$(CC) $(FLAGS) testEtal.c


clean:
	rm -f $(OBJS) $(OUT)