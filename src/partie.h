#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include "joueur.h"
/*
Ce fichier contient la d�finition d'une structure partie ainsi que
le prototype des fonctions li�es � la gestion de cette partie
*/

//0 Constantes
#define PARTIE_EN_COURS 0

//1 D�finition de la structure
typedef struct Partie
{
    // Contiendra la grille de la partie
    char** grille;
    // Contiendra un tableau dynamique de joueurs
    t_Joueur* joueurListe;
    // Variable indiquant l'�tat de la partie
    char state;
}t_Partie;

//2 Prototype des fonctions
// Cette fonction permet d'afficher la grille de jeu. Elle prend en param�tre la structure de la partie,
// ainsi que les coordonn�es o� la grille de jeu doit �tre affich�e (lig et col d�signent le point en haut � gauche)
void affichageConsoleGrilleDeJeu(t_Partie * self, int lig, int col);

#endif // PARTIE_H_INCLUDED
