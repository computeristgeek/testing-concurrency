CC=gcc
CFLAGS=-lfl

all:pre

pre:lex.yy.c
	$(CC) $^ $(CFLAGS) -o $@

lex.yy.c:pre.lex
	flex $^

clean:
	rm -rf lex.yy.c
	rm -rf pre
