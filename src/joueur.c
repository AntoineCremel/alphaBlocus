#include "joueur.h"


void joueurInitialisation(t_Joueur * self, char pieceFile[TAILLE_FILE_NAME])
{
    /*
        Cette fonction lit le contenu du fichier dont le nom est contenu dans le string pieceFile.
        Ce fichier contient une liste de fichier.
		On ouvre successivement chacun des fichiers de la liste. Ils contiennent les schémas de pièces de blocus.
		A partir de ces schémas, on créé une structure pièce en allocation dynamique, et on l'ajoute à la liste chaînée.

		Schéma de la liste chaînée :
			La liste chaînée de pièces est une liste bouclée à deux sens, c'est à dire que chaque pièce
			a un pointeur vers la liste qui la suit et un autre vers la liste qui la précède, et que la dernière pièce de
			la liste pointe vers la première (et vice versa)
    */
    //0 Variables
    // 0.0 Variable pointant vers le fichier contenant la liste des fichiers definissants les pieces.
    FILE * fichierListe = NULL;
    // 0.1 Variable pointant vers le fichier contenant la grille definissant la piece en cours.
    FILE * fichierPiece = NULL;
    // 0.2 string qui servira à la lecture des noms de fichiers
    char fileName[TAILLE_FILE_NAME];
    // 0.3 Pointeur intermediaire qui servira a l'allocation de la piece
    t_Piece * pieceBuff;
    // 0.4 Caractère qui servira d'intermédiaire vers la grille des pièces
    char charBuff;
    // 0.5 On initialise self->ancre
    self->ancre = NULL;

    // 1 On lit les informations relatives a la taille des pieces
    // 1.0 Ouverture du fichier permettant de trouver tous les fichiers de pièces
    fichierListe = fopen(pieceFile, "r");
    if(fichierListe == NULL)
	{
		printf("Le fichier de pieces n'a pas pu être lu\n");
		return;
	}


    // 1.1 Boucle permettant d'ouvrir successivement tous les fichiers contenant les tailles de pièces.
    while(!feof(fichierListe))
	{
		// 1.1.0 Obtention du nom du fichier
		fgets(fileName, TAILLE_FILE_NAME, fichierListe);

		// On retire le saut a la ligne grace a notre fonction custom
		takeOutEndLines(fileName);

		// 1.1.1 Ouverture
		fichierPiece = fopen(fileName, "r");
		// 1.1.2 Boucle afin de créer une pièce et de renseigner la grille de la pièce.
		if(fichierPiece)
		{
			// 1.1.2.0 Allocation de l'espace memoire pour la piece
			pieceBuff = (t_Piece*)malloc(sizeof(t_Piece));

			// 1.1.2.1 On met la piece dans la chaine
			addPieceAfter(self, pieceBuff);

			for(int i=0; i < I_TAB_PIECE; i++)
			{
				for(int j=0; j < J_TAB_PIECE; j++)
				{
					// On lit le caractère
					do
					{
						charBuff = (char)fgetc(fichierPiece);
					}while(charBuff == '\n');

					// Si c'est bien un caractère qui veut dire quelquechose on l'ajoute a la grille
					if(charBuff == SYMB_PIECE || charBuff == SYMB_PAS_PIECE)
					{
						self->ancre->grille[i][j] = charBuff;
					}
				}
			}
			fclose(fichierPiece);
		}
	}

	fclose(fichierListe);
}

void joueurDesinit(t_Joueur * self)
{
	// 0 Variables

	// 1 On effctue une boucle dans la liste chainee afin d'effacer toutes les pieces
	while(self->ancre != NULL)
	{
		scrapAncre(self);
	}
}

void playAncre(t_Joueur * self, char grid[I_TAB_PIECE][J_TAB_PIECE])
{
	// 0 Variables
	// On stocke la grille de la pièce

	// 1 On remplit le tableau avec les valeurs contenues dans la piece
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j = 0; j < J_TAB_PIECE; j++)
		{
			grid[i][j] = self->ancre->grille[i][j];
		}
	}
	/// Il est possible que l'effaçage de la pièce fasse bugger cette fonction
	/// IE : peut etre que le contenu du tableau sera effacé par le free que l'on s'apprete à effectuer
	/// 			A TESTER
	scrapAncre(self);
}

/// Fonctions elementaires
void scrapAncre(t_Joueur * self)
{
	//0 Variables
	// Pointeur utilisé pour garder contact avec la liste pendant que l'on efface
	// la piece contenue dans l'ancre;
	t_Piece * pieceBuffer;

	// 1.0 On recupère l'ancre
	pieceBuffer = self->ancre;

	// 1.1 On soude les autres elements de la chaine ensemble, en dehors de la piece que l'on veut effacer
	pieceBuffer->precedent->suivant = pieceBuffer->suivant;
	pieceBuffer->suivant->precedent = pieceBuffer->precedent;

	//1.2 Ensuite, on teste si l'on a affaire au dernier maillon qui existe
	if(pieceBuffer->precedent == pieceBuffer || pieceBuffer->precedent == NULL)
	{
		// 1.2.0 Si c'est le cas, met l'ancre à NULL
		self->ancre = NULL;
	}
	else
	{
		//1.2.1 on fait pointer l'ancre sur le maillon precedent
		self->ancre = pieceBuffer->precedent;
	}

	//1.3 Enfin, on libère la mémoire de pieceBuffer
	free(pieceBuffer);
}

void addPieceAfter(t_Joueur * self, t_Piece * newPiece)
{
	// Dans le cas ou il n'y a pas encore de piece pour ce joueur
	if(self->ancre == NULL)
	{
		newPiece->precedent = NULL;
		newPiece->suivant = NULL;

		self->ancre = newPiece;
	}
	// Dans le cas où il y a une seule piece pour ce joueur
	else if(self->ancre->suivant == NULL)
	{
		newPiece->precedent = self->ancre;
		newPiece->suivant = self->ancre;

		self->ancre->suivant = newPiece;
		self->ancre->precedent = newPiece;

		self->ancre = newPiece;
	}
	// Dans le cas ou il y a au deja plusieurs pieces pour ce joueur,
	//on ajoute celle ci a la suite et on fait pointer l'ancre dessus
	else
	{
		newPiece->precedent = self->ancre;
		newPiece->suivant = self->ancre->suivant;

		self->ancre->suivant->precedent = newPiece;
		self->ancre->suivant = newPiece;

		self->ancre = newPiece;
	}
}

void scrollToSuivant(t_Joueur * self)
{
	self->ancre = self->ancre->suivant;
}

void scrollToPrecedent(t_Joueur * self)
{
	self->ancre = self->ancre->precedent;
}
