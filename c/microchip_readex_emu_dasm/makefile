CC = gcc
CFLAGS = -g -O3
OBJECTS = readex.o utils.o dasm.o emu.o

readex.exe : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o readex.exe

readex.o : readex.c
	$(CC) -c readex.c
	
utils.o : utils.c
	$(CC) -c utils.c

dasm.o : dasm.c
	$(CC) -c dasm.c

emu.o : emu.c
	$(CC) -c emu.c
	