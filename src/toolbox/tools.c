#include "tools.h"

void takeOutEndLines(char * chaine)
{
	for(int i=0; i < sizeof(chaine); i++)
	{
		if(chaine[i] == '\n' && chaine[i + 1] == '\0')
		{
			chaine[i] = '\0';
		}
	}
}
