#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <conio.h>

#include "affichageConsole.h"
#include "partie.h"
#include "gameLoop.h"
#include "mainHeader.h"

#define MENU_P  0
#define PLAY    1
#define CHARGER 2
#define OPTIONS 3
#define QUITTER 4

// Fonction affichant le menu principal
int menu_principal(char tab[10][20], int *lig, char *quitter);

// Fonction affichant le menu pour lancer une nouvelle partie
int menu_nouvelle_partie(char tab[10][20], int *lig, char *quitter);

// Fonction affichant le menu pour charger une partie
int menu_charger_partie(char tab[10][20], int *lig, char *quitter);

// Fonction affichant le menu d'options
int menu_options(char tab[10][20], int *lig, char *quitter);

void superLoop();

#endif // MENU_H_INCLUDED
