CC=/usr/bin/gcc
CFLAGS= -g -Wall -funwind-tables

all: dleaker dleaker2 dleaker3

%.o: %.c $(DEPS)
	$(CC) -c -rdynamic -o $@ $< $(CFLAGS)

dleaker: dleaker.o backtrace.o
	$(CC) -dl -o dleaker dleaker.o backtrace.o

dleaker2: dleaker2.o 
	$(CC) -g -dl -o dleaker2 dleaker2.o

dleaker3: dleaker3.o 
	$(CC) -g -dl -pthread -o dleaker3 dleaker3.o

clean:
	rm -f *.o dleaker dleaker2 dleaker3
