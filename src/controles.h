#ifndef CONTROLES_H_INCLUDED
#define CONTROLES_H_INCLUDED

#include <stdio.h>
#include <string.h>

#include "mainHeader.h"

/*
    Ce fichier contient la d�finition d'une structure contenant les touches � utiliser pour bouger son personnage.
    Il contient �galement les prototypes des fonctions responsables de la modification de ces controles
*/

//0 Constantes (contient �ventuellement les controles par d�faut)
#define CUSTOM_CONTROLS_FILE	"../data/options/customControls.txt"
#define STD_CONTROLS_FILE		"../data/options/stdControls.txt"

//1 Structure
typedef struct Controles
{
    char haut;
    char bas;
    char gauche;
    char droite;
    char selectionner;
    char rotation;
    char scrollHaut;
    char scrollBas;
    char quitter;
    /// Ajouter les controles responsables de la selection du bloc

}t_Controles;

//2 Fonctions
void loadControles(t_Controles * self);
void readControlesFile(t_Controles * self, char fileName[TAILLE_FILE_NAME]);

#endif // CONTROLES_H_INCLUDED
