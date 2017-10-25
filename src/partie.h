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

#endif // PARTIE_H_INCLUDED
