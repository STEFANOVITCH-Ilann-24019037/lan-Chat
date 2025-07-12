CC = gcc
CFLAGS = -Wall -Wextra -pedantic -pthread
SRC = src/main.c src/discovery.c src/chat.c src/utils.c
OBJ = $(SRC:.c=.o)
EXEC = lan-chat

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

clean:
	rm -f $(EXEC) *.o src/*.o

re: clean all
