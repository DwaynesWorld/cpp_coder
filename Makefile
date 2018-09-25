CC = g++
IDIR =./include
CFLAGS = -Wall -std=c++17 -Ic:/MinGW/include -I$(IDIR)

ODIR = obj
LDIR =./lib

_OBJ = main.o twoSum.o addLinkedList.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_DEPS = twoSum.hpp addLinkedList.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

$(ODIR)/%.o: src/%.cpp $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -g -o bin/$@ $^ $(CFLAGS)

.PHONY : clean
clean:
	del /q bin
	del /q obj