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

    // 1 On lit les informations relatives a la taille des pieces
    // 1.0 Ouverture du fichier permettant de trouver tous les fichiers de pièces
    fichierListe = fopen(pieceFile, "r");
    if(fichierListe == NULL)
		return;

    // 1.1 Boucle permettant d'ouvrir successivement tous les fichiers contenant les tailles de pièces.
    while(!feof(fichierListe))
	{
		// 1.1.0 Obtention du nom du fichier
		fgets(fileName, TAILLE_FILE_NAME, fichierListe);
		// 1.1.1 Ouverture
		fichierPiece = fopen(fileName, "r");
		// 1.1.2 Boucle afin de créer une pièce et de renseigner la grille de la pièce.
		if(fichierPiece)
		{
			// 1.1.2.0 Creation de la piece

			for(int i=0; i < 5; i++)
			{
				for(int j=0; j < 5; j++)
				{

				}
			}
			fclose(fichierPiece);
		}
	}

	fclose(fichierListe);
}
