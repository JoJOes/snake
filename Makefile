# Projet Snake : fichier Makefile

# CHAPITRE 1 : BUT FINAL

but : menu

# CHAPITRE 2 : VARIABLES

OFILES = snake.o \
	 menu.o

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g

# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)

snake.o : snake.h

menu.o : snake.h

#CHAPITRE 4 : DEPENDANCES AVEC COMMANDES

menu : $(OFILES)
	$(CC) $(CFLAGS) -o menu $(OFILES) -lgraph

#CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES

clean :
	-rm -f $(OFILES)

#CHAPITRE 6 : BUTS FACTICES

.PHONY : but clean
