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
    changeColour(L_AQUA,BLACK);
    printf("          B");
    changeColour(L_YELLOW,BLACK);
    printf("L");
    changeColour(L_RED,BLACK);
    printf("O");
    changeColour(L_GREEN,BLACK);
    printf("K");
    changeColour(L_AQUA,BLACK);
    printf("U");
    changeColour(L_YELLOW,BLACK);
    printf("S          ");

    // Affichage des differents elements composants le menu principal avec leur couleur respective
    changeColour(L_AQUA,BLACK);
    printf("\n\n    Nouvelle Partie");
    changeColour(L_GREEN,BLACK);
    printf("\n\n    Charger partie");
    changeColour(L_YELLOW,BLACK);
    printf("\n\n    Options");
    changeColour(L_RED,BLACK);
    printf("\n\n    Quitter le jeu\n\n");
    changeColour(WHITE,BLACK);
    printf( "(Z pour aller vers le haut, S pour aller vers le bas, SPACE pour selectionner)");

    // Affichage de la position initiale du curseur
    changeColour(WHITE,BLACK);
    gotoligcol(*lig,2);
    printf(">");
    gotoligcol(10,78);

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
					gotoligcol(10,78);
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig-2;
					gotoligcol(*lig,2);
					printf(">");
					gotoligcol(10,78);
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
					gotoligcol(10,78);
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig+2;
					gotoligcol(*lig,2);
					printf(">");
					gotoligcol(10,78);
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
    changeColour(L_AQUA,BLACK);
    printf("       Nouvelle Partie       ");
    changeColour(L_YELLOW,BLACK);
    printf("\n\n    Joueur vs Ordinateur");
    printf("\n\n    joueur VS Joueur");
    printf("\n\n    joueur VS Joueur VS Ordinateur");
    changeColour(L_RED,BLACK);
    printf("\n\n    Retour");

    // Affichage de la position initiale du curseur
    changeColour(WHITE,BLACK);
    gotoligcol(*lig,2);
    printf(">");
    gotoligcol(8,10);

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
					gotoligcol(8,10);
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig-2;
					gotoligcol(*lig,2);
					printf(">");
					gotoligcol(8,10);
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
					gotoligcol(8,10);
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig+2;
					gotoligcol(*lig,2);
					printf(">");
					gotoligcol(8,10);
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
    changeColour(L_AQUA,BLACK);
    printf("       Nombre d'adversaires       ");
    changeColour(L_GREEN,BLACK);
    printf("\n\n    1 adversaire");
    printf("\n\n    2 adversaires");
    printf("\n\n    3 adversaires");
    changeColour(L_RED,BLACK);
    printf("\n\n    Retour");

    // Affichage de la position initiale du curseur
    changeColour(WHITE,BLACK);
    gotoligcol(*lig,2);
    printf(">");
    gotoligcol(8,10);

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
					gotoligcol(8,10);
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig-2;
					gotoligcol(*lig,2);
					printf(">");
					gotoligcol(8,10);
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
					gotoligcol(8,10);
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig+2;
					gotoligcol(*lig,2);
					printf(">");
					gotoligcol(8,10);
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
					return PLAY;
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
    changeColour(L_AQUA,BLACK);
    printf("       Nombre d'adversaires       ");
    changeColour(L_GREEN,BLACK);
    printf("\n\n    1 adversaire");
    printf("\n\n    2 adversaires");
    printf("\n\n    3 adversaires");
    changeColour(L_RED,BLACK);
    printf("\n\n    Retour");

    // Affichage de la position initiale du curseur
    changeColour(WHITE,BLACK);
    gotoligcol(*lig,2);
    printf(">");
    gotoligcol(8,10);

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
					gotoligcol(8,10);
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig-2;
					gotoligcol(*lig,2);
					printf(">");
					gotoligcol(8,10);
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
					gotoligcol(8,10);
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig+2;
					gotoligcol(*lig,2);
					printf(">");
					gotoligcol(8,10);
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
					return PLAY;
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
    changeColour(L_AQUA,BLACK);
    printf("       Nombre d'adversaires       ");
    changeColour(L_GREEN,BLACK);
    printf("\n\n    1 adversaire & 1 IA");
    printf("\n\n    2 adversaires & 1 IA");
    printf("\n\n    1 adversaire & 2 IA");
    changeColour(L_RED,BLACK);
    printf("\n\n    Retour");

    // Affichage de la position initiale du curseur
    changeColour(WHITE,BLACK);
    gotoligcol(*lig,2);
    printf(">");
    gotoligcol(8,10);

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
					gotoligcol(8,10);
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig-2;
					gotoligcol(*lig,2);
					printf(">");
					gotoligcol(8,10);
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
					gotoligcol(8,10);
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig+2;
					gotoligcol(*lig,2);
					printf(">");
					gotoligcol(8,10);
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
					return PLAY;
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
    changeColour(L_GREEN,BLACK);
    printf("       Charger Partie       ");
    changeColour(L_YELLOW,BLACK);
    printf("\n\n    1.Sauvegarde 1");
    printf("\n\n    2.Sauvegarde 2");
    printf("\n\n    3.Sauvegarde 3");
    changeColour(L_RED,BLACK);
    printf("\n\n    Retour");

    // Affichage de la position initiale du curseur
    changeColour(WHITE,BLACK);
    gotoligcol(*lig,2);
    printf(">");
    gotoligcol(8,10);

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
					gotoligcol(8,10);
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig-2;
					gotoligcol(*lig,2);
					printf(">");
					gotoligcol(8,10);
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
					gotoligcol(8,10);
				}
				else
				{
					gotoligcol(*lig,2);
					printf(" ");
					*lig=*lig+2;
					gotoligcol(*lig,2);
					printf(">");
					gotoligcol(8,10);
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
    changeColour(L_YELLOW,BLACK);
    printf("       Options       ");
    changeColour(L_GREEN,BLACK);
    printf("\n\n    Regles");
    printf("\n\n    Reconfiguration des touches");
    changeColour(L_RED,BLACK);
    printf("\n\n\n\n    Retour");

    // Affichage de la position initiale du curseur
    changeColour(WHITE,BLACK);
    gotoligcol(*lig,2);
    printf(">");
    gotoligcol(8,10);

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
					gotoligcol(8,10);
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
                        gotoligcol(8,10);
				    }
				    else
                    {
                        gotoligcol(*lig,2);
                        printf(" ");
                        *lig=*lig-2;
                        gotoligcol(*lig,2);
                        printf(">");
                        gotoligcol(8,10);
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
					gotoligcol(8,10);
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
                        gotoligcol(8,10);
				    }
				    else
                    {
                        gotoligcol(*lig,2);
                        printf(" ");
                        *lig=*lig+2;
                        gotoligcol(*lig,2);
                        printf(">");
                        gotoligcol(8,10);
                    }
				}
				break;

    // Selectionner
			case ' ' :
				if(*lig==2)
                {
                    system("CLS");
                    regle = fopen("data/regles.txt", "r");
                    if(regle == NULL)
                    {
                        printf("Impossible d'acceder au regle");
                    }
                    else
                    {
                        while(!feof(regle))
                        {
                            printf("%c",fgetc(regle));
                        }
                        while(!*quitter)
                        {
                            if(kbhit())
                            {
                                dep=getch();
                                switch(dep)
                            {
                            case ' ' :
                                fclose(regle);
                                return OPTIONS;
                                break;
                            }
                            }

                        }
                    }
                }
				if(*lig==4)
                {
                    return TOUCHE;
                }
				if(*lig==8)
					return MENU_P;
				break;
			}
        }
    }
    return OPTIONS;
}

int menu_reconfigurer_touche(char tab[10][20], int *lig, char *quitter)
{
    // Declaration des variables
    char dep;

    // Nettoyage de l'ecran pour afficher le menu
    system("CLS");

    // Affichage des differents elements composants le menu principal avec leur couleur respective
    changeColour(L_YELLOW,BLACK);
    printf("       Reconfiguration touches       ");
    changeColour(L_GREEN,BLACK);
    printf("\n\n    Reconfigurer");
    printf("\n\n    Touches par defaut");
    changeColour(L_RED,BLACK);
    printf("\n\n\n\n    Retour");

    // Affichage de la position initiale du curseur
    changeColour(WHITE,BLACK);
    gotoligcol(*lig,2);
    printf(">");
    gotoligcol(8,10);

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
					gotoligcol(8,10);
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
                        gotoligcol(8,10);
				    }
				    else
                    {
                        gotoligcol(*lig,2);
                        printf(" ");
                        *lig=*lig-2;
                        gotoligcol(*lig,2);
                        printf(">");
                        gotoligcol(8,10);
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
					gotoligcol(8,10);
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
                        gotoligcol(8,10);
				    }
				    else
                    {
                        gotoligcol(*lig,2);
                        printf(" ");
                        *lig=*lig+2;
                        gotoligcol(*lig,2);
                        printf(">");
                        gotoligcol(8,10);
                    }
				}
				break;

    // Selectionner
			case ' ' :
				if(*lig==2)
                {
                    loadControles(STD_CONTROLS_FILE);
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
    return TOUCHE;
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
        if(choix==TOUCHE)
            choix=menu_reconfigurer_touche(tab, &lig, &quitter);
    }
}


/*
void sauvegarder(char *quitter)
=======
/*void sauvegarder(char *quitter)
>>>>>>> c7f03f5c55290bc7886bace0e14d829c8bef20e7
{
    FILE * save1=NULL;
    FILE * save2=NULL;
    FILE * save3=NULL;
    char dep;

     while(!*quitter)
    {
        if(kbhit())
        {
            dep=getch();

    // Les differentes touches
			switch(dep)
			{
            case 'p' :
                if(save1!=NULL)
                    {
                        save1=fopen("data/sauvegardes/save1.txt","w");
                        fprintf();
                        fscanf();
                    }
                    else
                    {
                        if(save2!=NULL)
                        {
                            save1=fopen("data/sauvegardes/save2.txt","w");
                            fprintf();
                            fscanf();
                        }
                        else
                        {
                            if(save3!=NULL)
                            {
                                save1=fopen("data/sauvegardes/save3.txt","w");
                                fprintf();
                                fscanf();
                            }
                            else
                            {
                                gotoligcol();
                                printf("Plus de sauvegarde disponible");
                            }
                        }
                    }
            }
        }
    }
}

*/
