#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

/*
     Ce fichier contiendra toutes les informations sur la d�finition d'une  structure contenant les informations d'une piece,
    ainsi que les d�finitions des fonctions qui permettront de faire fonctionner ces pi�ces.
*/

//0 Constantes
#define I_TAB_PIECE 5
#define J_TAB_PIECE 5

#define I_CENTRE_PIECE	-(I_TAB_PIECE)/2
#define J_CENTRE_PIECE	-(J_TAB_PIECE)/2

#define SYMB_PIECE '@'
#define SYMB_PIECE_MORT	'O'
#define SYMB_PAS_PIECE '.'

/* Constantes qui d�finissent les valeurs de symetrie de la piece.
		- COMPLET : toutes les rotations et inversions sont utiles
		- ROTATION_SEULE :
*/
#define COMPLET 0
#define ROTATION_SEULE	1
#define DEMI_COMPLET
#define DEMI_ROTATION
#define SIMPLE

//1 D�finition de la structure
typedef struct Piece
{
    ///Impl�menter la d�finition d'une pi�ce de Blocus
   char grille[I_TAB_PIECE][J_TAB_PIECE];// Cette grille renseigne quelles cases sont couvertes par la pi�ce

    // Pointeurs n�cessaires au fonctionnement d'une liste cha�n�e.
    struct Piece * precedent;
    struct Piece * suivant;

    // Char qui retient l'orientation de la pi�ce
    char orientation; // Retient le nombre de rotations dans le sens des aiguilles d'une montre
    char inversion;  // Retient si la pi�ce a �t� invers�e

    // Variable qui retient le num�ro de la pi�ce
    int number;

    // Variable qui indique le type de sym�trie de la pi�ce
    // A aouter plus tard
    char symetrie;
}t_Piece;


//2 D�fintion des fonctions li�es � Piece

/*
Fonction qui permet la rotation d'une pi�ce dans le sens horaire.
Modifie la grille en cons�quence
*/
void pieceRotation(t_Piece* self);
// Fonction pour faire la rotation en sens inverse
void pieceAntiRotation(t_Piece * self);

// Fonction qui sert � inverser la pi�ce (la retourner)
void inversionPiece(t_Piece * self);

/*
	Fonction utilis�e dans la d�tection des coups possibles.

	Elle fait tourner la pi�ce vers l'orientation suivante
*/
void cycleThroughPiece(t_Piece * self);
// Fonction qui devra �tre utilis�e � la place de pieceRotation dans tous les endroits du code
// a part piece.c
void rotateThroughPiece(t_Piece * self);
// Fonction permettant de faire l'inverse de rotateThroughPiece
void antiRotateThroughPiece(t_Piece * self);
// Renvoit le nombre de rotations � essayer avec cette pi�ce
int n_rotations(t_Piece * self);

// Fonction qui renvoit 1 si symb est un symbole de pi�ce, 0 sinon
char isPiece(char symb);
// Fonction qui renvoit 1 si symb est un symbole de coin, 0 sinon
char isCoin(char symb);

#endif // PIECE_H_INCLUDED
