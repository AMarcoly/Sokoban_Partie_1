.PHONY: all dist clean distclean doc

NAME ?= $(shell basename $(shell pwd))
LDLIBS ?= -lm
CFLAGS ?= -O3 -march=native -g3 -ggdb
override CFLAGS += -std=gnu11 -pedantic -pedantic-errors \
		-Wall -Wextra \
		-Wdouble-promotion -Wformat=2 -Winit-self -Wswitch-default \
		-Wswitch-enum -Wunused-parameter -Wuninitialized -Wfloat-equal \
#		-Wshadow -Wundef -Wbad-function-cast \
		-Wcast-qual -Wcast-align -Wwrite-strings -Wconversion \
		-Wjump-misses-init -Wlogical-op -Wstrict-prototypes \
		-Wold-style-definition -Wmissing-prototypes -Wmissing-declarations \
		-Wredundant-decls -Wnested-externs
#
EXEC = main
all: $(EXEC)
main: main.o grid.o player.o
%: %.o
	$(CC) $(LDFLAGS) $^ -o $@ $(LOADLIBES) $(LDLIBS)

# Documentation
doc:
	doxygen Doxyfile

# Archive
archive:
	tar -czf ANTOINE_Marcoly_GAME_Adrien.tar.gz *.c *.h makefile *.txt *.md

# Nettoyage
clean:
	$(RM) -r $(EXEC) *.o doc html 
archiveclean: clean
	$(RM) *.tar.gz

# Dépendances avec les en-têtes
player.o : player.c player.h grid.h
grid.o: grid.c grid.h 
main.o: main.c grid.h player.h
