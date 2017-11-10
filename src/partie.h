#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include <stdarg.h>

#include "joueur.h"
#include "controles.h"
#include "mainHeader.h"
#include "toolbox/tools.h"
#include "gamePlayOptions.h"
/*
Ce fichier contient la définition d'une structure partie ainsi que
le prototype des fonctions liées à la gestion de cette partie
*/

//0 Constantes
#define PARTIE_EN_COURS 0
#define PARTIE_FINIE	1

// Pour définir le type de partie voulu
#define PARTIE_STANDARD 8

// Pour définir ce qui est contenu dans la case
#define CASE_VIDE 50

// Pour définir une case qui ne sera jamais dans la grille
#define OUT_BOUND		-1

//1 Définition de la structure
typedef struct Partie
{
    // Contiendra la grille de la partie
    // On met la hauteur (ordonnée) dans la première des variables, et l'abscisse dans la deuxième.
    // Les cases peuvent contenir l'une des deux valeurs suivantes :
    //		CASE_VIDE pour dire que la case est vide
    //		Un numéro qui correspond au numéro d'un joueur sur le tableau, pour dire que la case est occupée par une pièce du joueur correspondant.
    char ** grille;
    // Contient un tableau dynamique de joueurs
    t_Joueur * joueurListe;
    // Contient les touches à utiliser pour jouer
    t_Controles touches;
    // Contient les options de gameplay
    t_GameOptions game_options;
    // Variable indiquant l'état de la partie
    char state;
    // Variable indiquant quel joueur est le joueur actif
    int joueurActif;
    // Variables qui retiennent les dimensions de la matrice de jeu
    int h_grid;
    int w_grid;
    // Variable qui retient le nombre de joueurs actifs
    int n_Players;
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
//				Ces arguments sont des ints et servent à définir les joueurs voulus.
//				Chaque joueur que l'on ajoute doit avoir 4 arguments : son type, sa couleur, et sa position de départ (lig et col)
//					(IE : l'endroit sur lequel la première pièce du joueur doit être placée)
//
//	Exemple d'utilisation :
//		initialisationPartie(partie, 20, 20, PARTIE_STANDARD, 8, JOUEUR_HUMAIN, ROUGE, -1, -1, JOUEUR_HUMAIN, YELLOW, -1, 20, JOUEUR_ALEATOIRE, PURPLE, 20, 20, JOUEUR_ALEATOIRE, AQUA, -1, -1);
//		initialisera la structure partie avec une grille de 20*20, pour une partie standard, avec deux joueurs humains et deux ordinateurs
//			jouant de manière aléatoire. Leurs couleurs seront, dans l'ordre : rouge, jaune, violet, turquoise
void initialisationPartie(t_Partie * self, int w_grille, int h_grille, char partieType, int n_arguments, ...);

// Fonction pour libérer l'espace mémoire alloué lors de l'initialisation de la partie
void deinitialisationPartie(t_Partie * self);

// Fonction pour verifier si le curseur déplacé par le joueur déborde du plateau
// 		Renvoit : 1 s'il y a un dépassement de limite, 0 sinon.
char testDepassement(t_Partie * self);

/* Fonction pour jouer un coup.
	Dans ce contexte, jouer un coup signifie placer la pièce qui est à l'ancre du joueur actif
	 sur la position de son curseur.
 	- Teste d'abord si le coup est possible
	- S'il l'est, l'effectue et renvoit 0
	- Sinon, renvoit 1
*/
char playCoup(t_Partie * self);

// Fonction pour passer au joueur suivant
void nextPlayer(t_Partie * self);


/// Pour les coins
// Fonction pour trouver tous les coups possibles à partir d'un coin donné
void findAllPlaysHere(t_Partie * self, t_Coin * here);
/*
	Fonction pour déterminer si on peut poser la case piece_i piece_j d'une pièce
	sur la case game_i game_j de la grille de jeu tout en respectant les règles du jeu.

	Renvoit 1 si c'est possible, 0 sinon.
	De plus, dans le cas ou c'est possible, les valeurs de la position du curseur seront assignées à curs_i et curs_j.
*/
char testPlacement(t_Partie * self, int game_i, int game_j, int piece_i, int piece_j, int * curs_i, int * curs_j);

/*
	Fonction qui enregistre le nouveau coup du joueur actif dans sa liste de coups possibles :
		- Retire de sa double liste chaînée toutes les possibilités qui utilisent la pièce qu'il vient de jouer
		- Ajoute tous les coins de la pièce qu'il vient de jouer à sa liste de coups

	UTILISATION :
	A utiliser après avoir joué le coup, mais avant d'avoir effacé l'ancre du joueur actif
*/
void recordPlay(t_Partie * self);
/*
	Fonction pour recalculer tous les coups possibles dans un rayon rad_i et rad_j de la case curs_i curs_j
*/
void updateListesPossibilites(t_Partie * self, int curs_i, int curs_j, int rad_i, int rad_j);

/// Fonctions élémentaires
// Regarde tous les coins autour de grille_i et de grille_j. Si ces sont éligibles, créé un coin dans ces cases
// Renvoit 0 sinon
void checkAround(t_Partie * self, int grille_i, int grille_j);

#endif // PARTIE_H_INCLUDED
