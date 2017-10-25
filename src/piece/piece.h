#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

/*
     Ce fichier contiendra toutes les informations sur la définition d'une  structure contenant les informations d'une piece,
    ainsi que les définitions des fonctions qui permettront de faire fonctionner ces pièces.
*/

//0 Définition de la structure
typedef struct piece
{
    ///Implémenter la définition d'une pièce de Blocus
    /*
    Nous aurons probablement besoin d'un tableau à deux dimensions qui définira la forme de
    la pièce.
    Réfléchir aussi à ajouter éventuellement des variables qui donnent l'orientation de la pièce
    (afin de retenir l'orientation qu'elle avait la dernière fois que le joueur l'a regardée.
    */

    char grille[5][5];// Cette grille renseigne quelles cases sont couvertes par la pièce


}t_Piece;


//1 Défintion des fonctions


#endif // PIECE_H_INCLUDED
