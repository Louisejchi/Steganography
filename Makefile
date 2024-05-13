CC = gcc
LEX = flex
YACC = bison

all: main

main: main.l main.y
	$(YACC) -d main.y
	$(LEX) main.l
	$(CC) -o $@ lex.yy.c -lfl

clean:
	rm main lex.yy.c main.tab.c main.tab.h
