#include "coup.h"

void emptyCoin(t_Coin * self)
{
	// 0 Variables
	t_Coup * buffer = self->ancre;
	FILE * fic;

	// 1 On désinitialise à chaque fois le premier maillon
	while(buffer)
	{
		self->ancre = buffer->suivant;

		// 2 Ecriture du log
		fic = fopen(LOG_PLAYS_NAME, "a");
		if(fic)
		{
			fprintf(fic, "Coin (%i, %i), EMPTYCOIN piece : %i, rotation : %i, inversion : %i i : %i, j : %i\n", buffer->piece, buffer->rotation, buffer->inversion, buffer->curs_i, buffer->curs_j);
			fclose(fic);
		}

		free(buffer);

		buffer = self->ancre;
	}
}

void addCoup(t_Coin * self, int curs_i, int curs_j, char orientation, char inversion, int piece)
{
	// 0 Variables
	t_Coup * buffer;
	FILE * fic;

	// 1 Allocation de la mémoire
	buffer = (t_Coup*)malloc(sizeof(t_Coup));

	// 2 Remplissage des variables
	buffer->curs_i = curs_i;
	buffer->curs_j = curs_j;
	buffer->rotation = orientation;
	buffer->inversion = inversion;
	buffer->piece = piece;

	// 2. 1 Ecriture du log
	fic = fopen(LOG_PLAYS_NAME, "a");
	if(fic)
	{
		fprintf(fic, "Coin (%i, %i), ADDED piece : %i, rotation : %i, inversion : %i i : %i, j : %i\n", buffer->piece, buffer->rotation, buffer->inversion, buffer->curs_i, buffer->curs_j);
		fclose(fic);
	}

	// 3 Ensuite on ajoute le nouveau coup à la chaine
	buffer->suivant = self->ancre;
	self->ancre = buffer;
}

void scrapPieceCoups(t_Coin * self, int piece)
{
	// 0 Variables
	t_Coup * curseur = NULL;
	t_Coup * prev = NULL;
	FILE * fic;

	if(self)
		curseur = self->ancre;
	else
		return;

	// 1 On parcourt la liste chainee
	while(curseur)
	{
		// 2 Si on a trouve une possibilité qui utilise cette pièce
		if(curseur->piece == piece)
		{
			fic = fopen(LOG_PLAYS_NAME, "a");
			if(fic)
			{
				fprintf(fic, "Coin (%i, %i), REMOVED piece : %i, rotation : %i, inversion : %i i : %i, j : %i\n", curseur->piece, curseur->rotation, curseur->inversion, curseur->curs_i, curseur->curs_j);
				fclose(fic);
			}

			if(prev)
			{
				prev->suivant = curseur->suivant;
				free(curseur);
				curseur = prev->suivant;
			}
			// Si l'on n'a pas encore defini prev, c'est que l'on est à l'ancre.
			else
			{
				self->ancre = curseur->suivant;
				free(curseur);
				curseur = self->ancre;
			}
		}

		// On avance d'un cran dans la chaîne
		prev = curseur;
		curseur = curseur->suivant;
	}
}
