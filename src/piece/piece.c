#include "piece.h"

/*
    Ce fichier contiendra l'impl�mentation des fonctions li�es � la gestion des pi�ces.
*/


void pieceRotation(t_Piece * self)
{
	// On verifie qu'il s'agit bien d'une piece sur laquelle il est utile d'effectuer une rotation
	if(self->symetrie == SIMPLE)
		return;

	// 0 Variables
	char buffer[I_TAB_PIECE][J_TAB_PIECE];

	// 1 Double boucle pour appliquer la formule de rotation � chaque point de la piece
	// 	On enregistre la nouvelle pi�ce dans le buffer dans un premier temps.
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			buffer[j][I_TAB_PIECE - 1 - i] = self->grille[i][j];
		}
	}
	// 2 Maintenant que le buffer contient la pi�ce post rotation,
	// il ne reste plus qu'� le stocker dans la pi�ce.
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			self->grille[i][j] = buffer[i][j];
		}
	}

	// On met � jour l'orientation
	if(self->symetrie == COMPLET || self->symetrie == ROTATION_SEULE)
		self->orientation = (self->orientation + 1) % 4;
	else if(self->symetrie == DEMI_COMPLET || self->symetrie == DEMI_ROTATION)
		self->orientation = (self->orientation + 1) % 2;
	else
	// Valeur par d�faut au cas o�
		self->orientation = (self->orientation + 1) % 4;
}

void pieceAntiRotation(t_Piece * self)
{
	// On verifie qu'il s'agit bien d'une piece sur laquelle il est utile d'effectuer une rotation
	if(self->symetrie == SIMPLE)
		return;

	// 0 Variables
	char buffer[I_TAB_PIECE][J_TAB_PIECE];

	// 1 Double boucle pour appliquer la formule de rotation � chaque point de la piece
	// 	On enregistre la nouvelle pi�ce dans le buffer dans un premier temps.
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			buffer[J_TAB_PIECE - 1 - j][i] = self->grille[i][j];
		}
	}
	// 2 Maintenant que le buffer contient la pi�ce post rotation,
	// il ne reste plus qu'� le stocker dans la pi�ce.
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			self->grille[i][j] = buffer[i][j];
		}
	}

	// On met � jour l'orientation
	if(self->symetrie == DEMI_COMPLET || self->symetrie == DEMI_ROTATION)
		self->orientation = (self->orientation + 1) % 2;
	else
		self->orientation = (self->orientation + 3) % 4;
}

void inversionPiece(t_Piece * self)
{
	// 0 Variables
	char buffer[I_TAB_PIECE][J_TAB_PIECE];

	// 1 Double boucle pour appliquer la formule d'inversion � chaque point de la piece
	// 	On enregistre la nouvelle pi�ce dans le buffer dans un premier temps.
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			buffer[I_TAB_PIECE - 1 - i][j] = self->grille[i][j];
		}
	}
	// 2 Maintenant que le buffer contient la pi�ce post rotation,
	// il ne reste plus qu'� le stocker dans la pi�ce.
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			self->grille[i][j] = buffer[i][j];
		}
	}

	// On met � jour l'inversion de la pi�ce
	if(self->symetrie == COMPLET || self->symetrie == DEMI_COMPLET)
		self->inversion = (self->inversion + 1) % 2;
}

void invertThroughPiece(t_Piece * self)
{
	// 0 Variables

	// 1 En fonction de la valeur de sym�trie de la pi�ce pass�e en param�tre, on applique une inversion
	if(self->symetrie == SIMPLE)
		return;
	else
		inversionPiece(self);
}
void cycleThroughPiece(t_Piece * self)
{
	// 0 Variables

	// 1 En fonction de la sym�trie de la pi�ce, on lui applique un traitement
	if(self->symetrie == SIMPLE)
		return;

	else if(self->symetrie == ROTATION_SEULE)
		pieceRotation(self);

	else if(self->symetrie == DEMI_ROTATION)
	{
		if(self->orientation == 0)
			pieceRotation(self);
		else
			pieceAntiRotation(self);
	}
	else if(self->symetrie == DEMI_COMPLET)
	{
		inversionPiece(self);
		if(self->inversion == 0)
		{
			if(self->orientation == 0)
				pieceRotation(self);
			else
				pieceAntiRotation(self);
		}
	}

	else
	{
		inversionPiece(self);
		if(self->inversion == 0)
			pieceRotation(self);
	}
}
void rotateThroughPiece(t_Piece * self)
{
	if(self->symetrie == ROTATION_SEULE)
		cycleThroughPiece(self);
	else if(self->symetrie == DEMI_ROTATION)
	{
		if(self->orientation == 0)
			pieceRotation(self);
		else
			pieceAntiRotation(self);
	}
	else
	{
		cycleThroughPiece(self);
		cycleThroughPiece(self);
	}
}
void antiRotateThroughPiece(t_Piece * self)
{
	for(int i = 0; i < 3; i++)
		rotateThroughPiece(self);
}
int n_rotations(t_Piece * self)
{
	// 0 Variables

	// 1 Tests pour traiter la demande en fonction de lma sym�trie de la pi�ce
	if(self->symetrie == SIMPLE)
		return 1;
	else if(self->symetrie == DEMI_ROTATION)
		return 2;
	else if(self->symetrie == DEMI_COMPLET || self->symetrie == ROTATION_SEULE)
		return 4;
	else if(self->symetrie == COMPLET)
		return 8;
	// Si on n'a pas trouv� de correspondance, on renvoit la valeur par d�faut
	return 8;
}

char isPiece(char symb)
{
	if(symb == SYMB_PIECE || symb == SYMB_PIECE_MORT)
		return 1;

	else return 0;
}
char isCoin(char symb)
{
	if(symb == SYMB_PIECE)
		return 1;

	else return 0;
}
