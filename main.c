#include <stdio.h>
#include <stdlib.h>

#include "src/gameLoop.h"
#include "src/joueur.h"

int main()
{
    /* 1 Test pour voir si tout fonctionne
		Lancement d'une partie avec deux joueurs humains
	*/
	t_Partie game;

	printf("Bijour la gazelle\n");

	initialisationPartie(&game, 20, 20, PARTIE_STANDARD, 4, JOUEUR_HUMAIN, RED, JOUEUR_HUMAIN, L_RED);

	printf("Initialisation faite\n");
	gameTurns(&game);

	deinitialisationPartie(&game);
    ///Ajouter le code du projet :-D
    return 0;
}
