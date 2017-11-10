#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <conio.h>

#include "affichageConsole.h"
#include "partie.h"
#include "gameLoop.h"
#include "mainHeader.h"

// Fonction permettant d'effacer un menu pour en afficher un autre
void effacement(char tab[10][20]);

// Fonction qui permet de choisir quel menu lancer
void curseur();

// Fonction affichant le menu pour charger une partie
void menu_charger_partie(char tab[10][20]);

// Fonction affichant le menu d'options
void menu_options(char tab[10][20]);

// Fonction affichant le menu principal
void menu_principal(char tab[10][20]);

// Fonction permettant de choisir le menu a lancer
void choix_menu();
#endif // MENU_H_INCLUDED
