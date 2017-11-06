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

// Constante qui définit le nombre de caractère que l'on utilise pour une case de la piece
#define W_SQUARE 2
//		- Pour la zone de scroll :
#define W_SQUARE_SCROLL W_SQUARE

// Definition de la couleur de fond
//		- Pour la zone de scroll
#define SCROLL_BACK_COLOUR 	WHITE
//		- Pour la grille de jeu
#define GRID_BACK_COLOUR	L_BLACK

// Definition de la couleur de police
//		- Lorsque l'on voudrait mettre une couleur de police et de background qui seraient les même
#define FONT_SAME_FRONT	BLACK

// Definition des "skins" (lettres utilisées pour représenter différentes choses)
#define SKIN_CURSEUR_VIDE	' '
#define SKIN_CURSEUR_INTERDIT	'X'
#define SKIN_START				'A'

// Definition de l'endroit de la console où l'on place chaque partie de l'affichage
#define I_PLACE_GRID	0
#define J_PLACE_GRID	0
#define I_PLACE_SCROLL	0
#define J_PLACE_SCROLL	30

#define BASE_TEXT	WHITE
#define BASE_BACKGROUND	BLACK

// 1 Structures

// 2 Prototypes de fonctions
// gotoligcol permet de se placer à un endroit spécifique de la console.
void gotoligcol(int lig, int col);

// Fonction pour changer la couleur des lettres de la console.
void changeColour(int letters, int backGround);

// Fonction qui réunit tous les affichages dans la partie
//	 On fait passer les structures par pointeur pour économiser le passage par le tube,
//	pas pour pouvoir modifier leurs contenus
void affichageGame(t_Partie * game);

// Fonction pour afficher un rappel des contrôles sur la console
void affichageConsoleControles(t_Controles * self, int lig, int col);

// Cette fonction permet d'afficher la grille de jeu. Elle prend en paramètre la structure de la partie,
// ainsi que les coordonnées où la grille de jeu doit être affichée (lig et col désignent le point en haut à gauche)
void affichageConsoleGrilleDeJeu(t_Partie * self, int lig, int col);
// Appelée par l'affiochage de la grille de jeu, cette fonction affiche le curseur sur la grille.
void affichageConsoleCurseur(t_Partie * self, int lig, int col);
// Affichage des cases de départ
void affichageConsoleStart(t_Partie * self, int lig, int col);

// Cette fonction sert à afficher le joueur actif (les pièces dont il dispose)
// C'est cette fonction qui appellera pieceScrollConsole
void affichageJoueurConsole(t_Joueur * self, int lig, int col);
// Fonction qui sert à afficher une pièce dans la zone qui sert à choisir quelle pièce on va jouer
void affichagePieceScrollConsole(t_Piece * self, int lig, int col, int colour);

#endif // AFFICHAGECONSOLE_H_INCLUDED
