OBJS	= Lm.o TestLmGold.o Gold.o
SOURCE	= Lm.c TestLmGold.c Gold.c
HEADER	= Lm.h Gold.h
OUT	= TestLmGold
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Lm.o: Lm.c
	$(CC) $(FLAGS) Lm.c 

TestLmGold.o: TestLmGold.c
	$(CC) $(FLAGS) TestLmGold.c 

Gold.o: Gold.c
	$(CC) $(FLAGS) Gold.c 


clean:
	rm -f $(OBJS) $(OUT)
