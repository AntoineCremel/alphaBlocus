#include "affichageConsole.h"

/*
    Contient toutes les fonctions nécessaires à l'affichage de la partie sur console.
    Ces fonctions sont appellent les affichages de chaque structure et les place aux bons endroits grâce à des gotoligcol appropriés.
*/


void gotoligcol( int lig, int col )
{
    /*
        Fonction donnée par le professeur.
    */
    COORD mycoord;

    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void changeColour(int letters, int backGround)
{
	// 0 Variables
	HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h_console, letters + 16 * backGround);
}

void affichageGame(t_Partie * game)
{
	// 0 Variables

	// 1 On affiche la grille
	affichageConsoleGrilleDeJeu(game, I_PLACE_GRID, J_PLACE_GRID);

	// 2 On affiche la zone de scroll
	affichageJoueurConsole(&game->joueurListe[game->joueurActif], I_PLACE_SCROLL, J_PLACE_SCROLL);

	// En fin d'exécution, on place le curseur à un endroit nul pou qu'il ne nous gêne pas
	gotoligcol(0, 0);
}

void affichagePieceScrollConsole(t_Piece * self, int lig, int col, int colour)
{
	/*
	Pour cet affichage j'ai choisi de mettre simplement un espace ayant comme
	couleur d'arrière plan la couleur du joueur
	*/
	// 0 Variables

	// 1 On vérifie que la pièce existe
	if(self == NULL)
		return;

	// 2 Boucle d'affichage
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			if(self->grille[i][j] == SYMB_PIECE)
			{

				// Affichage a partir du centre
				gotoligcol(lig - (I_TAB_PIECE-1)/2 + i, W_SQUARE_SCROLL*(col - (J_TAB_PIECE-1) + j));
				changeColour(0, colour);

				for(int k=0; k < W_SQUARE_SCROLL; k++)
					printf(" ");
			}
		}
	}
}

void affichageConsoleControles(t_Controles * self, int lig, int col)
{

}

void affichageConsoleGrilleDeJeu(t_Partie * self, int lig, int col)
{
	// 0 Variables

	// 1 Double boucle parcourant la grille de jeu pour afficher chaque pièce qui se trouve dessus
	for(int i=0; i < self->h_grid; i++)
	{
		for(int j=0; j < self->w_grid; j++)
		{
			if(self->grille[i][j] == CASE_VIDE)
			{
				gotoligcol(lig + i, col + j * W_SQUARE);
				changeColour(0, GRID_BACK_COLOUR);
				for(int k=0; k < W_SQUARE; k++)
					printf(" ");
			}
			else
			{
				gotoligcol(lig + i, col + j * W_SQUARE);
				changeColour(0, self->joueurListe[(int)self->grille[i][j]].couleur);
				for(int k=0; k < W_SQUARE; k++)
					printf(" ");
			}
		}
	}
	affichageConsoleCurseur(self, lig, col);
}
void affichageConsoleCurseur(t_Partie * self, int lig, int col)
{
	// 0 Variables
	int i_gameGrid;
	int j_gameGrid;

	// Dans le cas où il n'y pas de pièce à placer, on ne fait rien
	if(self->joueurListe[self->joueurActif].ancre == NULL)
		return;

	// 1 Double boucle pour placer le curseur a l'endroit correspondant
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			if(self->joueurListe[self->joueurActif].ancre->grille[i][j] == SYMB_PIECE)
			{
				// 1.0 On détermine à quelle case de la grille est censée se trouver cette case du curseur
				i_gameGrid = self->joueurListe[self->joueurActif].curs_lig + i + I_CENTRE_PIECE;
				j_gameGrid = self->joueurListe[self->joueurActif].curs_col + j + J_CENTRE_PIECE;

				//1.1 On se place à cet endroit
				gotoligcol(lig + i_gameGrid, col + j_gameGrid * W_SQUARE);

				// 1.2 On détermine ce qu'il faut afficher en fonction de ce qui se trouve déjà sur la grille
				if(self->grille[i_gameGrid][j_gameGrid] == CASE_VIDE)
				{
					// 1.2.0 Dans le cas où la case en dessous est vide, on affiche un o
					changeColour(self->joueurListe[self->joueurActif].couleur, GRID_BACK_COLOUR);
					for(int k=0; k < W_SQUARE; k++)
					printf("%c", SKIN_CURSEUR_VIDE);
				}
				else if(self->grille[i_gameGrid][j_gameGrid] == self->joueurActif)
				{
					//1.2.1 Dans le cas où la case en dessous est occupé par une pièce du joueur actif,
					// on doit mettre une couleur de police particulière pour bien voir
					changeColour(FONT_SAME_FRONT, self->joueurListe[self->joueurActif].couleur);
					for(int k=0; k < W_SQUARE; k++)
					printf("%c", SKIN_CURSEUR_INTERDIT);
				}
				else
				{
					changeColour(self->joueurListe[self->joueurActif].couleur,
									self->joueurListe[(int)self->grille[i_gameGrid][j_gameGrid]].couleur);
					for(int k=0; k < W_SQUARE; k++)
					printf("%c", SKIN_CURSEUR_INTERDIT);
				}
			}
		}
	}
}

void affichageJoueurConsole(t_Joueur * self, int lig, int col)
{
	/*
		Pour cette fonction j'ai choisi un affichage qui montre
		la pièce active ainsi que deux pièces "au-dessus" et deux
		pièces "en-dessous"
	*/
	// 0 Variables
	// 0.0 On initialise ligne actuelle et col actuelle aux endroits où l'on veut
	// 		commencer la fonction
	int ligActuelle = lig + (I_TAB_PIECE-1)/2;
	int colActuelle = col + J_TAB_PIECE;

	// 1 On commence par colorer une zone taille fixe
	for(int i=0; i < (I_TAB_PIECE + LINES_BETWEEN_PIECES_IN_SCROLL) * (PIECES_A_AFFICHER_AU_DESSUS + 1 + PIECES_A_AFFICHER_AU_DESSOUS); i++)
	{
		for(int j=0; j < J_TAB_PIECE * W_SQUARE_SCROLL; j++)
		{
			gotoligcol(lig + i, W_SQUARE_SCROLL * (col + j));
			changeColour(0, SCROLL_BACK_COLOUR);
			for(int k=0; k < W_SQUARE_SCROLL; k++)
				printf(" ");
		}
	}

	// 2 Affichage des deux pièces au-dessus
	// 2.0 On scroll à travers la liste de chainee de joueur pour se mettre deux pieces plus haut
	for(int i=0; i < PIECES_A_AFFICHER_AU_DESSUS; i++)
		scrollToPrecedent(self);

	// 2.1 Ensuite on affiche le nombre de pièces voulues
	for(int i=0; i < PIECES_A_AFFICHER_AU_DESSUS + 1 + PIECES_A_AFFICHER_AU_DESSOUS; i++)
	{
		// 2.1.0 On affiche la pièce en cours
		affichagePieceScrollConsole(self->ancre, ligActuelle, colActuelle, self->couleur);
		//	2.1.1 On se met en place pour afficher la pièce suivante
		ligActuelle += LINES_BETWEEN_PIECES_IN_SCROLL + I_TAB_PIECE;
		colActuelle = col + J_TAB_PIECE;
		//	2.1.2 On scroll à travers la liste de pièces
		if(i != PIECES_A_AFFICHER_AU_DESSUS + PIECES_A_AFFICHER_AU_DESSOUS)
			scrollToSuivant(self);
	}

	// 3 On scroll pour revenir à l'ancre de départ
	for(int i=0; i < PIECES_A_AFFICHER_AU_DESSOUS; i++)
		scrollToPrecedent(self);
}
