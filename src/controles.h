#ifndef CONTROLES_H_INCLUDED
#define CONTROLES_H_INCLUDED

/*
    Ce fichier contient la d�finition d'une structure contenant les touches � utiliser pour bouger son personnage.
    Il contient �galement les prototypes des fonctions responsables de la modification de ces controles
*/

//0 Constantes (contient �ventuellement les controles par d�faut)

//1 Structure
typedef struct Controles
{
    char haut;
    char bas;
    char gauche;
    char droite;
    char selectionner;
    char rotation;
    char quitter;
    /// Ajouter les controles responsables de la selection du bloc

}t_Controles;

//2 Fonctions


#endif // CONTROLES_H_INCLUDED
