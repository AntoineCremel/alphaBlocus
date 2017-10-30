#include <stdio.h>
#include <stdlib.h>

#include "src/gameLoop.h"
#include "src/joueur.h"

int main()
{
    printf("Ceci est un test\n");

    t_Joueur test;

    joueurInitialisation(&test, "data/gameInit/stdPiecesList.txt");
    test.couleur = L_RED;
/*
    for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			printf("%c", test.ancre->grille[i][j]);
		}
		printf("\n");
	}

	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j=0; j < J_TAB_PIECE; j++)
		{
			printf("%c", test.ancre->precedent->grille[i][j]);
		}
		printf("\n");
	}*/


    affichageJoueurConsole(&test, 0, 0);

    changeColour(WHITE, BLACK);
    ///Ajouter le code du projet :-D
    return 0;
}
