#ifndef AFFICHAGECONSOLE_H_INCLUDED
#define AFFICHAGECONSOLE_H_INCLUDED

#include <windows.h>
#include "mainHeader.h"
#include "controles.h"
#include "partie.h"

// 0 Constantes

// 1 Structures

// 2 Prototypes de fonctions
// gotoligcol permet de se placer � un endroit sp�cifique de la console.
void gotoligcol(int lig, int col);

// Fonction pour changer la couleur des lettres de la console.
//
void changeColour(int letters, int backGround);

// Fonction qui r�unit tous les affichages dans la partie
//	 On fait passer les structures par pointeur pour �conomiser le passage par le tube,
//	pas pour pouvoir modifier leurs contenus
void affichageGame(t_Partie * game, t_Controles * touches);

#endif // AFFICHAGECONSOLE_H_INCLUDED
