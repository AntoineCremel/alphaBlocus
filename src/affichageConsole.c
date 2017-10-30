#include "affichageConsole.h"

/*
    Contient toutes les fonctions n�cessaires � l'affichage de la partie sur console.
    Ces fonctions sont appellent les affichages de chaque structure et les place aux bons endroits gr�ce � des gotoligcol appropri�s.
*/


void gotoligcol( int lig, int col )
{
    /*
        Fonction donn�e par le professeur.
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
	couleur d'arri�re plan la couleur du joueur
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

				// On met � jour lig_max et col_max pour savoir quels sont les
				// dimensions de la pi�ce que l'on affiche
				if(i > lig_max)
					lig_max = i;
				if(j > col_max)
					col_max = j;
			}
		}
	}

	// 2 On met � jour lig et col pour que la fonction qui a appel� sache o� l'on s'est arr�t�
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
		la pi�ce active ainsi que deux pi�ces "au-dessus" et deux
		pi�ces "en-dessous"
	*/
	// 0 Variables
	// 0.0 On initialise ligne actuelle et col actuelle aux endroits o� l'on veut
	// 		commencer la fonction
	int ligActuelle = lig;
	int colActuelle = col;

	// 1 On scroll � travers la liste de chainee de joueur pour se mettre deux pieces plus haut
	for(int i=0; i < PIECES_A_AFFICHER_AU_DESSUS; i++)
		scrollToPrecedent(self);

	// 2 Ensuite on affiche le nombre de pi�ces voulues
	for(int i=0; i < PIECES_A_AFFICHER_AU_DESSUS + 1 + PIECES_A_AFFICHER_AU_DESSOUS; i++)
	{
		// 2.0 On affiche la pi�ce en cours
		affichagePieceScrollConsole(self->ancre, &ligActuelle, &colActuelle, self->couleur);
		//	2.1 On se met en place pour afficher la pi�ce suivante
		ligActuelle += LINES_BETWEEN_PIECES_IN_SCROLL;
		colActuelle = col;
		//	2.2 On scroll � travers la liste de pi�ces
		scrollToSuivant(self);
	}

	// 3 On remet l'ancre sur son point de d�part
	for(int i=0; i < PIECES_A_AFFICHER_AU_DESSOUS; i++)
		scrollToPrecedent(self);
}
