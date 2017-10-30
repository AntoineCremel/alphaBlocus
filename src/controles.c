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
	int compt;
	char buf;
	char touche;
	char read[SIZE_LINE];
	char action;

	// 1 Ouverture du fichier
	fic = fopen(fileName, "r");

	// 2 On parcourt le fichier et on remplace les controles qui sont définis dans ce fichier
	while(!feof(fic))
	{
		fgets(read, SIZE_LINE, fic);
		buf = 'a';
		compt = 0;

		// 2.0 On lit l'action qui est définie sur cette ligne
		while(buf != ':' && buf != '\0' && compt < SIZE_TOUCHE_NAME - 1)
		{
			buf = read[compt];
			if(buf != ':' && buf != '\0')
			{
				action = buf;
			}
			compt ++;
		}
		// 2.1 On lit quelle touche est définie pour cette action
		touche = '\'';
		while(buf != '\n' && buf != '\0' && compt < SIZE_LINE - 1)
		{
			buf = read[compt];
			if(buf != '\'')
			{
				touche = buf;
			}
			compt++;
		}
		// 2.2 On change la touche correspondante à cette action
		if(touche != '\'')
		{
			switch(action)
			{
			case 'h':
				self->haut = touche;
				break;
			case 'b':
				self->bas = touche;
				break;
			case 'g':
				self->gauche = touche;
				break;
			case 'd':
				self->droite = touche;
				break;
			case 'r':
				self->rotation = touche;
				break;
			case 'c':
				self->selectionner = touche;
				break;
			case 'p':
				self->scrollHaut = touche;
				break;
			case 's':
				self->scrollBas = touche;
				break;
			case 'q':
				self->quitter = touche;
				break;
			}
		}
	}
}
