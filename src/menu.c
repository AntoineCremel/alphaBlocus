#include "mainHeader.h"
#include "menu.h"

/*
    Contient la définition des fonctions de fonctionnement et d'affichage sur console du menu.
*/

void effacement(char tab[10][20])
{
    int i, j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<20;j++)
            tab[i][j]=' ';
            printf("%c",tab[i][j]);
    }
    printf("\n");
}

void curseur(int *lig)
{
    char dep;

    gotoligcol(lig,2);
    printf(">");
    if (kbhit())
        {
            dep=getch();
        }

    switch(dep)
    {
    case 'z' :
        if(*lig==2)
        {
            *lig=8;
            gotoligcol(*lig,2);
            printf(" ");
            *lig=*lig-2;
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
            *lig=2;
            gotoligcol(*lig,2);
            printf(" ");
            *lig=*lig+2;
            gotoligcol(*lig,2);
            printf(">");
        }
        else
        {
            gotoligcol(*lig,2);
            printf(" ");
            *lig=*lig+2;
            gotoligcol(*lig+2,2);
            printf(">");
        }
        break;
    }
}

void menu_principal(char tab[10][20])
{
    effacement(tab);
    changeColour(3,0);
    printf("       B");
    changeColour(2,0);
    printf("L");
    changeColour(14,0);
    printf("O");
    changeColour(12,0);
    printf("K");
    changeColour(3,0);
    printf("U");
    changeColour(14,0);
    printf("S       ");
    changeColour(7,0);
    printf("\n\n   Nouvelle Partie");
    printf("\n\n   Charger partie");
    printf("\n\n   Options");
    printf("\n\n   Quitter le jeu");
}

void menu_charger_partie(char tab[10][20])
{
    effacement(tab);
    printf("    Charger Partie    ");
    printf("\n\n 1.Emplacement vide");
    printf("\n\n 2.Emplacement vide");
    printf("\n\n 3.Emplacement vide");
    printf("\n\n Retour");
}

void menu_options(char tab[10][20])
{
    effacement(tab);
    printf("    Options    ");

    printf("\n\n Retour");
}

void choix_menu(char tab[10][20], int *lig)
{
    char val;

    menu_principal(tab);
    curseur(lig);

    if (kbhit())
    {
        val=getch();
    }
    switch(val)
    {
    case ' ' :
        if(*lig==2)
        {
            initialisationPartie(&game, 14, 14, PARTIE_STANDARD, 8, JOUEUR_HUMAIN, RED, 6, 6, JOUEUR_HUMAIN, BLUE, 7, 7);

            printf("Initialisation faite\n");
        }
        if(*lig==4)
            menu_charger_partie(tab);
        if(*lig==6)
            menu_options(tab);
        if(*lig==8)
            break;
        break;
    }
}
