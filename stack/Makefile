CC=gcc

BIN=stack

all:$(BIN)

%:%.c
	$(CC) -o $@ $^ -L/home/pi/C/linkedList -lmylib 
clean:
	rm -rf $(BIN)