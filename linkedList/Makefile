CC=gcc

BIN=libmylib.so test runtime_test

all:$(BIN) 

%.o:%.c mylib.h
	$(CC) -c $^

%.so:%.c mylib.h
	$(CC) -fPIC -shared -o $@ $^ -lc

test:test.c libmylib.o
	$(CC) -o $@ $^

runtime_test: test.c
	$(CC) -o $@ $^ -L. -lmylib

clean:
	rm -rf $(BIN)