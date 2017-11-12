#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

/*
     Ce fichier contiendra toutes les informations sur la définition d'une  structure contenant les informations d'une piece,
    ainsi que les définitions des fonctions qui permettront de faire fonctionner ces pièces.
*/

//0 Constantes
#define I_TAB_PIECE 5
#define J_TAB_PIECE 5

#define I_CENTRE_PIECE	-(I_TAB_PIECE)/2
#define J_CENTRE_PIECE	-(J_TAB_PIECE)/2

#define SYMB_PIECE '@'
#define SYMB_PIECE_MORT	'O'
#define SYMB_PAS_PIECE '.'

/* Constantes qui définissent les valeurs de symetrie de la piece.
		- COMPLET : toutes les rotations et inversions sont utiles
		- ROTATION_SEULE :
*/
#define COMPLET 0
#define ROTATION_SEULE	1
#define DEMI_COMPLET
#define DEMI_ROTATION
#define SIMPLE

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

    // Variable qui indique le type de symétrie de la pièce
    // A aouter plus tard
    char symetrie;
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

/*
	Fonction utilisée dans la détection des coups possibles.

	Elle fait tourner la pièce vers l'orientation suivante
*/
void cycleThroughPiece(t_Piece * self);
// Fonction qui devra être utilisée à la place de pieceRotation dans tous les endroits du code
// a part piece.c
void rotateThroughPiece(t_Piece * self);
// Fonction permettant de faire l'inverse de rotateThroughPiece
void antiRotateThroughPiece(t_Piece * self);
// Renvoit le nombre de rotations à essayer avec cette pièce
int n_rotations(t_Piece * self);

// Fonction qui renvoit 1 si symb est un symbole de pièce, 0 sinon
char isPiece(char symb);
// Fonction qui renvoit 1 si symb est un symbole de coin, 0 sinon
char isCoin(char symb);

#endif // PIECE_H_INCLUDED
