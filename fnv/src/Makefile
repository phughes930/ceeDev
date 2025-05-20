IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR) -g -std=c99

ODIR=obj

LIBS=-lm

_DEPS=intarr.h arrfunc.h sieve.h qsort.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o arrfunc.o sieve.o qsort.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

fnvprime: $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~