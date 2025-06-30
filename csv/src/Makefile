IDIR=../include
LDIR=../lib
CC=gcc
CFLAGS=-I$(IDIR) -L$(LDIR) -std=c99 -g -m32

ODIR=obj

LIBS=-lm -lfnv

_DEPS=abuf.h readcsv.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=csv.o readcsv.o abuf.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

# $< is the first item in the dependencies list
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

csv: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~