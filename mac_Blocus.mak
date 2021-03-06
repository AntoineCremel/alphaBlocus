#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = -Wall
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/blocus

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/blocus

OBJ_DEBUG = $(OBJDIR_DEBUG)/src/toolbox/tools.o $(OBJDIR_DEBUG)/src/piece/piece.o $(OBJDIR_DEBUG)/src/partie.o $(OBJDIR_DEBUG)/src/menu.o $(OBJDIR_DEBUG)/src/joueur.o $(OBJDIR_DEBUG)/src/gamePlayOptions.o $(OBJDIR_DEBUG)/src/gameLoop.o $(OBJDIR_DEBUG)/src/coup.o $(OBJDIR_DEBUG)/src/controles.o $(OBJDIR_DEBUG)/src/affichageConsole.o $(OBJDIR_DEBUG)/main.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/src/toolbox/tools.o $(OBJDIR_RELEASE)/src/piece/piece.o $(OBJDIR_RELEASE)/src/partie.o $(OBJDIR_RELEASE)/src/menu.o $(OBJDIR_RELEASE)/src/joueur.o $(OBJDIR_RELEASE)/src/gamePlayOptions.o $(OBJDIR_RELEASE)/src/gameLoop.o $(OBJDIR_RELEASE)/src/coup.o $(OBJDIR_RELEASE)/src/controles.o $(OBJDIR_RELEASE)/src/affichageConsole.o $(OBJDIR_RELEASE)/main.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG)/src/toolbox || mkdir -p $(OBJDIR_DEBUG)/src/toolbox
	test -d $(OBJDIR_DEBUG)/src/piece || mkdir -p $(OBJDIR_DEBUG)/src/piece
	test -d $(OBJDIR_DEBUG)/src || mkdir -p $(OBJDIR_DEBUG)/src
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/src/toolbox/tools.o: src/toolbox/tools.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/toolbox/tools.c -o $(OBJDIR_DEBUG)/src/toolbox/tools.o

$(OBJDIR_DEBUG)/src/piece/piece.o: src/piece/piece.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/piece/piece.c -o $(OBJDIR_DEBUG)/src/piece/piece.o

$(OBJDIR_DEBUG)/src/partie.o: src/partie.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/partie.c -o $(OBJDIR_DEBUG)/src/partie.o

$(OBJDIR_DEBUG)/src/menu.o: src/menu.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/menu.c -o $(OBJDIR_DEBUG)/src/menu.o

$(OBJDIR_DEBUG)/src/joueur.o: src/joueur.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/joueur.c -o $(OBJDIR_DEBUG)/src/joueur.o

$(OBJDIR_DEBUG)/src/gamePlayOptions.o: src/gamePlayOptions.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/gamePlayOptions.c -o $(OBJDIR_DEBUG)/src/gamePlayOptions.o

$(OBJDIR_DEBUG)/src/gameLoop.o: src/gameLoop.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/gameLoop.c -o $(OBJDIR_DEBUG)/src/gameLoop.o

$(OBJDIR_DEBUG)/src/coup.o: src/coup.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/coup.c -o $(OBJDIR_DEBUG)/src/coup.o

$(OBJDIR_DEBUG)/src/controles.o: src/controles.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/controles.c -o $(OBJDIR_DEBUG)/src/controles.o

$(OBJDIR_DEBUG)/src/affichageConsole.o: src/affichageConsole.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/affichageConsole.c -o $(OBJDIR_DEBUG)/src/affichageConsole.o

$(OBJDIR_DEBUG)/main.o: main.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.c -o $(OBJDIR_DEBUG)/main.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)/src/toolbox
	rm -rf $(OBJDIR_DEBUG)/src/piece
	rm -rf $(OBJDIR_DEBUG)/src
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE)/src/toolbox || mkdir -p $(OBJDIR_RELEASE)/src/toolbox
	test -d $(OBJDIR_RELEASE)/src/piece || mkdir -p $(OBJDIR_RELEASE)/src/piece
	test -d $(OBJDIR_RELEASE)/src || mkdir -p $(OBJDIR_RELEASE)/src
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/src/toolbox/tools.o: src/toolbox/tools.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/toolbox/tools.c -o $(OBJDIR_RELEASE)/src/toolbox/tools.o

$(OBJDIR_RELEASE)/src/piece/piece.o: src/piece/piece.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/piece/piece.c -o $(OBJDIR_RELEASE)/src/piece/piece.o

$(OBJDIR_RELEASE)/src/partie.o: src/partie.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/partie.c -o $(OBJDIR_RELEASE)/src/partie.o

$(OBJDIR_RELEASE)/src/menu.o: src/menu.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/menu.c -o $(OBJDIR_RELEASE)/src/menu.o

$(OBJDIR_RELEASE)/src/joueur.o: src/joueur.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/joueur.c -o $(OBJDIR_RELEASE)/src/joueur.o

$(OBJDIR_RELEASE)/src/gamePlayOptions.o: src/gamePlayOptions.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/gamePlayOptions.c -o $(OBJDIR_RELEASE)/src/gamePlayOptions.o

$(OBJDIR_RELEASE)/src/gameLoop.o: src/gameLoop.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/gameLoop.c -o $(OBJDIR_RELEASE)/src/gameLoop.o

$(OBJDIR_RELEASE)/src/coup.o: src/coup.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/coup.c -o $(OBJDIR_RELEASE)/src/coup.o

$(OBJDIR_RELEASE)/src/controles.o: src/controles.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/controles.c -o $(OBJDIR_RELEASE)/src/controles.o

$(OBJDIR_RELEASE)/src/affichageConsole.o: src/affichageConsole.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/affichageConsole.c -o $(OBJDIR_RELEASE)/src/affichageConsole.o

$(OBJDIR_RELEASE)/main.o: main.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.c -o $(OBJDIR_RELEASE)/main.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)/src/toolbox
	rm -rf $(OBJDIR_RELEASE)/src/piece
	rm -rf $(OBJDIR_RELEASE)/src
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

