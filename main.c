#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include "src/gameLoop.h"
#include "src/joueur.h"

int main()
{
    /* 1 Test pour voir si tout fonctionne
		Lancement d'une partie avec 4 joueurs humains
	*/
	char tab[10][20];
	int lig=2;

	srand(time(NULL));
	curseur(&lig);

    return 0;
}
