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
}t_Coup;

#endif // COUP_H_INCLUDED
