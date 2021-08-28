CC=gcc

BIN=binary

ALL:$(BIN)

%:%.c
	$(CC) -o $@ $^

clean:
	rm -rf $(BIN)