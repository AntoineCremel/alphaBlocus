#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <string.h>
#include <stdlib.h>

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
// Recoit en entr�e :
//      la structure d'un joueur
//      un string contenant le nom du fichier o� se trouve la liste des fichiers contenant les pi�ces disponibles au joueur
void joueurInitialisation(t_Joueur * self, char pieceFile[30]);

#endif // JOUEUR_H_INCLUDED
