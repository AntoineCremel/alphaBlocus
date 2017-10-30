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

void affichagePieceScrollConsole(t_Piece * self, int * lig, int * col, int colour)
{
	/*
	Pour cet affichage j'ai choisi de mettre simplement un espace ayant comme
	couleur d'arrière plan la couleur du joueur
	*/
	// 0 Variables
	int lig_max = 0;
	int col_max = 0;
	int lig_min = I_TAB_PIECE;
	int col_min = J_TAB_PIECE;

	// 1 On trouve les dimensions de lig_min et col_min
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			if(self->grille[i][j] == SYMB_PIECE)
			{
				if(i < lig_min)
					lig_min = i;
				if(j < col_min)
					col_min = j;
			}
		}
	}

	// 2 Boucle d'affichage
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			if(self->grille[i][j] == SYMB_PIECE)
			{
				gotoligcol(*lig + i - lig_min, *col + j - col_min);
				changeColour(0, colour);
				printf(" ");

				// On met à jour lig_max et col_max pour savoir quels sont les
				// dimensions de la pièce que l'on affiche
				if(i > lig_max)
					lig_max = i;
				if(j > col_max)
					col_max = j;
			}
		}
	}

	// 2 On met à jour lig et col pour que la fonction qui a appelé sache où l'on s'est arrété
	*lig += lig_max - lig_min + 1;
	*col += col_max - col_min + 1;
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
	int ligActuelle = lig;
	int colActuelle = col;

	// 1 On scroll à travers la liste de chainee de joueur pour se mettre deux pieces plus haut
	for(int i=0; i < PIECES_A_AFFICHER_AU_DESSUS; i++)
		scrollToPrecedent(self);

	// 2 Ensuite on affiche le nombre de pièces voulues
	for(int i=0; i < PIECES_A_AFFICHER_AU_DESSUS + 1 + PIECES_A_AFFICHER_AU_DESSOUS; i++)
	{
		// 2.0 On affiche la pièce en cours
		affichagePieceScrollConsole(self->ancre, &ligActuelle, &colActuelle, self->couleur);
		//	2.1 On se met en place pour afficher la pièce suivante
		ligActuelle += LINES_BETWEEN_PIECES_IN_SCROLL;
		colActuelle = col;
		//	2.2 On scroll à travers la liste de pièces
		scrollToSuivant(self);
	}

	// 3 On remet l'ancre sur son point de départ
	for(int i=0; i < PIECES_A_AFFICHER_AU_DESSOUS; i++)
		scrollToPrecedent(self);
}
