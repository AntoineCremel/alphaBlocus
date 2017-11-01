#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED

#include "mainHeader.h"
#include "partie.h"
#include "controles.h"
#include "toolbox/tools.h"
#include "affichageConsole.h"

// 0 Constantes
#define DELAY_BET_FRAMES 0.05

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

// Fonction qui va analyser l'input donn� par l'utilisateur
// Renvoit 0 si le joueur a finit son tour ou veut quitter la partie,
// 1 sinon.
char treatInput(t_Partie * game, char pressed);

#endif // GAMELOOP_H_INCLUDED
