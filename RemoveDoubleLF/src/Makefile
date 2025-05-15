IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR) -std=c99 -g

ODIR=obj

_DEPS=abuf.h getPath.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=RemoveDoubleLf.o abuf.o getPath.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

RemoveDoubleLF: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~