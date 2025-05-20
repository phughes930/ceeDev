IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR) -std=c99 -g

ODIR=obj

_DEPS=abuf.h readcsv.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=csv.o readcsv.o abuf.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

# $< is the first item in the dependencies list
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

csv: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~