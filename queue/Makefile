CC=gcc
CFLAG=-g -Wall

BIN=demo libqueue.so libBTqueue.so


all:$(BIN)

libBTqueue.so: BTqueue.c
	$(CC) --shared -fpic -o $@ $^

%:%.c libqueue.so 
	$(CC) $(CFLAG) -o $@ $^ -llinkedList


clean:
	rm -rf $(BIN)
