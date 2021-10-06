CC = gcc

BIN = server client

all:$(BIN)

%: %.c
	$(CC) -g -o $@ $^

clean:
	rm -rf $(BIN)