#include "gameLoop.h"

/*
    Ce fichier contiendra toutes les définitions des fonctions ayant rapport à la boucle de jeu
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
		if(!game->joueurListe[game->joueurActif].bloque)
		{
			if(game->joueurListe[game->joueurActif].type == JOUEUR_HUMAIN)
				humanTurn(game);

			else if(game->joueurListe[game->joueurActif].type == JOUEUR_ALEATOIRE)
				aleaTurn(game);

			else if(game->joueurListe[game->joueurActif].type == JOUEUR_HEURISTIQUE)
				heuristurn(game);

			// On teste si le joueur est bloqué
			isBloque(&game->joueurListe[game->joueurActif]);
		}
		else
		{

			gotoligcol(22, 0);
			changeColour(game->joueurListe[game->joueurActif].couleur, L_BLACK);
			printf("Vous etes coince");

			affichageSansCurseur(game);

			getch();

			if(isFinished(game))
			{
				/// ECRAN DE FIN DE LA PARTIE
				endScreen(game);

				game->state = PARTIE_FINIE;

				getch();
			}

			gotoligcol(22, 0);
			changeColour(L_WHITE, BLACK);
			printf("                ");
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
	t_Coup * a_jouer;

	// Affichage de la partie dans son état actuel
	affichageGame(game);

	// 1 On détermine un coup aléatoire à jouer
	a_jouer = getAleaCoup(&game->joueurListe[game->joueurActif]);

	// 2 On doit maintenant déplacer le joueur actif
	slowPlay(game, a_jouer);
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
		affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID, 1);
	}
	else if(pressed == game->touches.bas)
	{
		game->joueurListe[game->joueurActif].curs_lig++;
		if(testDepassement(game))
			game->joueurListe[game->joueurActif].curs_lig--;
		affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID, 1);
	}
	else if(pressed == game->touches.gauche)
	{
		game->joueurListe[game->joueurActif].curs_col--;
		if(testDepassement(game))
			game->joueurListe[game->joueurActif].curs_col++;
		affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID, 1);
	}
	else if(pressed == game->touches.droite)
	{
		game->joueurListe[game->joueurActif].curs_col++;
		if(testDepassement(game))
			game->joueurListe[game->joueurActif].curs_col--;

		affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID, 1);
	}
	else if(pressed == game->touches.rotation)
	{
		rotateThroughPiece(game->joueurListe[game->joueurActif].ancre);
		// On teste si ce mouvement fait sortir des cases ou non
		if(testDepassement(game))
			antiRotateThroughPiece(game->joueurListe[game->joueurActif].ancre);

		// On affiche la zone des pièces
		affichageGame(game);

	}
	else if(pressed == game->touches.inversion)
	{
		invertThroughPiece(game->joueurListe[game->joueurActif].ancre);

		if(testDepassement(game))
			cycleThroughPiece(game->joueurListe[game->joueurActif].ancre);

		// On affiche la zone des pièces
		affichageGame(game);
	}
	else if(pressed == game->touches.scrollBas)
	{
		scrollToSuivant(&game->joueurListe[game->joueurActif]);

		if(testDepassement(game))
			scrollToPrecedent(&game->joueurListe[game->joueurActif]);

		// On affiche la zone des pièces
		affichageGame(game);
	}
	else if(pressed == game->touches.scrollHaut)
	{
		scrollToPrecedent(&game->joueurListe[game->joueurActif]);

		if(testDepassement(game))
			scrollToSuivant(&game->joueurListe[game->joueurActif]);

		// On affiche la zone des pièces
		affichageGame(game);
	}
	else if(pressed == game->touches.selectionner)
	{
		if(playCoup(game) == 0)
		{
			affichageGame(game);
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

void heuristurn(t_Partie * game)
{
	// 0 Variables
	t_Joueur * jAct = &game->joueurListe[game->joueurActif];
	t_Coin * curs_coin = jAct->possibilites;
	t_Coup * curs_coup = NULL;

	t_Coup * best_coup = NULL;

	unsigned int max_score = 0;
	unsigned int act_score = 0;

    // 1 Parcourt de la liste des coups possibles
    while(curs_coin)
	{
		curs_coup = curs_coin->ancre;
		while(curs_coup)
		{
			act_score = BASE_SCORE;
			// 2 Attribution d'un score en fonction de la situation du coup en cours
			// 2.0 Score en fonction de la distance par rapport au centre
			act_score += DIST_FROM_CENTER_MULTIP * (abs((game->h_grid/2) - curs_coup->curs_i) + abs((game->w_grid/2) - curs_coup->curs_j));

			// 2.1 Score en fonction du nombre de coups de l'adversaire bloqués par ce coup
			act_score += get_n_BlockedPlays(game, curs_coup) * PER_BLOCKED_PLAYS;

			// 3 Mise à jour de max_score
			if(max_score < act_score)
			{
				max_score = act_score;
				best_coup = curs_coup;
			}

			curs_coup = curs_coup->suivant;
		}
		curs_coin = curs_coin->suivant;
	}

	// 4 On joue maintenant le meilleur coup que l'on a trouvé
	slowPlay(game, best_coup);
}

void slowPlay(t_Partie * game, t_Coup * a_jouer)
{
	// 0 Variables
	t_Joueur * actuel = &game->joueurListe[game->joueurActif];
	char stay = 1;

	while(stay)
	{
		// 2.0 On commence par trouver la bonne pièce
		while(actuel->ancre->number != a_jouer->piece)
		{
			scrollToSuivant(actuel);
			testDepassement(game);

			affichageGame(game);
			waitSeconds(game->game_options.bot_delay);
			FILE * fic;
			fic = fopen(LOG_ALEA_NAME, "a");
			if(fic)
			{
				fprintf(fic, "Scroll to suivant\n");
				fclose(fic);
			}
		}
		// 2.1 Ensuite on trouve la bonne orientation / inversion
		while(actuel->ancre->orientation != a_jouer->rotation)
		{
			rotateThroughPiece(actuel->ancre);
			testDepassement(game);

			affichageGame(game);
			waitSeconds(game->game_options.bot_delay);
			FILE * fic;
			fic = fopen(LOG_ALEA_NAME, "a");
			if(fic)
			{
				fprintf(fic, "Piece rotation\n");
				fclose(fic);
			}
		}
		while(actuel->ancre->inversion != a_jouer->inversion)
		{
			invertThroughPiece(actuel->ancre);
			testDepassement(game);

			affichageGame(game);
			waitSeconds(game->game_options.bot_delay);
			FILE * fic;
			fic = fopen(LOG_ALEA_NAME, "a");
			if(fic)
			{
				fprintf(fic, "Piece inversion\n");
				fclose(fic);
			}
		}
		// 2.2 Enfin on la déplace au bon endroit
		while(actuel->curs_lig != a_jouer->curs_i || actuel->curs_col != a_jouer->curs_j)
		{
			if(actuel->curs_lig < a_jouer->curs_i)
			{
				actuel->curs_lig += 1;
				testDepassement(game);
				FILE * fic;
				fic = fopen(LOG_ALEA_NAME, "a");
				if(fic)
				{
					fprintf(fic, "Lig ++\n");
					fclose(fic);
				}
			}
			else if(actuel->curs_lig > a_jouer->curs_i)
			{
				actuel->curs_lig -= 1;
				testDepassement(game);
				FILE * fic;
				fic = fopen(LOG_ALEA_NAME, "a");
				if(fic)
				{
					fprintf(fic, "Lig --\n");
					fclose(fic);
				}
			}
			if(actuel->curs_col < a_jouer->curs_j)
			{
				actuel->curs_col += 1;
				testDepassement(game);
				FILE * fic;
				fic = fopen(LOG_ALEA_NAME, "a");
				if(fic)
				{
					fprintf(fic, "Col ++\n");
					fclose(fic);
				}
			}
			else if(actuel->curs_col > a_jouer->curs_j)
			{
				actuel->curs_col -= 1;
				testDepassement(game);
				FILE * fic;
				fic = fopen(LOG_ALEA_NAME, "a");
				if(fic)
				{
					fprintf(fic, "Col --\n");
					fclose(fic);
				}
			}
			affichageGame(game);
			waitSeconds(game->game_options.bot_delay);
		}

		// 3 Enfin on joue le coup correspondant
		if(playCoup(game) == 0)
		{
			affichageGame(game);
			stay = 0;
		}
	}
}
