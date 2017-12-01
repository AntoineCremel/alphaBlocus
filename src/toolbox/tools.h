#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <time.h>
#include <stdio.h>

#define OS_WINDOWS  0
#define OS_UNIX		1

#if defined(_WIN32) || defined(WIN32)
	#define OS OS_WINDOWS
	#include <conio.h>
	#include <windows.h>
#elif
	#define OS OS_UNIX
	#include <termios.h>
	#include <unistd.h>
	#include <fcntl.h>
#endif

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

/// Encapsulation des fonctions de conio.h
// Fonction pour récupérer le caractère appuyé par l'utilisateur
char loc_getch();
// Fonction pour récupérer kbhit
char loc_kbhit();
// Clear screen
void loc_clear();

#endif // TOOLS_H_INCLUDED
