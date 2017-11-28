#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED

#include <conio.h>
#include <math.h>

#include "mainHeader.h"
#include "partie.h"
#include "controles.h"
#include "toolbox/tools.h"
#include "affichageConsole.h"

// 0 Constantes
#define DELAY_BET_FRAMES 0.05

// 0.1 Constantes en lien avec le score d'heuristique
#define BASE_SCORE				400

#define DIST_FROM_CENTER_MULTIP -15
#define PER_BLOCKED_PLAYS		12

//1 Structures

//2 Prototypes de fonctions
/*
	gameTurns d�finit le d�roulement de la partie tour par tour
*/
void gameTurns(t_Partie * game);
/*
	humanTurn contient la d�finition de ce qui se passe durant le tour
	d'un joueur humain : boucle d'affichage, de selection de coup etc...
*/
void humanTurn(t_Partie * game);
/*
	aleaTurn contient la fonction permettant a l'ordinateur de jouer
	un coup al�atoirement
*/
void aleaTurn(t_Partie * game);
/*
	Fonction permettant � l'ordinateur de jouer un coup en fonction d'une liste d'heuristiques.
	Intelligence Artificielle de type 1, sans r�flexion sur plusieurs coups � la suite
*/
void heuristurn(t_Partie * game);

// Fonction qui fait jouer un coup � l'intelligence artificelle
void slowPlay(t_Partie * game, t_Coup * a_jouer);

// Fonction qui va analyser l'input donn� par l'utilisateur
// Renvoit 0 si le joueur a finit son tour ou veut quitter la partie,
// 1 sinon.
char treatInput(t_Partie * game, char pressed);

#endif // GAMELOOP_H_INCLUDED
