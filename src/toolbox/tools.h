#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <time.h>
#include <stdio.h>

#define LOG_FILE_SIZE 50
#define LOG_MSG_SIZE 50

// Fonction pour retirer les sauts a la ligne a la fin d'une chaine de caractère.
void takeOutEndLines(char * chaine);

// Fonction pour attendre un temps float en secondes
void waitSeconds(float secondes);

// FOnction qui renvoit les coordonnées d'un des coins de pos_i pos_j
void cycleThroughCorner(int * pos_i, int * pos_j, int loop);


/// Fonctions de log
void addCoinLog(char couleur, int i, int j);
void removeCoinLog(char couleur, int i, int j);

#endif // TOOLS_H_INCLUDED
