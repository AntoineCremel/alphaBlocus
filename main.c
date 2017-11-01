#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include "src/gameLoop.h"
#include "src/joueur.h"

int main()
{
    /* 1 Test pour voir si tout fonctionne
		Lancement d'une partie avec deux joueurs humains
	*/
	t_Partie game;
	srand(time(NULL));

	initialisationPartie(&game, 14, 14, PARTIE_STANDARD, 8, JOUEUR_HUMAIN, RED, 6, 6, JOUEUR_HUMAIN, BLUE, 7, 7);

	printf("Initialisation faite\n");
	gameTurns(&game);

	deinitialisationPartie(&game);
    ///Ajouter le code du projet :-D
    return 0;
}
