#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "piece/piece.h"
#include "toolbox/tools.h"
#include "mainHeader.h"
#include "coup.h"

/*
Ce fichier contiendra la structure et les d�finitions des fonctions n�cessaires au fonctionnement d'un joueur.
*/

//0 Constantes
#define JOUEUR_HUMAIN 0
#define JOUEUR_ALEATOIRE 1

#define LOG_ALEA_NAME "data/logs/aleatoie.txt"

//1 D�finition de la structure
typedef struct Joueur
{
    // Pointeur vers la liste cha�n�e de pi�ces destin�es au joueur
    t_Piece * ancre;
    // Liste cha�n�e de coin.
    // A chaque maillon de cette liste s'accroche une liste cha�n�e de coups possibles depuis ce coin
    t_Coin * possibilites;
    // Variable pour d�finir le type de joueur (AI, al�atoire, joueur humain)
    char type;
    // Variable qui d�finit la couleur des pi�ces d'un joueur.
    // Les constantes d�finissant les couleurs windows sont dans mainHeader.h
    char couleur;
    // Variables qui contiennent la position du curseur du joueur
    // Le curseur correspond � la case centrale de la pi�ce
    int curs_lig;
    int curs_col;
    // Variable qui indique si le joueur est encore capable de jouer o� si toutes
    //  ses options sont bloqu�es, auquel cas il faut passer son tour
    char bloque;
    // Variables qui indique la position de d�part du joueur
    int start_lig;
    int start_col;
    // Score du joueur
    int score;
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

// Fonction renvoyant un pointeur sur coup qui permet de jouer un coup al�atoire
t_Coup * getAleaCoup(t_Joueur * self);

/// Fonctions elementaires
// Fonction permettant d'ajouter une piece vide dans la chaine juste apres l'ancre et de faire pointer l'ancre dessus
void addPieceAfter(t_Joueur * self, t_Piece * newPiece);
// Fonction permettant de n'effacer qu'un seule piece
void scrapAncre(t_Joueur * self);

// Fonction permettant d'avancer sur la liste chain�e
void scrollToSuivant(t_Joueur * self);
// Fonction permettant de reculer sur la liste chain�e
void scrollToPrecedent(t_Joueur * self);

// Fonction qui teste si le joueur est bloqu�
char testBloc(t_Joueur * self);

// Fonction pour d�sallouer la m�moire d'un coin
void scrapCoin(t_Joueur * self, int pos_i, int pos_j);
// Fonction pour ajouter un coin � la liste chainee
void addCoin(t_Joueur * self, int pos_i, int pos_j);

// Fonction qui teste si un joueur peut encore jouer
// Renvoit 1 s'il est bloqu�, 0 sinon
char isBloque(t_Joueur * self);

// Fonction charg�e de parcourir les coins du joueur afin de vider les coins vides
void clearEmptyCoins(t_Joueur * self);

int get_n_PossiblePlays(t_Joueur * self);

#endif // JOUEUR_H_INCLUDED
