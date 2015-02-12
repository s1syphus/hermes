
OBJS = hermes.o gamedriver.o tictactoe.o connect4.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

hermes: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o hermes

hermes.o: hermes.cpp gamedriver.h
	$(CC) $(CFLAGS) hermes.cpp

gamedriver.o: gamedriver.cpp gamedriver.h tictactoe.h connect4.h
	$(CC) $(CFLAGS) gamedriver.cpp

tictactoe.o: tictactoe.h tictactoe.cpp
	$(CC) $(CFLAGS) tictactoe.cpp

connect4.o: connect4.h connect4.cpp
	$(CC) $(CFLAGS) connect4.cpp

clean:
	rm *.o hermes


