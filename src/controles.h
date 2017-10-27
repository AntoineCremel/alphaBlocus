#ifndef CONTROLES_H_INCLUDED
#define CONTROLES_H_INCLUDED

/*
    Ce fichier contient la définition d'une structure contenant les touches à utiliser pour bouger son personnage.
    Il contient également les prototypes des fonctions responsables de la modification de ces controles
*/

//0 Constantes (contient éventuellement les controles par défaut)

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
