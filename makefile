AR = ar
CFLAGS = -Wall -g
CC = gcc

all: isorts isort txtfinds txtfind

#dynamic
isort: isort.o libmysort.so
	$(CC) $(CFLAGS) -o isort isort.o ./libmysort.so

#static
isorts: isort.o libmysort.a
	$(CC) $(CFLAGS) -o isorts isort.o libmysort.a

#dynamic
txtfind: txtfind.o libmytxtfind.so
	$(CC) $(CFLAGS) -o txtfind txtfind.o ./libmytxtfind.so

#static
txtfinds: txtfind.o libmytxtfind.a
	$(CC) $(CFLAGS) -o txtfinds txtfind.o libmytxtfind.a

#creating dynamic lib .so
libmysort.so: isort.o
	$(CC) -shared -o libmysort.so isort.o

#creating static lib .a
libmysort.a: isort.o
	$(AR) -rcs libmysort.a isort.o

#creating dynamic lib .so
libmytxtfind.so: txtfind.o
	$(CC) -shared -o libmytxtfind.so txtfind.o

#creating static lib .a
libmytxtfind.a: txtfind.o
	$(AR) -rcs libmytxtfind.a txtfind.o

txtfind.o: txtfind.c
	$(CC) $(CFLAGS) -c txtfind.c

isort.o: isort.c
	$(CC) $(CFLAGS) -c isort.c

.PHONY: clean

clean:
	rm -rf *o *so *a *out isorts isort txtfind txtfinds

