CC = gcc
LEX = flex
YACC = bison

all: main

main: lex.yy.c main.tab.c
	$(CC) -o $@ $^ -lfl

lex.yy.c: main.l main.tab.h main.tab.c
	$(LEX) main.l

main.tab.h main.tab.c: main.y
	$(YACC) -d main.y

clean:
	rm main lex.yy.c main.tab.c main.tab.h
