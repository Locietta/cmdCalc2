# simple handwritten makefile for practice

vpath %.h ./include ./include/ADT
vpath %.c ./src ./src/CDT # ./testBin

CC       = gcc -Wall -Werror -O2
SRC      = main.c $(wildcard ./src/*.c ./src/CDT/*.c) 
OBJ      = $(patsubst %.c, %.o, $(SRC))
INCS     = -I"./include" -I"./include/ADT"
BIN      = test.exe
LDFLAGS  = -static-libgcc -g3 # -mwindows
CFLAGS   = $(INCS) -g3

.PHONY: all clean
all: $(BIN) 

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(LDFLAGS)

# (.o: .c)

clean:
	${RM} $(OBJ) $(BIN)