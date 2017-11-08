#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

/*
     Ce fichier contiendra toutes les informations sur la définition d'une  structure contenant les informations d'une piece,
    ainsi que les définitions des fonctions qui permettront de faire fonctionner ces pièces.
*/

//0 Constantes
#define I_TAB_PIECE 5
#define J_TAB_PIECE 5

#define I_CENTRE_PIECE	-(I_TAB_PIECE-1)/2
#define J_CENTRE_PIECE	-(J_TAB_PIECE-1)/2

#define SYMB_PIECE '@'
#define SYMB_PIECE_MORT	'O'
#define SYMB_PAS_PIECE '.'

//1 Définition de la structure
typedef struct Piece
{
    ///Implémenter la définition d'une pièce de Blocus
   char grille[I_TAB_PIECE][J_TAB_PIECE];// Cette grille renseigne quelles cases sont couvertes par la pièce

    // Pointeurs nécessaires au fonctionnement d'une liste chaînée.
    struct Piece * precedent;
    struct Piece * suivant;

    // Char qui retient l'orientation de la pièce
    char orientation; // Retient le nombre de rotations dans le sens des aiguilles d'une montre
    char inversion;  // Retient si la pièce a été inversée

    // Variable qui retient le numéro de la pièce
    int number;
}t_Piece;


//2 Défintion des fonctions liées à Piece

/*
Fonction qui permet la rotation d'une pièce dans le sens horaire.
Modifie la grille en conséquence
*/
void pieceRotation(t_Piece* self);
// Fonction pour faire la rotation en sens inverse
void pieceAntiRotation(t_Piece * self);

// Fonction qui sert à inverser la pièce (la retourner)
void inversionPiece(t_Piece * self);

// Fonction qui renvoit 1 si symb est un symbole de pièce, 0 sinon
char isPiece(char symb);

#endif // PIECE_H_INCLUDED
