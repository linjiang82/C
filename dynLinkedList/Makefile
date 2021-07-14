CC=gcc


BIN=demo dynLinkedList.o

all:$(BIN)


%.o:%.c
	$(CC) -c $^
%:%.c
	$(CC) -o $@ $^ dynLinkedList.c


clean:
	rm -rf $(BIN)
