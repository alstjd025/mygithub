# Set compiler to use
CC=g++ 
CFLAGS=-g -I. -fpermissive
LDFLAGS=
OBJS=Main.o Matrix.o Tetris.o CTetris.o ttymodes.o
DEBUG=1

all:: Main.exe

Main.exe: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS_TET)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#options for os x
osx:: Main

Main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS_TET)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)



clean: 
	rm -f Main *.exe *.o *~ *.stackdump
