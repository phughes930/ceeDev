IDIR = ../include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = obj

_DEPS = GetCh.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = CountKWords.o GetCh.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

CountKWords: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~