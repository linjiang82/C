CC=gcc

CFLAG=-g -Wall

BIN=demo liblinkedList.so

all=$(BIN)

demo: demo.c liblinkedList.so
	$(CC) $(CFLAG) -L. -o $@ $^

liblinkedList.so: linkedList.c 
	$(CC) $(CFLAG) -fPIC -shared -o $@ $^

clean:
	rm -rf $(BIN)
