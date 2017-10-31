#include "partie.h"

void initialisationPartie(t_Partie * self, int w_grille, int h_grille, char partieType, int n_arguments, ...)
{
	// 0 Variables
	// Variable de la bibliotheque stdarg contenant tous les arguments contenus dans les ...
	va_list valist;

	// 0.1 On initialise la liste d'arguments
	va_start(valist, n_arguments);

	// 1 Tout d'abord on initialise la liste de joueurs
	// 1.0 On alloue la place mémoire nécessaire
	self->joueurListe = (t_Joueur*)malloc((n_arguments/2) * sizeof(t_Joueur));
	// 1.1 Ensuite on la remplit avec des joueurs que l'on initialise en même temps
	for(int i=0; i < (n_arguments/2); i++)
	{
		self->joueurListe[i].type = va_arg(valist, int);
		self->joueurListe[i].couleur = va_arg(valist, int);

		// 1.2 Creation du joueur
		/// Pour l'instant seul un type de partie est pris en compte
		joueurInitialisation(&self->joueurListe[i], "data/gameInit/stdPiecesList.txt");

		// On initialise la position du curseur
		self->joueurListe[i].curs_lig = h_grille/2;
		self->joueurListe[i].curs_col = w_grille/2;
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

	// On met joueur actif à 0
	self->joueurActif = n_arguments/2 - 1;

	// On initialise les variables de taille de partie
	self->h_grid = h_grille;
	self->w_grid = w_grille;

	// On initialise le nombre de joueur
	self->n_Players = n_arguments/2;

	// 4 On initialise les controles
	loadControles(&self->touches);
}

void deinitialisationPartie(t_Partie * self)
{
	// 0 Variables

	// 1.0 Boucle de désinitialisation des joueurs
	for(int i=0; i < sizeof(self->joueurListe)/sizeof(t_Joueur); i++)
	{
		joueurDesinit(&self->joueurListe[i]);
	}
	// 1.1 Libération du tableau
	free(self->joueurListe);
	self->joueurListe = NULL;

	// 2.0 Boucle de libération de la mémoire de chaque ligne de la grille
	for(int i=0; i < sizeof(char*) * sizeof(self->grille); i++)
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

	// Dans le cas où il n'y pas de pièce à placer, on ne fait rien
	if(self->joueurListe[self->joueurActif].ancre == NULL)
		return;

	// 1 On parcourt les cases de la piece concernée,
	// 		et on détermine s'il y en a qui dépassent
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			if(self->joueurListe[self->joueurActif].ancre->grille[i][j] == SYMB_PIECE)
			{
				// On calcule la position de cette case sur la game_grid
				i_gameGrid = self->joueurListe[self->joueurActif].curs_lig + i + I_CENTRE_PIECE;
				j_gameGrid = self->joueurListe[self->joueurActif].curs_col + j + J_CENTRE_PIECE;

				if(i_gameGrid < 0
					|| i_gameGrid >= self->h_grid)
					// Si la piece dépasse d'un coté ou de l'autre en i
					return 1;

				if(j_gameGrid < 0
					|| j_gameGrid >= self->w_grid)
					// Si la pièce dépasse d'un côté ou de l'autre en j
					return 1;
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

	// 1 On parcourt les cases de la piece
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			i_gameGrid = self->joueurListe[self->joueurActif].curs_lig + i + I_CENTRE_PIECE;
			j_gameGrid = self->joueurListe[self->joueurActif].curs_col + j + J_CENTRE_PIECE;
			// 1.0 Dans le cas où se trouve bien une case de la piece
			// 		à cet emplacement de la grille
			if(self->joueurListe[self->joueurActif].ancre->grille[i][j] == SYMB_PIECE)
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

				// 1.3.0 Enfin, on voit si le coin de la grille
				// est en contact avec cette case

				if((i_gameGrid == 0 && j_gameGrid == 0)
					|| (i_gameGrid == self->h_grid - 1 && j_gameGrid == 0)
					|| (i_gameGrid == 0 && j_gameGrid == self->w_grid - 1)
					|| (i_gameGrid == self->h_grid - 1 && j_gameGrid == self->w_grid - 1))
					coin = 0;
			}
		}
	}

	// 1.3.1 Si on n'a pas trouvé de coin, alors le coup n'est pas légal
	if(coin == 1)
		return 1;
	// 2 Si l'on est arrivé ici sans faire de return 1, c'est que le coup est légal,
	// il faut donc le jouer
	// 2.0 On effectue une boucle pour placer chacune des cases de la piece sur la grille
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			if(self->joueurListe[self->joueurActif].ancre->grille[i][j] == SYMB_PIECE)
			{
				i_gameGrid = self->joueurListe[self->joueurActif].curs_lig + i + I_CENTRE_PIECE;
				j_gameGrid = self->joueurListe[self->joueurActif].curs_col + j + J_CENTRE_PIECE;

				// 2.1 On place la case correspondante sur la grille
				self->grille[i_gameGrid][j_gameGrid] = self->joueurActif;
			}
		}
	}
	// 2.2 Un fois que toutes les cases de la pièce ont été placées sur la grille,
	// on peut effacer la pièce de la liste de pièces du joueur actif
	scrapAncre(&self->joueurListe[self->joueurActif]);

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
