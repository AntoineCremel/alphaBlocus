#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "piece/piece.h"

/*
Ce fichier contiendra la structure et les définitions des fonctions nécessaires au fonctionnement d'un joueur.
*/

//0 Constantes
#define JOUEUR_HUMAIN 0
#define JOUEUR_ALEATOIRE 1

//1 Définition de la structure
typedef struct Joueur
{
    // Pointeur vers la liste chaînée de pièces destinées au joueur
    t_Piece * ancre;
    // Variable pour définir le type de joueur (AI, aléatoire, joueur humain)
    char type;
}t_Joueur;

//2 Prototypes des fonctions

//Fonction qui initalise une structure de joueur avec sa liste chaînée de pièces
// Recoit en entrée : la structure d'un joueur, et
void joueurInitialisation(t_Joueur * self, char pieceFile);

#endif // JOUEUR_H_INCLUDED
