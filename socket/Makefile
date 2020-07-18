CC = gcc

BIN = server client

all:$(BIN)

%: %.c
	$(CC) -o $@ $^

clean:
	rm -rf $(BIN)