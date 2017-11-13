#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include "src/gameLoop.h"
#include "src/joueur.h"
#include "src/menu.h"

int main()
{
    /* 1 Test pour voir si tout fonctionne
		Lancement d'une partie avec 4 joueurs humains
	*/
	srand(time(NULL));

	superLoop();

    return 0;
}
