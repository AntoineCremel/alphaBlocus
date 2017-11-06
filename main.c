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
	t_Partie game;
	srand(time(NULL));

	initialisationPartie(&game, 20, 20, PARTIE_STANDARD, 16, JOUEUR_HUMAIN, RED, 0, 0, JOUEUR_HUMAIN, GREEN, 0, 19, JOUEUR_HUMAIN, PURPLE, 19, 19, JOUEUR_HUMAIN, BLUE, 19, 0);

	printf("Initialisation faite\n");
	gameTurns(&game);

	deinitialisationPartie(&game);
    ///Ajouter le code du projet :-D
    return 0;
}
