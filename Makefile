CC = g++
IDIR = ./include
CFLAGS = -Wall -std=c++17 -Ic:/MinGW/include -I$(IDIR)

ODIR = obj
LDIR = ./lib

_OBJ = main.o two_sum.o add_linkedlist.o median_of_two.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_DEPS = two_sum.h add_linkedlist.h median_of_two.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

$(ODIR)/%.o: src/%.cc $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -g -o bin/$@ $^ $(CFLAGS)

.PHONY: clean
clean:
	del /q bin
	del /q obj