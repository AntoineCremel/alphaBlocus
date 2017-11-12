#include "partie.h"

void initialisationPartie(t_Partie * self, int w_grille, int h_grille, char partieType, int n_arguments, ...)
{
	// -1 Remise à jour des logs
	FILE * fic;
	fic = fopen("data/logs/corners.txt", "w");
	fclose(fic);
	fic = fopen(LOG_PLAYS_NAME, "w");
	fclose(fic);
	fic = fopen(LOG_FIND_NAME, "w");
	fclose(fic);
	fic = fopen(LOG_ALEA_NAME, "w");
	fclose(fic);
	fic = fopen(LOG_UPDATE_PLAYS, "w");
	fclose(fic);

	// 0 Variables
	// Variable de la bibliotheque stdarg contenant tous les arguments contenus dans les ...
	va_list valist;

	// 0.1 On initialise la liste d'arguments
	va_start(valist, n_arguments);

	// 1 Tout d'abord on initialise la liste de joueurs
	// 1.0 On alloue la place mémoire nécessaire
	self->joueurListe = (t_Joueur*)malloc((n_arguments/2) * sizeof(t_Joueur));
	// 1.1 Ensuite on la remplit avec des joueurs que l'on initialise en même temps
	for(int i=0; i < (n_arguments/4); i++)
	{
		self->joueurListe[i].type = (char)va_arg(valist, int);
		self->joueurListe[i].couleur = (char)va_arg(valist, int);

		// On initialise la position de départ du joueur
		self->joueurListe[i].start_lig = va_arg(valist, int);
		self->joueurListe[i].start_col = va_arg(valist, int);

		// On initialise la position de départ du curseur
		// En blindant pour que la pièce ne déborde pas de la grille
		self->joueurListe[i].curs_lig = self->joueurListe[i].start_lig;
		self->joueurListe[i].curs_col = self->joueurListe[i].start_col;

		// 1.2 Creation du joueur
		if(partieType == PARTIE_STANDARD)
			joueurInitialisation(&self->joueurListe[i], "data/gameInit/stdPiecesList.txt");

		else if(partieType == PARTIE_DEV)
			joueurInitialisation(&self->joueurListe[i], "data/gameInit/devPiecesList.txt");

		// On initialise la variable de deadlock
		self->joueurListe[i].bloque = 0;
	}
	// 1.3 Libération de la valist
	va_end(valist);

	// 2 Il faut maintenant allouer la place mémoire à la grille
	self->grille = (char**)malloc(h_grille * sizeof(char*));

	for(int i=0; i < h_grille; i++)
	{
		self->grille[i] = (char*)malloc(w_grille * sizeof(char));
		// On remplit chaque case par la valeur correspondant à une case vide
		for(int j=0; j < w_grille; j++)
			self->grille[i][j] = CASE_VIDE;
	}

	// 3 On initialise l'état de la partie
	/// Pour l'instant la partie commence à l'état PARTIE_EN_COURS
	self->state = PARTIE_EN_COURS;

	// On initialise les variables de taille de partie
	self->h_grid = h_grille;
	self->w_grid = w_grille;

	// On initialise le nombre de joueur
	self->n_Players = n_arguments/4;

	// On fait un tour des joueurs actifs
	for(int i=0; i < n_arguments/4; i++)
	{
		self->joueurActif = i;
		// Pour tester si le curseur ne déborde pas
		testDepassement(self);
		// Pour mettre à jouer sa liste de coups possibles
		findAllPlaysHere(self, self->joueurListe[self->joueurActif].possibilites, i);
	}

	// 4 On initialise les controles
	loadControles(&self->touches);
	// 5 On initialise les options de jeu
	loadGameOptions(&self->game_options);

}

void deinitialisationPartie(t_Partie * self)
{
	// 0 Variables

	// 1.0 Boucle de désinitialisation des joueurs
	for(int i=0; i < self->n_Players; i++)
	{
		joueurDesinit(&self->joueurListe[i]);
	}
	// 1.1 Libération du tableau
	free(self->joueurListe);
	self->joueurListe = NULL;

	// 2.0 Boucle de libération de la mémoire de chaque ligne de la grille
	for(int i=0; i < self->h_grid; i++)
	{
		free(self->grille[i]);
		self->grille[i] = NULL;
	}
	free(self->grille);
	self->grille = NULL;
}

char testDepassement(t_Partie * self)
{
	// 0 Variables
	// 0.1 C'est dans ces deux int que l'on va stocker l'équivalent
	//		de la case actuelle de la piece sur la grille
	int i_gameGrid;
	int j_gameGrid;

	int cleared = 0;

	// Dans le cas où il n'y pas de pièce à placer, on ne fait rien
	if(self->joueurListe[self->joueurActif].ancre == NULL)
		return 0;

	// 1 On parcourt les cases de la piece concernée,
	// 		et on détermine s'il y en a qui dépassent
	while(!cleared)
	{
		cleared = 1;

		for(int i=0; i < I_TAB_PIECE; i++)
		{
			for(int j=0; j < J_TAB_PIECE; j++)
			{
				if(isPiece(self->joueurListe[self->joueurActif].ancre->grille[i][j]))
				{
					// On calcule la position de cette case sur la game_grid
					i_gameGrid = self->joueurListe[self->joueurActif].curs_lig + i + I_CENTRE_PIECE;
					j_gameGrid = self->joueurListe[self->joueurActif].curs_col + j + J_CENTRE_PIECE;



					/*if(i_gameGrid < 0
						|| i_gameGrid >= self->h_grid)
						// Si la piece dépasse d'un coté ou de l'autre en i
						return 1;

					if(j_gameGrid < 0
						|| j_gameGrid >= self->w_grid)
						// Si la pièce dépasse d'un côté ou de l'autre en j
						return 1;
					// On vérifie que la pièce ne dépasse pas
					*/

					if(i_gameGrid < 0)
					{
						self->joueurListe[self->joueurActif].curs_lig++;
						cleared = 0;
					}
					else if(i_gameGrid >= self->h_grid)
					{
						self->joueurListe[self->joueurActif].curs_lig--;
						cleared = 0;
					}

					if(j_gameGrid < 0)
					{
						self->joueurListe[self->joueurActif].curs_col++;
						cleared = 0;
					}
					else if(j_gameGrid >= self->w_grid)
					{
						self->joueurListe[self->joueurActif].curs_col--;
						cleared = 0;
					}

				}
			}
		}
	}
	return 0;
}

char playCoup(t_Partie * self)
{
	// 0 Variables
	char coin = 1;
	// 0.1 C'est dans ces deux int que l'on va stocker l'équivalent
	//		de la case actuelle de la piece sur la grille
	int i_gameGrid;
	int j_gameGrid;

	// 0.2 Variable pour tester d'autres joueurs que le joueur actif
	int joueur_a_check;

	// 1 On parcourt les cases de la piece
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			i_gameGrid = self->joueurListe[self->joueurActif].curs_lig + i + I_CENTRE_PIECE;
			j_gameGrid = self->joueurListe[self->joueurActif].curs_col + j + J_CENTRE_PIECE;
			// 1.0 Dans le cas où se trouve bien une case de la piece
			// 		à cet emplacement de la grille
			if(isPiece(self->joueurListe[self->joueurActif].ancre->grille[i][j]))
			{
				// 1.1 On vérifie que l'on se trouve bien sur une case vide
				if(self->grille[i_gameGrid][j_gameGrid] != CASE_VIDE)
					return 1;

				// 1.2 Ensuite, on vérifie que l'on n'est pas au bord de
				// l'une de nos propres cases
				// Et on en profite pour chercher si l'on trouve le coin d'une de nos pièces
				if(i_gameGrid > 0)
				{
					if(self->grille[i_gameGrid - 1][j_gameGrid] == self->joueurActif)
						return 1;

					if(j_gameGrid > 0)
					{
						if(self->grille[i_gameGrid - 1][j_gameGrid - 1] == self->joueurActif)
							coin = 0;
					}
					if(j_gameGrid < self->w_grid - 1)
					{
						if(self->grille[i_gameGrid - 1][j_gameGrid + 1] == self->joueurActif)
							coin = 0;
					}
				}
				if(i_gameGrid < self->h_grid - 1)
				{
					if(self->grille[i_gameGrid + 1][j_gameGrid] == self->joueurActif)
						return 1;

					if(j_gameGrid > 0)
					{
						if(self->grille[i_gameGrid + 1][j_gameGrid - 1] == self->joueurActif)
							coin = 0;
					}
					if(j_gameGrid < self->w_grid - 1)
					{
						if(self->grille[i_gameGrid + 1][j_gameGrid + 1] == self->joueurActif)
							coin = 0;
					}
				}
				if(j_gameGrid > 0)
				{
					if(self->grille[i_gameGrid][j_gameGrid - 1] == self->joueurActif)
						return 1;
				}
				if(j_gameGrid < self->w_grid - 1)
				{
					if(self->grille[i_gameGrid][j_gameGrid + 1] == self->joueurActif)
						return 1;
				}

				// 1.3.0 Enfin, on voit si la la position de départ
				// est en contact avec cette case

				if(i_gameGrid == self->joueurListe[self->joueurActif].start_lig
					&& j_gameGrid == self->joueurListe[self->joueurActif].start_col)
				{
					coin = 0;
				}

				// 1.4 On vérifie qu'on ne déborde sur aucune case de départ d'autres joueurs
				for(int k = 1; k < self->n_Players; k++)
				{
					joueur_a_check = (self->joueurActif + k) % self->n_Players;

					if(i_gameGrid == self->joueurListe[joueur_a_check].start_lig
					&& j_gameGrid == self->joueurListe[joueur_a_check].start_col)
						coin = 1;
				}
			}
		}
	}
	// 1.3.2 Si on n'a pas trouvé de coin, alors le coup n'est pas légal
	if(coin == 1)
	{
		return 1;
	}
	// 2 Si l'on est arrivé ici sans faire de return 1, c'est que le coup est légal,
	// il faut donc le jouer
	// 2.0 Si l'on a utilisé la poistion de départ, il faut la mettre
	// outbound pour indiquer qu'elle n'est plus utilisable
	self->joueurListe[self->joueurActif].start_lig = OUT_BOUND;
	self->joueurListe[self->joueurActif].start_col = OUT_BOUND;

	// 2.1 On effectue une boucle pour placer chacune des cases de la piece sur la grille
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			if(isPiece(self->joueurListe[self->joueurActif].ancre->grille[i][j]))
			{
				i_gameGrid = self->joueurListe[self->joueurActif].curs_lig + i + I_CENTRE_PIECE;
				j_gameGrid = self->joueurListe[self->joueurActif].curs_col + j + J_CENTRE_PIECE;

				// 2.1 On place la case correspondante sur la grille
				self->grille[i_gameGrid][j_gameGrid] = self->joueurActif;
			}
		}
	}
	// 2.2 Un fois que toutes les cases de la pièce ont été placées sur la grille,
	// Incrémenter le score dudit joueur
	self->joueurListe[self->joueurActif].score += (int)self->joueurListe[self->joueurActif].ancre->taille;
	// Mettre à jour  les coins du joueur en cours
	recordPlay(self);
	// on peut effacer la pièce de la liste de pièces du joueur actif
	scrapAncre(&self->joueurListe[self->joueurActif]);

	// Enfin on fait le tour des coins à proximité et on les remplit
	updateListesPossibilites(self, self->joueurListe[self->joueurActif].curs_lig,
							self->joueurListe[self->joueurActif].curs_col,
							I_TAB_PIECE + I_TAB_PIECE/2 + 1, J_TAB_PIECE + J_TAB_PIECE/2 + 1);

	// 3 Une fois que l'on a fait cela, on s'assure que la nouvelle pièce ne dépasse pas de la grille
	if(testDepassement(self) == 1)
	{
		self->joueurListe[self->joueurActif].curs_lig = self->h_grid / 2;
		self->joueurListe[self->joueurActif].curs_col = self->w_grid / 2;
	}

	return 0;
}

void nextPlayer(t_Partie * self)
{
	// 0 Variables
	//printf("n_Players : %i\n", self->n_Players);

	// 1 On incrémente activePlayer
	self->joueurActif = self->joueurActif + 1;
	if(self->joueurActif >= self->n_Players)
		self->joueurActif = 0;
}

/// Les coins
void findAllPlaysHere(t_Partie * self, t_Coin * here, int n_joueurActuel)
{
	// 0 Variables
	t_Piece * depart = self->joueurListe[n_joueurActuel].ancre;
	t_Piece * pieceActuelle;
	int curs_i;
	int curs_j;

	// 1 Tout d'abord, on vérifie que l'espace du coin est toujours libre et n'est pas occupé
	emptyCoin(here);
	if(self->grille[here->pos_i][here->pos_j] != CASE_VIDE)
	{
		return;
	}

	do
	{
		pieceActuelle = self->joueurListe[n_joueurActuel].ancre;

		if(pieceActuelle)
		{

			for(int k = 0; k < n_rotations(pieceActuelle); k++)
			{
				// On ajuste la rotation de la piece
				cycleThroughPiece(pieceActuelle);
				// On teste de mettre chacun des coins de la pièce sur ce coin là
				for(int i = 0; i < I_TAB_PIECE; i++)
				{
					for(int j = 0; j < J_TAB_PIECE; j++)
					{
						if(isCoin(pieceActuelle->grille[i][j]))
						{
							// Si l'on a trouve un coin à cet endroit là, alors on tente de placer la pièce en question
							if(testPlacement(self, here->pos_i, here->pos_j, i, j, &curs_i, &curs_j, n_joueurActuel))
							{
								// Ajouter le coup correspondant à la liste chainee du coin en cours
								addCoup(here, curs_i, curs_j, pieceActuelle->orientation, pieceActuelle->inversion, pieceActuelle->number);
							}
						}
					}
				}
			}
		}
		// On avance de un parmi les pièces du joueurs actifs
		scrollToSuivant(&self->joueurListe[n_joueurActuel]);
	}while(self->joueurListe[n_joueurActuel].ancre != depart);
}

char testPlacement(t_Partie * self, int game_i, int game_j, int piece_i, int piece_j, int * curs_i, int * curs_j, int n_joueurActuel)
{
	// 0 Variables
	int repere_i = game_i - piece_i;
	int repere_j = game_j - piece_j;
	int grille_i, grille_j;
	t_Piece * actuelle = self->joueurListe[n_joueurActuel].ancre;

	// 1 On determine la position du curseur
	*curs_i = repere_i + I_TAB_PIECE / 2;
	*curs_j = repere_j + J_TAB_PIECE / 2;

	// 2 Ensuite on fait le tour des cases de la piece pour voir s'il y a problème
	if(actuelle)
	{
		FILE * fic;
		fic = fopen(LOG_FIND_NAME, "a");
		if(fic)
		{
			fprintf(fic, "Testing piece n : %i, au coin (%i, %i) in game grid, with orientation (%i, %i) from square (%i, %i) of piece, donc position du curseur : (%i, %i)\n",
					actuelle->number, game_i, game_j, actuelle->orientation, actuelle->inversion, piece_i, piece_j, *curs_i, *curs_j);
			fclose(fic);
		}

		for(int i = 0; i < I_TAB_PIECE; i++)
		{
			for(int j = 0; j < J_TAB_PIECE; j++)
			{
				// Si il y a un carré de la pièce à l'emplacement actuel
				if(isPiece(actuelle->grille[i][j]))
				{
					grille_i = repere_i + i;
					grille_j = repere_j + j;
					// 3 On regarde si la case correspondante de la grille est interdite
					// 3.0 Verification que l'on est bien dans les limites de la grille
					if(grille_i < 0 || grille_i >= self->h_grid || grille_j < 0 || grille_j >= self->w_grid)
						return 0;

					// 3.1 Verification que l'on est bien sur une case vide
					if(self->grille[grille_i][grille_j] != CASE_VIDE)
						return 0;

					// 3.2 Verification que l'on n'est pas sur la case de départ d'un autre joueur
					for(int p = 1; p < self->n_Players; p++)
					{
						if(grille_i == self->joueurListe[(n_joueurActuel + p) % self->n_Players].start_lig
						&& grille_j == self->joueurListe[(n_joueurActuel + p) % self->n_Players].start_col)
							return 0;
					}

					// 3.3 Verification que l'on n'est pas à côté d'une pièce alliée
					if(grille_i > 0)
					{
						if(self->grille[grille_i-1][grille_j] == n_joueurActuel)
							return 0;
					}
					if(grille_i < self->h_grid - 1)
					{
						if(self->grille[grille_i+1][grille_j] == n_joueurActuel)
							return 0;
					}
					if(grille_j > 0)
					{
						if(self->grille[grille_i][grille_j-1] == n_joueurActuel)
							return 0;
					}
					if(grille_j < self->w_grid - 1)
					{
						if(self->grille[grille_i][grille_j+1] == n_joueurActuel)
							return 0;
					}
				}
			}
		}
	}
	else
		return 0;
	// Si l'on est arrivé jusqu'ici sans rencontrer de return 0, c'est que tout va bien
	// On indique au log que le test a été successful
	FILE * fic;
	fic = fopen(LOG_FIND_NAME, "a");
	if(fic)
	{
		fprintf(fic, "CONFIRMED\n");
		fclose(fic);
	}
	return 1;
}

void updateListesPossibilites(t_Partie * self, int curs_i, int curs_j, int rad_i, int rad_j)
{
	// 0 Variables
	int n_JoueurActuel = self->joueurActif;
	t_Joueur * joueurActuel;
	t_Coin * coinCurs = NULL;

	int compt = 1;

	// 1 On fait le tour des joueurs pour mettre à jour les coins qui sont
	// dans l'aire d'influence de cette case
	// 1.0 Boucle qui parcourt chaque joueur de la partie
	do
	{
		joueurActuel = &self->joueurListe[n_JoueurActuel];
		coinCurs = joueurActuel->possibilites;

		// 1.1 Boucle qui parcourt les coins du joueur
		while(coinCurs)
		{

			// 1.1.0 On teste s'il s'agit d'un coin dans le rayon d'action de cette nouvelle piece
			// Pour le calcul du rayon, on fait une forme de diamant
			if(coinCurs->pos_i > curs_i - rad_i + abs(coinCurs->pos_j - curs_j) && coinCurs->pos_i < curs_i + rad_i - abs(coinCurs->pos_j - curs_j)
			&& coinCurs->pos_j > curs_j - rad_j + abs(coinCurs->pos_i - curs_i) && coinCurs->pos_j < curs_j + rad_j - abs(coinCurs->pos_i - curs_i))
			{
				findAllPlaysHere(self, coinCurs, n_JoueurActuel);
			}

			coinCurs = coinCurs->suivant;
			compt++;
		}

		// On commence  par s'assurer qu'il n'y a pas de coins vides dans la liste de possibilités
		// du joueur actuel
		clearEmptyCoins(joueurActuel);

		n_JoueurActuel = (n_JoueurActuel + 1) % self->n_Players;
	}while(n_JoueurActuel != self->joueurActif);
}

void recordPlay(t_Partie * self)
{
	// 0 Variables
	t_Joueur * joueurActuel = &self->joueurListe[self->joueurActif];
	t_Coin * coinCurs = joueurActuel->possibilites;
	// Variables qui correspondent à l'emplacement du carre i, j de la pièce active
	// sur la grille
	int grille_i, grille_j;

	// 1 On commence par traiter le joueur actuel
	// 1.0 On retire de ses coups tous ceux qui impliquent la pièce qu'il vient de jouer
	//	Double while de parcours de la double liste chaînée
	while(coinCurs)
	{
		scrapPieceCoups(coinCurs, joueurActuel->ancre->number);
		coinCurs = coinCurs->suivant;
	}

	// 1.1 On rajoute tous les coins de la pièce qu'il vient de jouer
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			// 1.1.0 Si l'on est sur une case de la pièce qui n'est pas une case morte
			if(isCoin(joueurActuel->ancre->grille[i][j]))
			{
				// 1.1.1 On se place à l'endroit de la grille de jeu qui correspond
				grille_i = joueurActuel->curs_lig + i + I_CENTRE_PIECE;
				grille_j = joueurActuel->curs_col + j + J_CENTRE_PIECE;

				// 1.1.2 Ensuite on regarde les 4 coins autour de cette case pour voir s'ils
				// sont éligibles pour être ajoutés à la liste de coins du joueur
				checkAround(self, grille_i, grille_j);
			}
		}
	}
}

void checkAround(t_Partie * self, int grille_i, int grille_j)
{
	// 0 Variables
	int corn_i = grille_i;
	int corn_j = grille_j;
	char ajout;

	// 1 On regarde les coins autour de la case
	for(int cyc = 0; cyc < 4; cyc++)
	{
		/*
		corn_i = grille_i;
		corn_j = grille_j;
		cycleThroughCorner(&corn_i, &corn_j, cyc);*/
		if(cyc < 2)
			corn_i = grille_i - 1;
		else
			corn_i = grille_i + 1;
		if(cyc % 2 == 0)
			corn_j = grille_j - 1;
		else
			corn_j = grille_j + 1;

		if(corn_i >= 0 && corn_j >= 0 && corn_i < self->h_grid && corn_j < self->w_grid)
		{
			if(self->grille[corn_i][corn_j] == CASE_VIDE)
			{
				ajout = 1;
				if(corn_i > 0)
				{
					if(self->grille[corn_i-1][corn_j] == self->joueurActif)
						ajout = 0;
				}
				if(corn_i < self->h_grid - 1)
				{
					if(self->grille[corn_i+1][corn_j] == self->joueurActif)
						ajout = 0;
				}
				if(corn_j > 0)
				{
					if(self->grille[corn_i][corn_j-1] == self->joueurActif)
						ajout = 0;
				}
				if(corn_j < self->w_grid - 1)
				{
					if(self->grille[corn_i][corn_j+1] == self->joueurActif)
						ajout = 0;
				}
				// Verifier que l'on n'est pas sur la case de depart d'un autre joueur
				for(int p = 1; p < self->n_Players; p++)
				{
					if(corn_i == self->joueurListe[(self->joueurActif + p) % self->n_Players].start_lig
					&& corn_j == self->joueurListe[(self->joueurActif + p) % self->n_Players].start_col)
						ajout = 0;
				}

				if(ajout)
				{
					addCoin(&self->joueurListe[self->joueurActif], corn_i, corn_j);
				}
			}
		}
	}
}
