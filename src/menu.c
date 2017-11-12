#include "menu.h"

/*
    Contient la définition des fonctions de fonctionnement et d'affichage sur console du menu.
*/


int menu_principal(char tab[10][20], int *lig, char *quitter)
{
    // Declaration des variables
    char dep;

    // Nettoyage de l'ecran pour afficher le menu
    system("CLS");

    // Affichage de BLOKUS avec modification des couleurs
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

    // Affichage des differents elements composants le menu principal avec leur couleur respective
    changeColour(11,0);
    printf("\n\n    Nouvelle Partie");
    changeColour(10,0);
    printf("\n\n    Charger partie");
    changeColour(14,0);
    printf("\n\n    Options");
    changeColour(12,0);
    printf("\n\n    Quitter le jeu\n\n");
    changeColour(7,0);
    printf( "(Z pour aller vers le haut, S pour aller vers le bas, SPACE pour selectionner)");

    // Affichage de la position initiale du curseur
    changeColour(7,0);
    gotoligcol(*lig,2);
    printf(">");

    // Boucle des différents deplacements du curseurs
    // Saisie de la touche
    while(!*quitter)
    {
        if(kbhit())
        {
            dep=getch();

    // Les differentes touches
			switch(dep)
			{

	// Aller vers le haut
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

    // Aller vers le bas
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

    // Selectionner
			case ' ' :
				if(*lig==2)
					return PLAY;
				if(*lig==4)
					return CHARGER;
				if(*lig==6)
					return OPTIONS;
				if(*lig==8)
					return QUITTER;
                break;
			}
        }
    }
    return MENU_P;
}

int menu_nouvelle_partie(char tab[10][20], int *lig, char *quitter)
{
    // Declaration des variables
    char dep;

    // Nettoyage de l'ecran pour afficher le menu
    system("CLS");

    // Affichage des differents elements composants le menu principal avec leur couleur respective
    changeColour(11,0);
    printf("       Nouvelle Partie       ");
    changeColour(7,0);
    printf("\n\n    Joueur vs Ordinateur");
    printf("\n\n    joueur VS Joueur");
    printf("\n\n    joueur VS Joueur VS Ordinateur");
    changeColour(12,0);
    printf("\n\n\   Retour");

    // Affichage de la position initiale du curseur
    changeColour(7,0);
    gotoligcol(*lig,2);
    printf(">");

    // Boucle des différents deplacements du curseurs
    // Saisie de la touche
    while(!*quitter)
    {
        if(kbhit())
        {
            dep=getch();

    // Les differentes touches
			switch(dep)
			{

    // Aller vers le haut
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

    // Aller vers le bas
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

    // Selectionner
			case ' ' :
				if(*lig==2)
				{
					return NOMBRE1;
				}
				if(*lig==4)
				{
					return NOMBRE2;
				}
				if(*lig==6)
				{
					return NOMBRE3;
				}
				if(*lig==8)
					return MENU_P;
				break;
			}
        }
    }
    return PLAY;
}

int menu_nombre_IA(char tab[10][20], int *lig, char *quitter)
{
    // Declaration des variables
    char dep;
    t_Partie game;

    // Nettoyage de l'ecran pour afficher le menu
    system("CLS");

    // Affichage des differents elements composants le menu principal avec leur couleur respective
    changeColour(11,0);
    printf("       Nombre d'adversaires       ");
    changeColour(7,0);
    printf("\n\n    1 adversaire");
    printf("\n\n    2 adversaires");
    printf("\n\n    3 adversaires");
    changeColour(12,0);
    printf("\n\n\   Retour");

    // Affichage de la position initiale du curseur
    changeColour(7,0);
    gotoligcol(*lig,2);
    printf(">");

    // Boucle des différents deplacements du curseurs
    // Saisie de la touche
    while(!*quitter)
    {
        if(kbhit())
        {
            dep=getch();

    // Les differentes touches
			switch(dep)
			{

    // Aller vers le haut
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

    // Aller vers le bas
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

    // Selectionner
			case ' ' :
				if(*lig==2)
				{
				    initialisationPartie(&game, 14, 14, PARTIE_STANDARD, 8, JOUEUR_HUMAIN, BLUE, 6, 6, JOUEUR_ALEATOIRE, YELLOW, 7, 7);
                    gameTurns(&game);
                    deinitialisationPartie(&game);
					return MENU_P;
				}
				if(*lig==4)
				{
				    initialisationPartie(&game, 20, 20, PARTIE_STANDARD, 12, JOUEUR_HUMAIN, BLUE, 0, 0, JOUEUR_ALEATOIRE, YELLOW, 0, 19, JOUEUR_ALEATOIRE, RED, 19, 10);
                    gameTurns(&game);
                    deinitialisationPartie(&game);

					initialisationPartie(&game, 14, 14, PARTIE_STANDARD, 8, JOUEUR_HUMAIN, RED, 5, 5, JOUEUR_ALEATOIRE, BLUE, 8, 8);
					gameTurns(&game);
					deinitialisationPartie(&game);
					return MENU_P;
				}
				if(*lig==6)
				{
				    initialisationPartie(&game, 20, 20, PARTIE_STANDARD, 16, JOUEUR_HUMAIN, BLUE, 0, 0, JOUEUR_ALEATOIRE, YELLOW, 0, 19, JOUEUR_ALEATOIRE, RED, 19, 19, JOUEUR_ALEATOIRE, GREEN, 19, 0);
                    gameTurns(&game);
                    deinitialisationPartie(&game);
					return MENU_P;
				}
				if(*lig==8)
					return MENU_P;
				break;
			}
        }
    }
    return NOMBRE1;
}

int menu_nombre_joueur(char tab[10][20], int *lig, char *quitter)
{
    // Declaration des variables
    char dep;
    t_Partie game;

    // Nettoyage de l'ecran pour afficher le menu
    system("CLS");

    // Affichage des differents elements composants le menu principal avec leur couleur respective
    changeColour(11,0);
    printf("       Nombre d'adversaires       ");
    changeColour(7,0);
    printf("\n\n    1 adversaire");
    printf("\n\n    2 adversaires");
    printf("\n\n    3 adversaires");
    changeColour(12,0);
    printf("\n\n\   Retour");

    // Affichage de la position initiale du curseur
    changeColour(7,0);
    gotoligcol(*lig,2);
    printf(">");

    // Boucle des différents deplacements du curseurs
    // Saisie de la touche
    while(!*quitter)
    {
        if(kbhit())
        {
            dep=getch();

    // Les differentes touches
			switch(dep)
			{

    // Aller vers le haut
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

    // Aller vers le bas
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

    // Selectionner
			case ' ' :
				if(*lig==2)
				{
				    initialisationPartie(&game, 14, 14, PARTIE_STANDARD, 8, JOUEUR_HUMAIN, BLUE, 6, 6, JOUEUR_HUMAIN, YELLOW, 7, 7);
                    gameTurns(&game);
                    deinitialisationPartie(&game);
					return MENU_P;
				}
				if(*lig==4)
				{
				    initialisationPartie(&game, 20, 20, PARTIE_STANDARD, 12, JOUEUR_HUMAIN, BLUE, 0, 0, JOUEUR_HUMAIN, YELLOW, 0, 19, JOUEUR_HUMAIN, RED, 19, 10);
                    gameTurns(&game);
                    deinitialisationPartie(&game);
					return MENU_P;
				}
				if(*lig==6)
				{
				    initialisationPartie(&game, 20, 20, PARTIE_STANDARD, 16, JOUEUR_HUMAIN, BLUE, 0, 0, JOUEUR_HUMAIN, YELLOW, 0, 19, JOUEUR_HUMAIN, RED, 19, 19, JOUEUR_HUMAIN, GREEN, 19, 0);
                    gameTurns(&game);
                    deinitialisationPartie(&game);
					return MENU_P;
				}
				if(*lig==8)
					return MENU_P;
				break;
			}
        }
    }
    return NOMBRE2;
}

int menu_nombre_joueur_IA(char tab[10][20], int *lig, char *quitter)
{
    // Declaration des variables
    char dep;
    t_Partie game;

    // Nettoyage de l'ecran pour afficher le menu
    system("CLS");

    // Affichage des differents elements composants le menu principal avec leur couleur respective
    changeColour(11,0);
    printf("       Nombre d'adversaires       ");
    changeColour(7,0);
    printf("\n\n    1 adversaire & 1 IA");
    printf("\n\n    2 adversaires & 1 IA");
    printf("\n\n    1 adversaire & 2 IA");
    changeColour(12,0);
    printf("\n\n\   Retour");

    // Affichage de la position initiale du curseur
    changeColour(7,0);
    gotoligcol(*lig,2);
    printf(">");

    // Boucle des différents deplacements du curseurs
    // Saisie de la touche
    while(!*quitter)
    {
        if(kbhit())
        {
            dep=getch();

    // Les differentes touches
			switch(dep)
			{

    // Aller vers le haut
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

    // Aller vers le bas
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

    // Selectionner
			case ' ' :
				if(*lig==2)
				{
				    initialisationPartie(&game, 20, 20, PARTIE_STANDARD, 12, JOUEUR_HUMAIN, BLUE, 0, 0, JOUEUR_HUMAIN, YELLOW, 0, 19, JOUEUR_ALEATOIRE, RED, 19, 10);
                    gameTurns(&game);
                    deinitialisationPartie(&game);
					return MENU_P;
				}
				if(*lig==4)
				{
				    initialisationPartie(&game, 20, 20, PARTIE_STANDARD, 16, JOUEUR_HUMAIN, BLUE, 0, 0, JOUEUR_HUMAIN, YELLOW, 0, 19, JOUEUR_HUMAIN, RED, 19, 19, JOUEUR_ALEATOIRE, GREEN, 19, 0);
                    gameTurns(&game);
                    deinitialisationPartie(&game);
					return MENU_P;
				}
				if(*lig==6)
				{
				    initialisationPartie(&game, 20, 20, PARTIE_STANDARD, 16, JOUEUR_HUMAIN, BLUE, 0, 0, JOUEUR_HUMAIN, YELLOW, 0, 19, JOUEUR_ALEATOIRE, RED, 19, 19, JOUEUR_ALEATOIRE, GREEN, 19, 0);
                    gameTurns(&game);
                    deinitialisationPartie(&game);
					return MENU_P;
				}
				if(*lig==8)
					return MENU_P;
				break;
			}
        }
    }
    return NOMBRE3;
}

int menu_charger_partie(char tab[10][20], int *lig, char *quitter)
{
    // Declaration des variables
    char dep;

    // Nettoyage de l'ecran pour afficher le menu
    system("CLS");

    // Affichage des differents elements composants le menu principal avec leur couleur respective
    changeColour(10,0);
    printf("       Charger Partie       ");
    changeColour(7,0);
    printf("\n\n    1.Emplacement vide");
    printf("\n\n    2.Emplacement vide");
    printf("\n\n    3.Emplacement vide");
    changeColour(12,0);
    printf("\n\n    Retour");

    // Affichage de la position initiale du curseur
    changeColour(7,0);
    gotoligcol(*lig,2);
    printf(">");

    // Boucle des différents deplacements du curseurs
    // Saisie de la touche
    while(!*quitter)
    {
        if(kbhit())
        {
            dep=getch();

    // Les differentes touches
			switch(dep)
			{

    // Aller vers le haut
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

    // Aller vers le bas
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

    // Selectionner
			case ' ' :
				if(*lig==2)
                {

                }
				if(*lig==4)
                {

                }
				if(*lig==6)
                {

                }
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
    // Declaration des variables
    char dep;
    FILE * regle = NULL;

    // Nettoyage de l'ecran pour afficher le menu
    system("CLS");

    // Affichage des differents elements composants le menu principal avec leur couleur respective
    changeColour(14,0);
    printf("       Options       ");
    changeColour(7,0);
    printf("\n\n    Regles");
    printf("\n\n    Reconfiguration des touches");
    changeColour(12,0);
    printf("\n\n\n\n    Retour");

    // Affichage de la position initiale du curseur
    changeColour(7,0);
    gotoligcol(*lig,2);
    printf(">");

    // Boucle des différents deplacements du curseurs
    // Saisie de la touche
    while(!*quitter)
    {
        if(kbhit())
        {
            dep=getch();

    // Les differentes touches
			switch(dep)
			{

    // Aller vers le haut
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
				    if(*lig==8)
				    {
				        gotoligcol(*lig,2);
                        printf(" ");
                        *lig=4;
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
				}
				break;

    // Aller vers le bas
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
				    if(*lig==4)
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
                        *lig=*lig+2;
                        gotoligcol(*lig,2);
                        printf(">");
                    }
				}
				break;

    // Selectionner
			case ' ' :
				if(*lig==2)
                {
                    regle = fopen("data/regle.txt", "r+");
                    if (regle != NULL)
                    {
                        fgetc(regle);
                    }
                    else
                    {
                    printf(" Impossible d'ouvrir le regle regle.txt");
                    }
                }
				if(*lig==4)
                {

                }
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
    // Declaration des variables
    char choix=MENU_P;
    char tab[10][20];
    int lig=2;
    char quitter=0;

    // Boucle pour pouvoir passer de menu en menu sans problème au niveau des retours
    while(choix!=QUITTER)
    {
        if(choix==MENU_P)
            choix=menu_principal(tab, &lig, &quitter);
        if(choix==PLAY)
            choix=menu_nouvelle_partie(tab, &lig, &quitter);
        if(choix==NOMBRE1)
            choix=menu_nombre_IA(tab, &lig, &quitter);
        if(choix==NOMBRE2)
            choix=menu_nombre_joueur(tab, &lig, &quitter);
        if(choix==NOMBRE3)
            choix=menu_nombre_joueur_IA(tab, &lig, &quitter);
        if(choix==CHARGER)
            choix=menu_charger_partie(tab, &lig, &quitter);
        if(choix==OPTIONS)
            choix=menu_options(tab, &lig, &quitter);
    }
}
