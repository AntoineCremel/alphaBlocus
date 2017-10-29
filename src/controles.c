#include "controles.h"

void loadControles(t_Controles * self)
{
	// 0 Variables

	// 1 Lecture des controles standards
	readControlesFile(self, STD_CONTROLS_FILE);

	// 2 Lecture des controles custroms(qui overrident les controles standards)
	readControlesFile(self, CUSTOM_CONTROLS_FILE);
}

void readControlesFile(t_Controles * self, char fileName[TAILLE_FILE_NAME])
{
	// 0 Variables
	FILE * fic;
	char buf;
	char read[30];
	char action[20];

	// 1 Ouverture du fichier
	fic = fopen(fileName, "r");

	// 2 On parcourt le fichier et on remplace les controles qui sont définis dans ce fichier
	while(!feof(fic))
	{
		fgets(read, 30, fic);

		buf = 'a';

		/// A FINIR
	}
}
