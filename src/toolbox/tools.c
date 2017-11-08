#include "tools.h"

void takeOutEndLines(char * chaine)
{
	for(int i=0; chaine[i] != '\0'; i++)
	{
		if(chaine[i] == '\n' && chaine[i + 1] == '\0')
		{
			chaine[i] = '\0';
		}
	}
}

void waitSeconds(float seconds)
{
	// 0 Variables
	clock_t end;

	// 1 Definition de l'heure a laquelle on veut attendre
	end = clock() + seconds * CLOCKS_PER_SEC;

	while(clock() < end);
}

void cycleThroughCorner(int * pos_i, int * pos_j, int loop)
{
	// Renvoit l'un des quatres coins de la case grille_i grille_j
	// en fonction de la valeur contenue dans loop
	if(loop%4 == 0)
	{
		*pos_i = *pos_i - 1;
		*pos_j = *pos_j - 1;
	}
	else if(loop%4 == 1)
	{
		*pos_i = *pos_i - 1;
		*pos_j = *pos_j + 1;
	}
	else if(loop%4 == 2)
	{
		*pos_i = *pos_i + 1;
		*pos_j = *pos_j + 1;
	}
	else if(loop%4 == 3)
	{
		*pos_i = *pos_i + 1;
		*pos_j = *pos_j - 1;
	}
}
