#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include <stdarg.h>

#include "joueur.h"
#include "controles.h"
/*
Ce fichier contient la définition d'une structure partie ainsi que
le prototype des fonctions liées à la gestion de cette partie
*/

//0 Constantes
#define PARTIE_EN_COURS 0

// Pour définir le type de partie voulu
#define PARTIE_STANDARD 8

// Pour définir ce qui est contenu dans la case
#define CASE_VIDE 50

//1 Définition de la structure
typedef struct Partie
{
    // Contiendra la grille de la partie
    // On met la hauteur (ordonnée) dans la première des variables, et l'abscisse dans la deuxième.
    // Les cases peuvent contenir l'une des deux valeurs suivantes :
    //		CASE_VIDE pour dire que la case est vide
    //		Un numéro qui correspond au numéro d'un joueur sur le tableau, pour dire que la case est occupée par une pièce du joueur correspondant.
    char** grille;
    // Contient un tableau dynamique de joueurs
    t_Joueur* joueurListe;
    // Contient les touches à utiliser pour jouer
    t_Controles touches;
    // Variable indiquant l'état de la partie
    char state;
}t_Partie;

//2 Prototype des fonctions

// Cette fonction permet d'afficher la grille de jeu. Elle prend en paramètre la structure de la partie,
// ainsi que les coordonnées où la grille de jeu doit être affichée (lig et col désignent le point en haut à gauche)
void affichageConsoleGrilleDeJeu(t_Partie * self, int lig, int col);

// Fonction d'initialisation de la partie.
//	Parametres :
//		self : pointeur sur la partie
//		int w_grille : largeur voulue pour la grille
//		int h_grille : hauteur voulue pour la grille
//		char partieType : Nombre d'arguments voulus
//		int num_arguments : nombre d'arguments dans les ...
//			-> Cette fonction prend un nombre d'argument variable. Ces arguments sont des chars et représentent le type de joueur voulu.
//
//	Exemple d'utilisation :
//		initialisationPartie(partie, 20, 20, PARTIE_STANDARD, JOUEUR_HUMAIN, JOUEUR_HUMAIN, JOUEUR_ALEATOIRE, JOUEUR_ALEATOIRE);
//		initialisera la structure partie avec une grille de 20*20, pour une partie standard, avec deux joueurs humains et deux ordinateurs
//			jouant de manière aléatoire.
void initialisationPartie(t_Partie * self, int w_grille, int h_grille, char partieType, t_Controles touches, int n_joueurs, ...);

// Fonction pour libérer l'espace mémoire alloué lors de l'initialisation de la partie
void deinitialisationPartie(t_Partie * self);

#endif // PARTIE_H_INCLUDED
