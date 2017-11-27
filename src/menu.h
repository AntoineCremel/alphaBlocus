#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <conio.h>

#include "affichageConsole.h"
#include "partie.h"
#include "gameLoop.h"
#include "mainHeader.h"
#include "controles.h"

#define MENU_P     0
#define PLAY       1
#define NOMBRE1    2
#define NOMBRE2    3
#define NOMBRE3    4
#define CHARGER    5
#define OPTIONS    6
#define TOUCHE     7
#define QUITTER    8

// Fonction affichant le menu principal
int menu_principal(char tab[10][20], int *lig, char *quitter);

// Fonction affichant le menu pour lancer une nouvelle partie
int menu_nouvelle_partie(char tab[10][20], int *lig, char *quitter);

// Fonctions pour determiner le nombre de joueur ainsi que le type de l'adversaire
int menu_nombre_IA(char tab[10][20], int *lig, char *quitter);
int menu_nombre_joueur(char tab[10][20], int *lig, char *quitter);
int menu_nombre_joueur_IA(char tab[10][20], int *lig, char *quitter);

// Fonction affichant le menu pour charger une partie
int menu_charger_partie(char tab[10][20], int *lig, char *quitter);

// Fonction affichant le menu d'options
int menu_options(char tab[10][20], int *lig, char *quitter);

// Fonction affichant le menu pour reconfigurer les touches
int menu_reconfigurer_touche(char tab[10][20], int *lig, char *quitter);

// Fonction permettant le passage de menu en menu
void superLoop();

#endif // MENU_H_INCLUDED
