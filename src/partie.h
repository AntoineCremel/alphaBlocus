#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include <stdarg.h>

#include "joueur.h"
#include "controles.h"
#include "mainHeader.h"
/*
Ce fichier contient la d�finition d'une structure partie ainsi que
le prototype des fonctions li�es � la gestion de cette partie
*/

//0 Constantes
#define PARTIE_EN_COURS 0
#define PARTIE_FINIE	1

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
    char ** grille;
    // Contient un tableau dynamique de joueurs
    t_Joueur * joueurListe;
    // Contient les touches � utiliser pour jouer
    t_Controles touches;
    // Variable indiquant l'�tat de la partie
    char state;
    // Variable indiquant quel joueur est le joueur actif
    int joueurActif;
    // Variables qui retiennent les dimensions de la matrice de jeu
    int h_grid;
    int w_grid;
}t_Partie;

//2 Prototype des fonctions

// Fonction d'initialisation de la partie.
//	Parametres :
//		self : pointeur sur la partie
//		int w_grille : largeur voulue pour la grille
//		int h_grille : hauteur voulue pour la grille
//		char partieType : Nombre d'arguments voulus
//		int num_arguments : nombre d'arguments dans les ...
//			-> Cette fonction prend un nombre d'argument variable.
//				Ces arguments sont des chars et servent � d�finir les joueurs voulus.
//				Chaque joueur que l'on ajoute doit avoir deux arguments : son type et sa couleur
//
//	Exemple d'utilisation :
//		initialisationPartie(partie, 20, 20, PARTIE_STANDARD, JOUEUR_HUMAIN, ROUGE, JOUEUR_HUMAIN, YELLOW, JOUEUR_ALEATOIRE, PURPLE, JOUEUR_ALEATOIRE, AQUA);
//		initialisera la structure partie avec une grille de 20*20, pour une partie standard, avec deux joueurs humains et deux ordinateurs
//			jouant de mani�re al�atoire. Leurs couleurs seront, dans l'ordre : rouge, jaune, violet, turquoise
void initialisationPartie(t_Partie * self, int w_grille, int h_grille, char partieType, int n_joueurs, ...);

// Fonction pour lib�rer l'espace m�moire allou� lors de l'initialisation de la partie
void deinitialisationPartie(t_Partie * self);

// Fonction pour verifier si le curseur d�plac� par le joueur d�borde du plateau
// 		Renvoit : 1 s'il y a un d�passement de limite, 0 sinon.
char testDepassement(t_Partie * self);

/* Fonction pour jouer un coup.
	Dans ce contexte, jouer un coup signifie placer la pi�ce qui est � l'ancre du joueur actif
	 sur la position de son curseur.
 	- Teste d'abord si le coup est possible
	- S'il l'est, l'effectue et renvoit 0
	- Sinon, renvoit 1
*/
char playCoup(t_Partie * self);

void nextPlayer(t_Partie * self);

#endif // PARTIE_H_INCLUDED
