#ifndef COUP_H_INCLUDED
#define COUP_H_INCLUDED

/*
	Ce fichier contient la d�finition d'un coup possible, c'est � dire d'un coup accessible � un joueur
*/

// 0 Constantes

// 1 Structures
typedef struct Coup
{
	// Variables de position
	int curs_i;
	int curs_y;
	// Variables qui indiquent la rotation de la pi�ce
	char rotation;
	char inversion;

	// Pointeur de la liste cha�n�e
	struct Coup * suivant;
}t_Coup;

typedef struct Coin
{
	// Variables de position
	int i;
	int j;

	// Pointeur sur Coup
	t_Coup * ancre;
	// Pointeur pour continuer la liste cha�n�e de points
	struct Coin * suivant;
}t_Coin;

// 2 Prototypes de fonction


#endif // COUP_H_INCLUDED
