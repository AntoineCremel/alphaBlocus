#include "gameLoop.h"

/*
    Ce fichier contiendra toutes les d�finitions des fonctions ayant rapport � la boucle de jeu
*/

void gameTurns(t_Partie * game)
{
	// 0 Variables

	// 1 Initialisation

	// 2 Boucle de tours
	while(game->state == PARTIE_EN_COURS)
	{
		// 2.0 On change le joueur actif
		nextPlayer(game);

		// 2.1 On effectue une action en fonction du joueur actif
		if(game->joueurListe[game->joueurActif].type == JOUEUR_HUMAIN)
			humanTurn(game);

		else if(game->joueurListe[game->joueurActif].type == JOUEUR_ALEATOIRE)
			aleaTurn(game);
	}
}

void humanTurn(t_Partie * game)
{
	// 0 Variables
	char pressed;
	char stay = 1;

	// 1 Boucle d'affichage et de mouvement possibles pour un joueur
	while(stay == 1)
	{
		// 1.0 Detection de l'appui d'une touche
		if(kbhit())
		{
			pressed = getch();
			// 1.1 On traite l'input du joueur pour savoir ce qu'il veut faire
			stay = treatInput(game, pressed);
		}

		// Affichage de l'ensemble de la partie
		affichageGame(game);

		// Attente
		waitSeconds(DELAY_BET_FRAMES);
	}
}
void aleaTurn(t_Partie * game)
{

}

char treatInput(t_Partie * game, char pressed)
{
	// 0 Variables

	// 1 Analyse de l'input.
	/*
		Chaque if teste la correspondance entre la touche press�e et une
		des touches d�finies comme touche effectuant une action.
	*/
	if(pressed == game->touches.haut)
	{
		game->joueurListe[game->joueurActif].curs_lig--;
		if(testDepassement(game))
			game->joueurListe[game->joueurActif].curs_lig++;
	}
	else if(pressed == game->touches.bas)
	{
		game->joueurListe[game->joueurActif].curs_lig++;
		if(testDepassement(game))
			game->joueurListe[game->joueurActif].curs_lig--;
	}
	else if(pressed == game->touches.gauche)
	{
		game->joueurListe[game->joueurActif].curs_col--;
		if(testDepassement(game))
			game->joueurListe[game->joueurActif].curs_col++;
	}
	else if(pressed == game->touches.droite)
	{
		game->joueurListe[game->joueurActif].curs_col++;
		if(testDepassement(game))
			game->joueurListe[game->joueurActif].curs_col--;
	}
	else if(pressed == game->touches.rotation)
	{
		pieceRotation(game->joueurListe[game->joueurActif].ancre);
		if(testDepassement(game))
			pieceAntiRotation(game->joueurListe[game->joueurActif].ancre);
	}
	else if(pressed == game->touches.inversion)
	{
		inversionPiece(game->joueurListe[game->joueurActif].ancre);
		if(testDepassement(game))
			inversionPiece(game->joueurListe[game->joueurActif].ancre);
	}
	else if(pressed == game->touches.scrollBas)
	{
		scrollToSuivant(&game->joueurListe[game->joueurActif]);
		if(testDepassement(game))
			scrollToPrecedent(&game->joueurListe[game->joueurActif]);
	}
	else if(pressed == game->touches.scrollHaut)
	{
		scrollToPrecedent(&game->joueurListe[game->joueurActif]);
		if(testDepassement(game))
			scrollToSuivant(&game->joueurListe[game->joueurActif]);
	}
	else if(pressed == game->touches.selectionner)
	{
		if(playCoup(game) == 0)
			return 0;
	}
	else if(pressed == game->touches.quitter)
	{
		game->state = PARTIE_FINIE;
		return 0;
	}


	return 1;
}
