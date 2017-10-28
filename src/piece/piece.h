#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

/*
     Ce fichier contiendra toutes les informations sur la d�finition d'une  structure contenant les informations d'une piece,
    ainsi que les d�finitions des fonctions qui permettront de faire fonctionner ces pi�ces.
*/

//0 Constantes
#define I_TAB_PIECE 5
#define J_TAB_PIECE 5

#define SYMB_PIECE '@'
#define SYMB_PAS_PIECE '.'

//1 D�finition de la structure
typedef struct Piece
{
    ///Impl�menter la d�finition d'une pi�ce de Blocus
   char grille[I_TAB_PIECE][J_TAB_PIECE];// Cette grille renseigne quelles cases sont couvertes par la pi�ce

    // Pointeurs n�cessaires au fonctionnement d'une liste cha�n�e.
    struct Piece * precedent;
    struct Piece * suivant;
}t_Piece;


//2 D�fintion des fonctions li�es � Piece

/*
Fonction qui permet la rotation d'une pi�ce. Change les espaces occup�s dans grille
*/
void pieceRotation(t_Piece* self);

#endif // PIECE_H_INCLUDED
