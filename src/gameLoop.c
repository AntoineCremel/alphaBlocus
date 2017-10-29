#include "gameLoop.h"

/*
    Ce fichier contiendra toutes les définitions des fonctions ayant rapport à la boucle de jeu
*/

void gameLoop(t_Partie * game, t_Controles * touches)
{
	// 0 Variables
	char pressed;

	// 1 Initialisations

	// 2 Boucle de jeu
	while(game->state == PARTIE_EN_COURS)
	{
		if(kbhit())
		{
			/// Resolution des actions a effectuer en cas de mouvement
			pressed = getch();
			treatInput(pressed, touches);
		}

		// Affichage de l'ensemble de la partie
		affichageGame(game, touches);

		// Attente
		waitSeconds(DELAY_BET_FRAMES);
	}
}

void treatInput(char pressed, t_Controles * touches)
{

}
