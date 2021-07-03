CC=gcc

BIN=convert

ALL:$(BIN)

%:%.c
	$(CC) -o $@ $^ -lm

clean:
	rm -rf $(BIN)
