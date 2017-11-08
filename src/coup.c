#include "coup.h"

void emptyCoin(t_Coin * self)
{
	// 0 Variables
	t_Coup * buffer = self->ancre;

	// 1 On désinitialise à chaque fois le premier maillon
	while(buffer)
	{
		self->ancre = buffer->suivant;

		free(buffer);

		buffer = self->ancre;
	}
}

void addCoup(t_Coin * self, int curs_i, int curs_j, char orientation, char inversion, int piece)
{
	// 0 Variables
	t_Coup * buffer;

	// 1 Allocation de la mémoire
	buffer = (t_Coup*)malloc(sizeof(t_Coup));

	// 2 Remplissage des variables
	buffer->curs_i = curs_i;
	buffer->curs_j = curs_j;
	buffer->rotation = orientation;
	buffer->inversion = inversion;
	buffer->piece = piece;

	// 3 Ensuite on ajoute le nouveau coup à la chaine
	buffer->suivant = self->ancre;
	self->ancre = buffer;
}

void scrapPieceCoups(t_Coin * self, int piece)
{
	// 0 Variables
	t_Coup * curseur = self->ancre;
	t_Coup * prev = NULL;

	// 1 On parcourt la liste chainee
	while(curseur)
	{
		if(curseur->piece == piece)

		// On avance d'un cran dans la chaîne
		prev = curseur;
		curseur = curseur->suivant;
	}
}
