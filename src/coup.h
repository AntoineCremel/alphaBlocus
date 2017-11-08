#ifndef COUP_H_INCLUDED
#define COUP_H_INCLUDED

#include <stdlib.h>

/*
	Ce fichier contient la d�finition d'un coup possible, c'est � dire d'un coup accessible � un joueur
*/

// 0 Constantes

// 1 Structures
typedef struct Coup
{
	// Variables de position
	int curs_i;
	int curs_j;
	// Variables qui indiquent la rotation de la pi�ce
	char rotation;
	char inversion;

	// Variable qui indique quel coup il faut jouer
	int piece;

	// Pointeur de la liste cha�n�e
	struct Coup * suivant;
}t_Coup;

typedef struct Coin
{
	// Variables de position
	int pos_i;
	int pos_j;

	// Pointeur sur Coup
	t_Coup * ancre;
	// Pointeur pour continuer la liste cha�n�e de points
	struct Coin * suivant;
}t_Coin;

// 2 Prototypes de fonction

// Lib�ration de la m�moire des coins
void emptyCoin(t_Coin * self);
// Ajout d'un coup � la liste chainee d'un coin
void addCoup(t_Coin * self, int curs_i, int curs_j, char orientation, char inversion, int piece);
// Fonction pour retirer tous les coups au numero piece
void scrapPieceCoups(t_Coin * self, int piece);

#endif // COUP_H_INCLUDED
