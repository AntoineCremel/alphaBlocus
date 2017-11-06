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

// Constante qui d�finit le nombre de caract�re que l'on utilise pour une case de la piece
#define W_SQUARE 2
//		- Pour la zone de scroll :
#define W_SQUARE_SCROLL W_SQUARE

// Definition de la couleur de fond
//		- Pour la zone de scroll
#define SCROLL_BACK_COLOUR 	WHITE
//		- Pour la grille de jeu
#define GRID_BACK_COLOUR	L_BLACK

// Definition de la couleur de police
//		- Lorsque l'on voudrait mettre une couleur de police et de background qui seraient les m�me
#define FONT_SAME_FRONT	BLACK

// Definition des "skins" (lettres utilis�es pour repr�senter diff�rentes choses)
#define SKIN_CURSEUR_VIDE	' '
#define SKIN_CURSEUR_INTERDIT	'X'
#define SKIN_START				'A'

// Definition de l'endroit de la console o� l'on place chaque partie de l'affichage
#define I_PLACE_GRID	0
#define J_PLACE_GRID	0
#define I_PLACE_SCROLL	0
#define J_PLACE_SCROLL	30

#define BASE_TEXT	WHITE
#define BASE_BACKGROUND	BLACK

// 1 Structures

// 2 Prototypes de fonctions
// gotoligcol permet de se placer � un endroit sp�cifique de la console.
void gotoligcol(int lig, int col);

// Fonction pour changer la couleur des lettres de la console.
void changeColour(int letters, int backGround);

// Fonction qui r�unit tous les affichages dans la partie
//	 On fait passer les structures par pointeur pour �conomiser le passage par le tube,
//	pas pour pouvoir modifier leurs contenus
void affichageGame(t_Partie * game);

// Fonction pour afficher un rappel des contr�les sur la console
void affichageConsoleControles(t_Controles * self, int lig, int col);

// Cette fonction permet d'afficher la grille de jeu. Elle prend en param�tre la structure de la partie,
// ainsi que les coordonn�es o� la grille de jeu doit �tre affich�e (lig et col d�signent le point en haut � gauche)
void affichageConsoleGrilleDeJeu(t_Partie * self, int lig, int col);
// Appel�e par l'affiochage de la grille de jeu, cette fonction affiche le curseur sur la grille.
void affichageConsoleCurseur(t_Partie * self, int lig, int col);
// Affichage des cases de d�part
void affichageConsoleStart(t_Partie * self, int lig, int col);

// Cette fonction sert � afficher le joueur actif (les pi�ces dont il dispose)
// C'est cette fonction qui appellera pieceScrollConsole
void affichageJoueurConsole(t_Joueur * self, int lig, int col);
// Fonction qui sert � afficher une pi�ce dans la zone qui sert � choisir quelle pi�ce on va jouer
void affichagePieceScrollConsole(t_Piece * self, int lig, int col, int colour);

#endif // AFFICHAGECONSOLE_H_INCLUDED
