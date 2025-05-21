CC=gcc
IDIR=../include
CFLAGS=-I$(IDIR) -g -std=c99

ODIR=obj

_DEPS=llist.h llistfunc.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o llistfunc.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

llist: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~