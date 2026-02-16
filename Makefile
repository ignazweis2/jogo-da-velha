# executable
TARGET = tic-tac-toe

# compiler
CC = gcc

# compilation flags
CFLAGS = -Wall

# .c files
SRC = tic-tac-toe.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# clean generated files
clean:
	rm -f $(TARGET)
