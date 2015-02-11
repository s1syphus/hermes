
OBJS = hermes.o gamedriver.o tictactoe.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

hermes: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o hermes

hermes.o: hermes.cpp gamedriver.h
	$(CC) $(CFLAGS) hermes.cpp

gamedriver.o: gamedriver.cpp gamedriver.h tictactoe.h
	$(CC) $(CFLAGS) gamedriver.cpp

tictactoe.o: tictactoe.h tictactoe.cpp
	$(CC) $(CFLAGS) tictactoe.cpp


clean:
	rm *.o hermes


