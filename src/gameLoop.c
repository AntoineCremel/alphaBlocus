#include "gameLoop.h"

/*
    Ce fichier contiendra toutes les définitions des fonctions ayant rapport à la boucle de jeu
*/

void gameTurns(t_Partie * game)
{
	// 0 Variables

	// 1 Initialisation
	// Affichage de l'ensemble de la partie
	affichageGame(game);

	// 2 Boucle de tours
	while(game->state == PARTIE_EN_COURS)
	{
		// 2.0 On change le joueur actif
		nextPlayer(game);

		// 2.1 On effectue une action en fonction du joueur actif
		if(!game->joueurListe[game->joueurActif].bloque)
		{
			if(game->joueurListe[game->joueurActif].type == JOUEUR_HUMAIN)
				humanTurn(game);

			else if(game->joueurListe[game->joueurActif].type == JOUEUR_ALEATOIRE)
				aleaTurn(game);

			// On teste si le joueur est bloqué
			isBloque(&game->joueurListe[game->joueurActif]);
		}
		else
		{
			/// Ecrire un ecran pour indiquer que ce joueur est bloqué et ne peut plus jouer
		}
	}
}

void humanTurn(t_Partie * game)
{
	// 0 Variables
	char pressed;
	char stay = 1;

	affichageGame(game);
	// 1 Boucle d'affichage et de mouvement possibles pour un joueur
	while(stay == 1)
	{
		// 1.0 Detection de l'appui d'une touche
		pressed = getch();
		// 1.1 On traite l'input du joueur pour savoir ce qu'il veut faire
		stay = treatInput(game, pressed);

		// Attente
		// Pas nécessaire puisque l'on affiche la grille que lorsque l'on effectue un mouvement
		//waitSeconds(DELAY_BET_FRAMES);
	}
}
void aleaTurn(t_Partie * game)
{
	// 0 Variables
	t_Joueur * actuel = &game->joueurListe[game->joueurActif];
	t_Coup * a_jouer;
	char stay = 1;

	// 1 On détermine un coup aléatoire à jouer
	a_jouer = getAleaCoup(&game->joueurListe[game->joueurActif]);

	// 2 On doit maintenant déplacer le joueur actif
	while(stay)
	{
		// 2.0 On commence par trouver la bonne pièce
		while(actuel->ancre->number != a_jouer->piece)
		{
			scrollToSuivant(actuel);
			waitSeconds(game->game_options.bot_delay);
		}
		// 2.1 Ensuite on trouve la bonne orientation / inversion
		while(actuel->ancre->orientation != a_jouer->rotation)
		{
			pieceRotation(actuel->ancre);
			waitSeconds(game->game_options.bot_delay);
		}
		while(actuel->ancre->inversion != a_jouer->inversion)
		{
			inversionPiece(actuel->ancre);
			waitSeconds(game->game_options.bot_delay);
		}
		// 2.2 Enfin on la déplace au bon endroit
		while(actuel->curs_lig != a_jouer->curs_i || actuel->curs_col != a_jouer->curs_i)
		{
			if(actuel->curs_lig < a_jouer->curs_i)
			{
				actuel->curs_lig++;
			}
			else if(actuel->curs_lig > a_jouer->curs_i)
			{
				actuel->curs_lig--;
			}
			if(actuel->curs_col < a_jouer->curs_j)
			{
				actuel->curs_col++;
			}
			else if(actuel->curs_col > a_jouer->curs_j)
			{
				actuel->curs_col--;
			}
			waitSeconds(game->game_options.bot_delay);
		}

		// 3 Enfin on joue le coup correspondant
		if(playCoup(game) == 0)
		{
			affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID);
			stay = 0;
		}
	}
}

char treatInput(t_Partie * game, char pressed)
{
	// 0 Variables

	// 1 Analyse de l'input.
	/*
		Chaque if teste la correspondance entre la touche pressée et une
		des touches définies comme touche effectuant une action.
	*/
	if(pressed == game->touches.haut)
	{
		game->joueurListe[game->joueurActif].curs_lig--;
		if(testDepassement(game))
			game->joueurListe[game->joueurActif].curs_lig++;
		affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID);
	}
	else if(pressed == game->touches.bas)
	{
		game->joueurListe[game->joueurActif].curs_lig++;
		if(testDepassement(game))
			game->joueurListe[game->joueurActif].curs_lig--;
		affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID);
	}
	else if(pressed == game->touches.gauche)
	{
		game->joueurListe[game->joueurActif].curs_col--;
		if(testDepassement(game))
			game->joueurListe[game->joueurActif].curs_col++;
		affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID);
	}
	else if(pressed == game->touches.droite)
	{
		game->joueurListe[game->joueurActif].curs_col++;
		if(testDepassement(game))
			game->joueurListe[game->joueurActif].curs_col--;

		affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID);
	}
	else if(pressed == game->touches.rotation)
	{
		pieceRotation(game->joueurListe[game->joueurActif].ancre);
		// On teste si ce mouvement fait sortir des cases ou non
		if(testDepassement(game))
			pieceAntiRotation(game->joueurListe[game->joueurActif].ancre);

		// On affiche la zone des pièces
		affichageJoueurConsole(&game->joueurListe[game->joueurActif], I_PLACE_SCROLL, J_PLACE_SCROLL);
		affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID);

	}
	else if(pressed == game->touches.inversion)
	{
		inversionPiece(game->joueurListe[game->joueurActif].ancre);

		if(testDepassement(game))
			inversionPiece(game->joueurListe[game->joueurActif].ancre);

		// On affiche la zone des pièces
		affichageJoueurConsole(&game->joueurListe[game->joueurActif], I_PLACE_SCROLL, J_PLACE_SCROLL);
		affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID);
	}
	else if(pressed == game->touches.scrollBas)
	{
		scrollToSuivant(&game->joueurListe[game->joueurActif]);

		if(testDepassement(game))
			scrollToPrecedent(&game->joueurListe[game->joueurActif]);

		// On affiche la zone des pièces
		affichageJoueurConsole(&game->joueurListe[game->joueurActif], I_PLACE_SCROLL, J_PLACE_SCROLL);
		affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID);
	}
	else if(pressed == game->touches.scrollHaut)
	{
		scrollToPrecedent(&game->joueurListe[game->joueurActif]);

		if(testDepassement(game))
			scrollToSuivant(&game->joueurListe[game->joueurActif]);

		// On affiche la zone des pièces
		affichageJoueurConsole(&game->joueurListe[game->joueurActif], I_PLACE_SCROLL, J_PLACE_SCROLL);
		affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID);
	}
	else if(pressed == game->touches.selectionner)
	{
		if(playCoup(game) == 0)
		{
			affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID);
			return 0;
		}
	}
	else if(pressed == game->touches.quitter)
	{
		game->state = PARTIE_FINIE;
		return 0;
	}


	return 1;
}
