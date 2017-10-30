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

void affichageGame(t_Partie * game, t_Controles * touches)
{

}

void affichagePieceScrollConsole(t_Piece * self, int lig, int col, int colour)
{
	/*
	Pour cet affichage j'ai choisi de mettre simplement un espace ayant comme
	couleur d'arrière plan la couleur du joueur
	*/
	// 0 Variables


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
		scrollToSuivant(self);
	}

	// 3 On scroll pour revenir à l'ancre de départ
	for(int i=0; i < PIECES_A_AFFICHER_AU_DESSOUS; i++)
		scrollToPrecedent(self);
}
