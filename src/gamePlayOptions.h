#ifndef GAMEPLAYOPTIONS_H_INCLUDED
#define GAMEPLAYOPTIONS_H_INCLUDED

#include <stdio.h>

// 0 Constantes

// 1 Structures
typedef struct gamePlayOptions
{
	// Variable qui détermine combien de tours il faut attendre entre chaque action d'un bot
	float bot_delay;
}t_GameOptions;

// 2 Prototypes de fonctions
void loadGameOptions(t_GameOptions * self);

#endif // GAMEPLAYOPTIONS_H_INCLUDED
