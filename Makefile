CC=gcc
CFLAGS=-Wall
OBJS=main.o bilhete.o sala.o util.o

all: cinema

cinema: $(OBJS)
	$(CC) -o cinema $(OBJS)

main.o: main.c bilhete.h sala.h util.h
	$(CC) $(CFLAGS) -c main.c

bilhete.o: bilhete.c bilhete.h sala.h util.h
	$(CC) $(CFLAGS) -c bilhete.c

sala.o: sala.c sala.h
	$(CC) $(CFLAGS) -c sala.c

util.o: util.c util.h bilhete.h
	$(CC) $(CFLAGS) -c util.c

clean:
	rm -f *.o cinema
