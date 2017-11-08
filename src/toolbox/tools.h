#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <time.h>

// Fonction pour retirer les sauts a la ligne a la fin d'une chaine de caractère.
void takeOutEndLines(char * chaine);

// Fonction pour attendre un temps float en secondes
void waitSeconds(float secondes);

// FOnction qui renvoit les coordonnées d'un des coins de pos_i pos_j
void cycleThroughCorner(int * pos_i, int * pos_j, int loop);

#endif // TOOLS_H_INCLUDED
