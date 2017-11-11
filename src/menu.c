#include "menu.h"

/*
    Contient la définition des fonctions de fonctionnement et d'affichage sur console du menu.
*/


int menu_principal(char tab[10][20], int *lig, char *quitter)
{
    char dep;

    system("CLS");
    changeColour(11,0);
    printf("          B");
    changeColour(10,0);
    printf("L");
    changeColour(14,0);
    printf("O");
    changeColour(12,0);
    printf("K");
    changeColour(11,0);
    printf("U");
    changeColour(14,0);
    printf("S          ");
    changeColour(11,0);
    printf("\n\n    Nouvelle Partie");
    changeColour(10,0);
    printf("\n\n    Charger partie");
    changeColour(14,0);
    printf("\n\n    Options");
    changeColour(12,0);
    printf("\n\n    Quitter le jeu\n\n");

    changeColour(7,0);
    gotoligcol(*lig,2);
    printf(">");

    while(!*quitter)
    {
        if(kbhit())
        {
            dep=getch();

			switch(dep)
			{
			case 'z' :
				if(*lig==2)
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=8;
					gotoligcol(*lig,2);
					printf(">");
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig-2;
					gotoligcol(*lig,2);
					printf(">");
				}
				break;
			case 's' :
				if(*lig==8)
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=2;
					gotoligcol(*lig,2);
					printf(">");
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig+2;
					gotoligcol(*lig,2);
					printf(">");
				}
				break;
			case ' ' :
				if(*lig==2)
					return PLAY;
				if(*lig==4)
					return CHARGER;
				if(*lig==6)
					return OPTIONS;
				if(*lig==8)
					*quitter=1;
				break;
			}
        }
    }
    return MENU_P;
}

int menu_nouvelle_partie(char tab[10][20], int *lig, char *quitter)
{
    char dep;
    t_Partie game;

    system("CLS");
    changeColour(11,0);
    printf("       Nouvelle Partie       ");
    changeColour(7,0);
    printf("\n\n    Tests");
    printf("\n\n    joueur VS joueur");
    printf("\n\n    4 joueurs");
    changeColour(12,0);
    printf("\n\n    Retour");

    changeColour(7,0);
    gotoligcol(*lig,2);
    printf(">");

    while(!*quitter)
    {
        if(kbhit())
        {
            dep=getch();
			switch(dep)
			{
			case 'z' :
				if(*lig==2)
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=8;
					gotoligcol(*lig,2);
					printf(">");
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig-2;
					gotoligcol(*lig,2);
					printf(">");
				}
				break;
			case 's' :
				if(*lig==8)
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=2;
					gotoligcol(*lig,2);
					printf(">");
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig+2;
					gotoligcol(*lig,2);
					printf(">");
				}
				break;
			case ' ' :
				if(*lig==2)
				{
					initialisationPartie(&game, 3, 3, PARTIE_STANDARD, 4, JOUEUR_HUMAIN, RED, 0, 0);
					gameTurns(&game);
					deinitialisationPartie(&game);
				}
				if(*lig==4)
				{
					initialisationPartie(&game, 14, 14, PARTIE_STANDARD, 8, JOUEUR_HUMAIN, RED, 6, 6, JOUEUR_HUMAIN, BLUE, 7, 7);
					gameTurns(&game);
					deinitialisationPartie(&game);
				}
				if(*lig==6)
				{
					initialisationPartie(&game, 20, 20, PARTIE_STANDARD, 16, JOUEUR_HUMAIN, RED, 0, 0, JOUEUR_HUMAIN, BLUE, 0, 19, JOUEUR_HUMAIN, GREEN, 19, 19, JOUEUR_HUMAIN, YELLOW, 19, 0);
					gameTurns(&game);
					deinitialisationPartie(&game);
				}
				if(*lig==8)
					return MENU_P;
				break;
			}
        }
    }
    return PLAY;
}

int menu_charger_partie(char tab[10][20], int *lig, char *quitter)
{
    char dep;

    system("CLS");
    changeColour(10,0);
    printf("       Charger Partie       ");
    changeColour(7,0);
    printf("\n\n    1.Emplacement vide");
    printf("\n\n    2.Emplacement vide");
    printf("\n\n    3.Emplacement vide");
    changeColour(12,0);
    printf("\n\n    Retour");

    changeColour(7,0);
    gotoligcol(*lig,2);
    printf(">");

    while(!*quitter)
    {
        if(kbhit())
        {
            dep=getch();

			switch(dep)
			{
			case 'z' :
				if(*lig==2)
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=8;
					gotoligcol(*lig,2);
					printf(">");
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig-2;
					gotoligcol(*lig,2);
					printf(">");
				}
				break;
			case 's' :
				if(*lig==8)
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=2;
					gotoligcol(*lig,2);
					printf(">");
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig+2;
					gotoligcol(*lig,2);
					printf(">");
				}
				break;
			case ' ' :
				//if(*lig==2)
				//if(*lig==4)
				//if(*lig==6)
				if(*lig==8)
					return MENU_P;
				break;
			}
        }
    }
    return CHARGER;
}

int menu_options(char tab[10][20], int *lig, char *quitter)
{
    char dep;

    system("CLS");
    changeColour(14,0);
    printf("       Options       ");
    changeColour(7,0);
    printf("\n\n    Regles");
    printf("\n\n    Reconfiguration des touches");
    changeColour(12,0);
    printf("\n\n\n\n    Retour");

    changeColour(7,0);
    gotoligcol(*lig,2);
    printf(">");

    while(!*quitter)
    {
        if(kbhit())
        {
            dep=getch();

			switch(dep)
			{
			case 'z' :
				if(*lig==2)
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=8;
					gotoligcol(*lig,2);
					printf(">");
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig-2;
					gotoligcol(*lig,2);
					printf(">");
				}
				break;
			case 's' :
				if(*lig==8)
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=2;
					gotoligcol(*lig,2);
					printf(">");
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig+2;
					gotoligcol(*lig,2);
					printf(">");
				}
				break;
			case ' ' :
				//if(*lig==2)
				//if(*lig==4)
				//if(*lig==6)
				if(*lig==8)
					return MENU_P;
				break;
			}
        }
    }
    return OPTIONS;
}

void superLoop()
{
    char choix=MENU_P;
    char tab[10][20];
    int lig=2;
    char quitter=0;

    while(choix!=QUITTER)
    {
        if(choix==MENU_P)
            choix=menu_principal(tab, &lig, &quitter);
        if(choix==PLAY)
            choix=menu_nouvelle_partie(tab, &lig, &quitter);
        if(choix==CHARGER)
            choix=menu_charger_partie(tab, &lig, &quitter);
        if(choix==OPTIONS)
            choix=menu_options(tab, &lig, &quitter);
        if(choix==QUITTER)
            break;
    }
}
