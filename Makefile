COURSE = cs240
SEMESTER = spring2022

CP_NUMBER = 5

LASTNAME = Seg-Fault
GITUSERID = -
USER = -

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++

OBJ = obj
BIN = bin
EXE = play

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/Player.o $(OBJ)/main.o 
	$(CC) $(FLAGS)  $(OBJ)/Player.o  $(OBJ)/main.o -o $@


$(OBJ)/Player.o: Player.h
	$(CC) $(FLAGS) -c Player.cpp -o $@

$(OBJ)/main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp -o $@

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz

tar: clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)
