#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED

#include <conio.h>

#include "mainHeader.h"
#include "partie.h"
#include "controles.h"
#include "toolbox/tools.h"
#include "affichageConsole.h"

// 0 Constantes
#define DELAY_BET_FRAMES 0.2

//1 Structures

//2 Prototypes de fonctions
void gameLoop(t_Partie * game, t_Controles * touches);

// Fonction qui va analyser l'input donné par l'utilisateur
void treatInput(char pressed, t_Controles * touches);

#endif // GAMELOOP_H_INCLUDED
