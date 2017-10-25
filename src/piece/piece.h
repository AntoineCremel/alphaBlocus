#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

/*
     Ce fichier contiendra toutes les informations sur la d�finition d'une  structure contenant les informations d'une piece,
    ainsi que les d�finitions des fonctions qui permettront de faire fonctionner ces pi�ces.
*/

//0 D�finition de la structure
typedef struct piece
{
    ///Impl�menter la d�finition d'une pi�ce de Blocus
    /*
    Nous aurons probablement besoin d'un tableau � deux dimensions qui d�finira la forme de
    la pi�ce.
    R�fl�chir aussi � ajouter �ventuellement des variables qui donnent l'orientation de la pi�ce
    (afin de retenir l'orientation qu'elle avait la derni�re fois que le joueur l'a regard�e.
    */

    char grille[5][5];// Cette grille renseigne quelles cases sont couvertes par la pi�ce


}t_Piece;


//1 D�fintion des fonctions


#endif // PIECE_H_INCLUDED
