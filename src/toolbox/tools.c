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

	while(clock() != end);
}
