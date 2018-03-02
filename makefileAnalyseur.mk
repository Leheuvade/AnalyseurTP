ECHO=@echo 
CC=g++
EDL=g++
LDFLAGS=
CFLAGS=-Wall
EXEC=exe


all: $(EXEC)

$(EXEC) : main.o automate.o etat.o etat0.o etat1.o etat2.o etat3.o etat4.o etat5.o etat6.o etat7.o etat8.o etat9.o lexer.o symbole.o 
	echo "Edition des liens"
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean : 
	rm -rf *.o
	rm -rf $(EXEC)

PHONY : clean