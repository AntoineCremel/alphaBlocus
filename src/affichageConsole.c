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
