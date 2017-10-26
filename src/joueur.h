#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "piece/piece.h"

/*
Ce fichier contiendra la structure et les d�finitions des fonctions n�cessaires au fonctionnement d'un joueur.
*/

//0 Constantes
#define JOUEUR_HUMAIN 0
#define JOUEUR_ALEATOIRE 1

//1 D�finition de la structure
typedef struct Joueur
{
    // Pointeur vers la liste cha�n�e de pi�ces destin�es au joueur
    t_Piece * ancre;
    // Variable pour d�finir le type de joueur (AI, al�atoire, joueur humain)
    char type;
}t_Joueur;

//2 Prototypes des fonctions

//Fonction qui initalise une structure de joueur avec sa liste cha�n�e de pi�ces
// Recoit en entr�e : la structure d'un joueur, et
void joueurInitialisation(t_Joueur * self, char pieceFile);

#endif // JOUEUR_H_INCLUDED
