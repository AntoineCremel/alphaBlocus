#include "partie.h"

void initialisationPartie(t_Partie * self, int w_grille, int h_grille, char partieType, t_Controles touches, int n_joueurs, ...)
{
	// 0 Variables
	// Variable de la bibliotheque stdarg contenant tous les arguments contenus dans les ...
	va_list valist;

	// 0.1 On initialise la liste d'arguments
	va_start(valist, n_joueurs);

	// 1 Tout d'abord on initialise la liste de joueurs
	// 1.0 On alloue la place m�moire n�cessaire
	self->joueurListe = (t_Joueur*)malloc(n_joueurs * sizeof(t_Joueur));
	// 1.1 Ensuite on la remplit avec des joueurs que l'on initialise en m�me temps
	for(int i=0; i < n_joueurs; i++)
	{
		self->joueurListe[i].type = (char)va_arg(valist, int);
		// 1.2 Creation du joueur
		/// Pour l'instant seul un type de partie est pris en compte
		joueurInitialisation(&self->joueurListe[i], "../data/gameInit/stdPiecesList.txt");
	}
	// 1.3 Lib�ration de la valist
	va_end(valist);

	// 2 Il faut maintenant allouer la place m�moire � la grille
	self->grille = (char**)malloc(h_grille * sizeof(char*));

	for(int i=0; i < h_grille; i++)
	{
		self->grille[i] = (char*)malloc(w_grille * sizeof(char));
		// On remplit chaque case par la valeur correspondant � une case vide
		for(int j=0; j < w_grille; j++)
			self->grille[i][j] = CASE_VIDE;
	}

	// 3 On initialise l'�tat de la partie
	/// Pour l'instant la partie commence � l'�tat PARTIE_EN_COURS
	self->state = PARTIE_EN_COURS;

	// 4 On initialise les controles
	self->touches = touches;
}

void deinitialisationPartie(t_Partie * self)
{
	// 0 Variables

	// 1.0 Boucle de d�sinitialisation des joueurs
	for(int i=0; i < sizeof(self->joueurListe)/sizeof(t_Joueur); i++)
	{
		joueurDesinit(&self->joueurListe[i]);
	}
	// 1.1 Lib�ration du tableau
	free(self->joueurListe);
	self->joueurListe = NULL;

	// 2.0 Boucle de lib�ration de la m�moire de chaque ligne de la grille
	for(int i=0; i < sizeof(char*) * sizeof(self->grille); i++)
	{
		free(self->grille[i]);
		self->grille[i] = NULL;
	}
	free(self->grille);
	self->grille = NULL;
}
