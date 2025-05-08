IDIR = ../include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR=obj

_DEPS= Alloc.h NumCmp.h ReadWrite.h StrCmp.h Swap.h GetLine.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Alloc.o NumCmp.o ReadWrite.o StrCmp.o Swap.o GetLine.o StringSort.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

StringSort: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	