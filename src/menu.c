#include "menu.h"

/*
    Contient la définition des fonctions de fonctionnement et d'affichage sur console du menu.
*/

void curseur(int *lig)
{
    char dep;
    t_Partie game;
    char tab[10][20];
    char quitter=0;

    menu_principal(tab);

    gotoligcol(*lig,2);
    printf(">");

    while(!quitter)
        {
            if(kbhit)
            {
                dep=getch();
            }
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
                    initialisationPartie(&game, 14, 14, PARTIE_STANDARD, 8, JOUEUR_HUMAIN, RED, 6, 6, JOUEUR_HUMAIN, BLUE, 7, 7);
                    printf("Initialisation faite\n");

                    gameTurns(&game);

                    deinitialisationPartie(&game);
                }
                if(*lig==4)
                    menu_charger_partie(tab);
                if(*lig==6)
                    menu_options(tab);
                if(*lig==8)
                    quitter=1;
                break;
            }
        }
}

void menu_principal(char tab[10][20])
{
    system("CLS");
    changeColour(3,0);
    printf("          B");
    changeColour(2,0);
    printf("L");
    changeColour(14,0);
    printf("O");
    changeColour(12,0);
    printf("K");
    changeColour(3,0);
    printf("U");
    changeColour(14,0);
    printf("S          ");
    changeColour(7,0);
    printf("\n\n    Nouvelle Partie");
    printf("\n\n    Charger partie");
    printf("\n\n    Options");
    printf("\n\n    Quitter le jeu\n\n");
}

void menu_charger_partie(char tab[10][20])
{
    system("CLS");
    printf("    Charger Partie    ");
    printf("\n\n    1.Emplacement vide");
    printf("\n\n    2.Emplacement vide");
    printf("\n\n    3.Emplacement vide");
    printf("\n\n    Retour");
}

void menu_options(char tab[10][20])
{
    system("CLS");
    printf("       Options       ");

    printf("\n\n    Retour");
}
