#include "tools.h"

void takeOutEndLines(char * chaine)
{
	for(int i=0; chaine[i] != '\0'; i++)
	{
		if(chaine[i] == '\n' && chaine[i + 1] == '\0')
		{
			chaine[i] = '\0';
		}
	}
}

void waitSeconds(float seconds)
{
	// 0 Variables
	clock_t end;

	// 1 Definition de l'heure a laquelle on veut attendre
	end = clock() + seconds * CLOCKS_PER_SEC;

	while(clock() < end);
}

void cycleThroughCorner(int * pos_i, int * pos_j, int loop)
{
	// Renvoit l'un des quatres coins de la case grille_i grille_j
	// en fonction de la valeur contenue dans loop
	if(loop%4 == 0)
	{
		*pos_i = *pos_i - 1;
		*pos_j = *pos_j - 1;
	}
	else if(loop%4 == 1)
	{
		*pos_i = *pos_i - 1;
		*pos_j = *pos_j + 1;
	}
	else if(loop%4 == 2)
	{
		*pos_i = *pos_i + 1;
		*pos_j = *pos_j + 1;
	}
	else if(loop%4 == 3)
	{
		*pos_i = *pos_i + 1;
		*pos_j = *pos_j - 1;
	}
}


void addCoinLog(char couleur, int i, int j)
{
	FILE * logFile;
	logFile = fopen("data/logs/corners.txt", "a");
	fprintf(logFile, "joueur %i, ADDED i : %i, j : %i\n", couleur, i, j);
	fclose(logFile);
}

void removeCoinLog(char couleur, int i, int j)
{
	FILE * logFile;
	logFile = fopen("data/logs/corners.txt", "a");
	fprintf(logFile, "joueur %i, REMOVED i : %i, j : %i\n", couleur, i, j);
	fclose(logFile);
}

#if defined(_WIN32) || defined(WIN32)

char loc_getch()
{
	return getch();
}
char loc_kbhit()
{
	return kbhit();
}

#elif

char loc_getch()
{
  struct termios oldt,
                 newt;
  char            ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;

}

#endif