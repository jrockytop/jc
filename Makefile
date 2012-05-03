#CC = gcc
CC = cc
LEX = lex
LEXLIB = -lfl
#LEXLIB = -ll
#LEXLIB = -L/sw/pd/gnu/lib -lfl
#LEXLIB = -L/usr/lib/64 -ll
#CFLAGS = -DLONGLONG -g -64
#CFLAGS = -g -Wall -DLONGLONG
CFLAGS = -g -Wall
#CFLAGS = -O
#CFLAGS = -g -DLONGLONG  -xarch=generic64
#LDFLAGS = -64
#LDFLAGS = -xarch=generic64

INSTALL = /usr/local

OBJS = push.o ops.o help.o coms.o lex.yy.o dlist.o init.o add.o sub.o mult.o \
	div.o lshift.o rshift.o or.o and.o mod.o regs.o bit_comp.o xor.o
all: jc

jc: $(OBJS) jc.h
#	etags *.[ch]
	$(CC) -o jc $(OBJS) $(LEXLIB) $(LDFLAGS)

$(OBJS): jc.h

help.c: DOCUMENTATION
	@echo '#include "jc.h"\nvoid help() {\n\tprintf(' > help.c
	@sed 's/\\/\\\\/g' < DOCUMENTATION | sed 's/$$/\\n"/g' | sed 's/^/"/g' | sed 's/%/%%/g' >> help.c
	@echo ');\n}\n' >> help.c

lex.yy.c: jc.l
	$(LEX) jc.l

install: jc
	cp jc $(INSTALL)/bin

clean:
	rm -f $(OBJS) lex.yy.c jc core *.core help.c
