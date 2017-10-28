#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

/*
     Ce fichier contiendra toutes les informations sur la définition d'une  structure contenant les informations d'une piece,
    ainsi que les définitions des fonctions qui permettront de faire fonctionner ces pièces.
*/

//

//1 Définition de la structure
typedef struct Piece
{
    ///Implémenter la définition d'une pièce de Blocus
   char grille[5][5];// Cette grille renseigne quelles cases sont couvertes par la pièce

    // Pointeurs nécessaires au fonctionnement d'une liste chaînée.
    struct Piece * precedent;
    struct Piece * suivant;
}t_Piece;


//2 Défintion des fonctions liées à Piece

/*
Fonction qui permet la rotation d'une pièce. Change les espaces occupés dans grille
*/
void pieceRotation(t_Piece* self);

#endif // PIECE_H_INCLUDED
