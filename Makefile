# executável
TARGET = jogo-da-velha

# compilador
CC = gcc

# flags de compilação
CFLAGS = -Wall

# arquivos .c
SRC = jogo-da-velha.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 

# limpar arquivos gerados
clean:
	rm -f $(TARGET)
