#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include <stdarg.h>

#include "joueur.h"
#include "controles.h"
/*
Ce fichier contient la d�finition d'une structure partie ainsi que
le prototype des fonctions li�es � la gestion de cette partie
*/

//0 Constantes
#define PARTIE_EN_COURS 0

// Pour d�finir le type de partie voulu
#define PARTIE_STANDARD 8

// Pour d�finir ce qui est contenu dans la case
#define CASE_VIDE 50

//1 D�finition de la structure
typedef struct Partie
{
    // Contiendra la grille de la partie
    // On met la hauteur (ordonn�e) dans la premi�re des variables, et l'abscisse dans la deuxi�me.
    // Les cases peuvent contenir l'une des deux valeurs suivantes :
    //		CASE_VIDE pour dire que la case est vide
    //		Un num�ro qui correspond au num�ro d'un joueur sur le tableau, pour dire que la case est occup�e par une pi�ce du joueur correspondant.
    char** grille;
    // Contient un tableau dynamique de joueurs
    t_Joueur* joueurListe;
    // Contient les touches � utiliser pour jouer
    t_Controles touches;
    // Variable indiquant l'�tat de la partie
    char state;
}t_Partie;

//2 Prototype des fonctions

// Cette fonction permet d'afficher la grille de jeu. Elle prend en param�tre la structure de la partie,
// ainsi que les coordonn�es o� la grille de jeu doit �tre affich�e (lig et col d�signent le point en haut � gauche)
void affichageConsoleGrilleDeJeu(t_Partie * self, int lig, int col);

// Fonction d'initialisation de la partie.
//	Parametres :
//		self : pointeur sur la partie
//		int w_grille : largeur voulue pour la grille
//		int h_grille : hauteur voulue pour la grille
//		char partieType : Nombre d'arguments voulus
//		int num_arguments : nombre d'arguments dans les ...
//			-> Cette fonction prend un nombre d'argument variable. Ces arguments sont des chars et repr�sentent le type de joueur voulu.
//
//	Exemple d'utilisation :
//		initialisationPartie(partie, 20, 20, PARTIE_STANDARD, JOUEUR_HUMAIN, JOUEUR_HUMAIN, JOUEUR_ALEATOIRE, JOUEUR_ALEATOIRE);
//		initialisera la structure partie avec une grille de 20*20, pour une partie standard, avec deux joueurs humains et deux ordinateurs
//			jouant de mani�re al�atoire.
void initialisationPartie(t_Partie * self, int w_grille, int h_grille, char partieType, t_Controles touches, int n_joueurs, ...);

// Fonction pour lib�rer l'espace m�moire allou� lors de l'initialisation de la partie
void deinitialisationPartie(t_Partie * self);

#endif // PARTIE_H_INCLUDED
