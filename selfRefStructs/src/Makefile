IDIR = ../include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = obj

_DEPS = GetWord.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = SelfRef.o GetWord.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

SelfRef: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~