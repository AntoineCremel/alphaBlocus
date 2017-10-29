#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "piece/piece.h"
#include "toolbox/tools.h"
#include "mainHeader.h"

/*
Ce fichier contiendra la structure et les d�finitions des fonctions n�cessaires au fonctionnement d'un joueur.
*/

//0 Constantes
#define JOUEUR_HUMAIN 0
#define JOUEUR_ALEATOIRE 1

#define TAILLE_FILE_NAME 50

//1 D�finition de la structure
typedef struct Joueur
{
    // Pointeur vers la liste cha�n�e de pi�ces destin�es au joueur
    t_Piece * ancre;
    // Variable pour d�finir le type de joueur (AI, al�atoire, joueur humain)
    char type;
    // Variable qui d�finit la couleur des pi�ces d'un joueur.
    // Les constantes d�finissant les couleurs windows sont dans mainHeader.h
    char couleur;
}t_Joueur;

//2 Prototypes des fonctions

//Fonction qui initalise une structure de joueur avec sa liste cha�n�e de pi�ces
// Recoit en entr�e :
//      la structure d'un joueur
//      un string contenant le nom du fichier o� se trouve la liste des fichiers contenant les pi�ces disponibles au joueur
void joueurInitialisation(t_Joueur * self, char pieceFile[TAILLE_FILE_NAME]);

// Fonction de desinitialisation d'un joueur (on parcourt la liste chain�e de pi�ces et on efface tout)
void joueurDesinit(t_Joueur * self);

// Fonction permettant de jouer la piece selectionn�e par l'ancre
// 		Renvoit la grille de la piece, et retire la piece de la liste chainee.
void playAncre(t_Joueur * self, char grid[I_TAB_PIECE][J_TAB_PIECE]);

/// Fonctions elementaires
// Fonction permettant d'ajouter une piece vide dans la chaine juste apres l'ancre et de faire pointer l'ancre dessus
void addPieceAfter(t_Joueur * self, t_Piece * newPiece);
// Fonction permettant de n'effacer qu'un seule piece
void scrapAncre(t_Joueur * self);

// Fonction permettant d'avancer sur la liste chain�e
void scrollToSuivant(t_Joueur * self);
// Fonction permettant de reculer sur la liste chain�e
void scrollToPrecedent(t_Joueur * self);

#endif // JOUEUR_H_INCLUDED
