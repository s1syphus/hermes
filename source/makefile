
OBJS = hermes.o gamedriver.o tictactoe.o alphabeta.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

hermes: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o hermes

hermes.o: hermes.cpp gamedriver.h
	$(CC) $(CFLAGS) hermes.cpp

gamedriver.o: gamedriver.cpp gamedriver.h tictactoe.h alphabeta.h
	$(CC) $(CFLAGS) gamedriver.cpp

tictactoe.o: tictactoe.h tictactoe.cpp boards.h
	$(CC) $(CFLAGS) tictactoe.cpp

alphabeta.o: alphabeta.cpp alphabeta.h boards.h
	$(CC) $(CFLAGS) alphabeta.cpp

clean:
	rm *.o hermes


