IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR) -Wall -g -std=c99

ODIR=obj

LIBS=-lm

_DEPS=intarr.h arrfunc.h sieve.h qsort.h fnvprime.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=fnv.o arrfunc.o sieve.o qsort.o fnvprime.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

fnv.a: $(OBJ)
	ar ruv $@ $^ 
	ranlib $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ ./*.o