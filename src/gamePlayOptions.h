#ifndef GAMEPLAYOPTIONS_H_INCLUDED
#define GAMEPLAYOPTIONS_H_INCLUDED

#include <stdio.h>

// 0 Constantes

// 1 Structures
typedef struct gamePlayOptions
{
	// Variable qui d�termine combien de tours il faut attendre entre chaque action d'un bot
	float bot_delay;
	// Variable qui d�termine si le jeu doit montrer les coups possibles pour chaque joueur
	//� chaque tour de jeu
	char show_possibilites;
}t_GameOptions;

// 2 Prototypes de fonctions
void loadGameOptions(t_GameOptions * self);

#endif // GAMEPLAYOPTIONS_H_INCLUDED
