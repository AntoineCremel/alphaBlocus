#include "piece.h"

/*
    Ce fichier contiendra l'implémentation des fonctions liées à la gestion des pièces.
*/


void pieceRotation(t_Piece * self)
{
	// 0 Variables
	char buffer[I_TAB_PIECE][J_TAB_PIECE];

	// 1 Double boucle pour appliquer la formule de rotation à chaque point de la piece
	// 	On enregistre la nouvelle pièce dans le buffer dans un premier temps.
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			buffer[j][I_TAB_PIECE - 1 - i] = self->grille[i][j];
		}
	}
	// 2 Maintenant que le buffer contient la pièce post rotation,
	// il ne reste plus qu'à le stocker dans la pièce.
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			self->grille[i][j] = buffer[i][j];
		}
	}

	// On met à jour l'orientation
	self->orientation = (self->orientation + 1) % 4;
}

void pieceAntiRotation(t_Piece * self)
{
	// 0 Variables
	char buffer[I_TAB_PIECE][J_TAB_PIECE];

	// 1 Double boucle pour appliquer la formule de rotation à chaque point de la piece
	// 	On enregistre la nouvelle pièce dans le buffer dans un premier temps.
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			buffer[J_TAB_PIECE - 1 - j][i] = self->grille[i][j];
		}
	}
	// 2 Maintenant que le buffer contient la pièce post rotation,
	// il ne reste plus qu'à le stocker dans la pièce.
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			self->grille[i][j] = buffer[i][j];
		}
	}

	// On met à jour l'orientation
	self->orientation = (self->orientation + 3) % 4;
}

void inversionPiece(t_Piece * self)
{
	// 0 Variables
	char buffer[I_TAB_PIECE][J_TAB_PIECE];

	// 1 Double boucle pour appliquer la formule d'inversion à chaque point de la piece
	// 	On enregistre la nouvelle pièce dans le buffer dans un premier temps.
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			buffer[I_TAB_PIECE - 1 - i][j] = self->grille[i][j];
		}
	}
	// 2 Maintenant que le buffer contient la pièce post rotation,
	// il ne reste plus qu'à le stocker dans la pièce.
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			self->grille[i][j] = buffer[i][j];
		}
	}

	// On met à jour l'inversion de la pièce
	self->inversion = (self->inversion + 1) % 2;
}
