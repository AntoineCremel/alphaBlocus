#ifndef AFFICHAGECONSOLE_H_INCLUDED
#define AFFICHAGECONSOLE_H_INCLUDED

#include <windows.h>
#include "mainHeader.h"
#include "controles.h"
#include "partie.h"

// 0 Constantes
#define SKIN_PIECE ' '

// Constantes qui définissent, dans la zone de scroll des pièces, le nombre de pièces à afficher au-dessus de la pièce active
//	et le nombre de pièces à afficher au-dessous
#define PIECES_A_AFFICHER_AU_DESSUS	2
#define PIECES_A_AFFICHER_AU_DESSOUS 2

// Constante qui définit le nombre d'espaces à laisser entre chaque pièce
#define LINES_BETWEEN_PIECES_IN_SCROLL	1

// 1 Structures

// 2 Prototypes de fonctions
// gotoligcol permet de se placer à un endroit spécifique de la console.
void gotoligcol(int lig, int col);

// Fonction pour changer la couleur des lettres de la console.
void changeColour(int letters, int backGround);

// Fonction qui réunit tous les affichages dans la partie
//	 On fait passer les structures par pointeur pour économiser le passage par le tube,
//	pas pour pouvoir modifier leurs contenus
void affichageGame(t_Partie * game, t_Controles * touches);

// Fonction pour afficher un rappel des contrôles sur la console
void affichageConsoleControles(t_Controles * self, int lig, int col);

// Cette fonction permet d'afficher la grille de jeu. Elle prend en paramètre la structure de la partie,
// ainsi que les coordonnées où la grille de jeu doit être affichée (lig et col désignent le point en haut à gauche)
void affichageConsoleGrilleDeJeu(t_Partie * self, int lig, int col);

// Cette fonction sert à afficher le joueur actif (les pièces dont il dispose)
// C'est cette fonction qui appellera pieceScrollConsole
void affichageJoueurConsole(t_Joueur * self, int lig, int col);
// Fonction qui sert à afficher une pièce dans la zone qui sert à choisir quelle pièce on va jouer
void affichagePieceScrollConsole(t_Piece * self, int * lig, int * col, int colour);

#endif // AFFICHAGECONSOLE_H_INCLUDED
