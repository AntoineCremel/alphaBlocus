#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include "joueur.h"
/*
Ce fichier contient la définition d'une structure partie ainsi que
le prototype des fonctions liées à la gestion de cette partie
*/

//0 Constantes
#define PARTIE_EN_COURS 0

//1 Définition de la structure
typedef struct Partie
{
    // Contiendra la grille de la partie
    char** grille;
    // Contiendra un tableau dynamique de joueurs
    t_Joueur* joueurListe;
    // Variable indiquant l'état de la partie
    char state;
}t_Partie;

//2 Prototype des fonctions
// Cette fonction permet d'afficher la grille de jeu. Elle prend en paramètre la structure de la partie,
// ainsi que les coordonnées où la grille de jeu doit être affichée (lig et col désignent le point en haut à gauche)
void affichageConsoleGrilleDeJeu(t_Partie * self, int lig, int col);

#endif // PARTIE_H_INCLUDED
