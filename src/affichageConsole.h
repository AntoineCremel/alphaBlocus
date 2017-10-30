#ifndef AFFICHAGECONSOLE_H_INCLUDED
#define AFFICHAGECONSOLE_H_INCLUDED

#include <windows.h>
#include "mainHeader.h"
#include "controles.h"
#include "partie.h"

// 0 Constantes
#define SKIN_PIECE ' '

// Constantes qui d�finissent, dans la zone de scroll des pi�ces, le nombre de pi�ces � afficher au-dessus de la pi�ce active
//	et le nombre de pi�ces � afficher au-dessous
#define PIECES_A_AFFICHER_AU_DESSUS	2
#define PIECES_A_AFFICHER_AU_DESSOUS 2

// Constante qui d�finit le nombre d'espaces � laisser entre chaque pi�ce
#define LINES_BETWEEN_PIECES_IN_SCROLL	1

// 1 Structures

// 2 Prototypes de fonctions
// gotoligcol permet de se placer � un endroit sp�cifique de la console.
void gotoligcol(int lig, int col);

// Fonction pour changer la couleur des lettres de la console.
void changeColour(int letters, int backGround);

// Fonction qui r�unit tous les affichages dans la partie
//	 On fait passer les structures par pointeur pour �conomiser le passage par le tube,
//	pas pour pouvoir modifier leurs contenus
void affichageGame(t_Partie * game, t_Controles * touches);

// Fonction pour afficher un rappel des contr�les sur la console
void affichageConsoleControles(t_Controles * self, int lig, int col);

// Cette fonction permet d'afficher la grille de jeu. Elle prend en param�tre la structure de la partie,
// ainsi que les coordonn�es o� la grille de jeu doit �tre affich�e (lig et col d�signent le point en haut � gauche)
void affichageConsoleGrilleDeJeu(t_Partie * self, int lig, int col);

// Cette fonction sert � afficher le joueur actif (les pi�ces dont il dispose)
// C'est cette fonction qui appellera pieceScrollConsole
void affichageJoueurConsole(t_Joueur * self, int lig, int col);
// Fonction qui sert � afficher une pi�ce dans la zone qui sert � choisir quelle pi�ce on va jouer
void affichagePieceScrollConsole(t_Piece * self, int * lig, int * col, int colour);

#endif // AFFICHAGECONSOLE_H_INCLUDED
