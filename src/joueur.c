#include "joueur.h"


void joueurInitialisation(t_Joueur * self, char pieceFile[TAILLE_FILE_NAME])
{
    /*
        Cette fonction lit le contenu du fichier dont le nom est contenu dans le string pieceFile.
        Ce fichier contient une liste de fichier.
		On ouvre successivement chacun des fichiers de la liste. Ils contiennent les sch�mas de pi�ces de blocus.
		A partir de ces sch�mas, on cr�� une structure pi�ce en allocation dynamique, et on l'ajoute � la liste cha�n�e.

		Sch�ma de la liste cha�n�e :
			La liste cha�n�e de pi�ces est une liste boucl�e � deux sens, c'est � dire que chaque pi�ce
			a un pointeur vers la liste qui la suit et un autre vers la liste qui la pr�c�de, et que la derni�re pi�ce de
			la liste pointe vers la premi�re (et vice versa)
    */
    //0 Variables
    // 0.0 Variable pointant vers le fichier contenant la liste des fichiers definissants les pieces.
    FILE * fichierListe = NULL;
    // 0.1 Variable pointant vers le fichier contenant la grille definissant la piece en cours.
    FILE * fichierPiece = NULL;
    // 0.2 string qui servira � la lecture des noms de fichiers
    char fileName[TAILLE_FILE_NAME];
    // 0.3 Pointeur intermediaire qui servira a l'allocation de la piece
    t_Piece * pieceBuff;
    // 0.4 Caract�re qui servira d'interm�diaire vers la grille des pi�ces
    char charBuff;
    // 0.5 On initialise les pointeurs
    self->ancre = NULL;
    self->possibilites = NULL;
    // 0.6 Variable qui sera utilis�e pour num�roter les pi�ces
    int num = 1;
    // 0.7 Variable qui compte la taille de la pi�ce pour l'utiliser pour le calcul du score
    int taille = 0;

    // 1 On lit les informations relatives a la taille des pieces
    // 1.0 Ouverture du fichier permettant de trouver tous les fichiers de pi�ces
    fichierListe = fopen(pieceFile, "r");
    if(fichierListe == NULL)
	{
		printf("Le fichier de pieces n'a pas pu �tre lu\n");
		return;
	}


    // 1.1 Boucle permettant d'ouvrir successivement tous les fichiers contenant les tailles de pi�ces.
    while(!feof(fichierListe))
	{
		// 1.1.0 Obtention du nom du fichier
		fgets(fileName, TAILLE_FILE_NAME, fichierListe);

		// On retire le saut a la ligne grace a notre fonction custom
		takeOutEndLines(fileName);

		// 1.1.1 Ouverture
		fichierPiece = fopen(fileName, "r");
		// 1.1.2 Boucle afin de cr�er une pi�ce et de renseigner la grille de la pi�ce.
		if(fichierPiece)
		{
			// 1.1.2.0 Allocation de l'espace memoire pour la piece
			pieceBuff = (t_Piece*)malloc(sizeof(t_Piece));

			// 1.1.2.1 On met la piece dans la chaine
			addPieceAfter(self, pieceBuff);

			// Reinitialisation du compteur de taille de la pi�ce
			taille = 0;

			// On initialise la sym�trie de la pi�ce avec une valeur par d�faut
			self->ancre->symetrie = COMPLET;

			// Initialisation de l'orientation de la pi�ce
			self->ancre->inversion = 0;
			self->ancre->orientation = 0;

			for(int i=0; i < I_TAB_PIECE; i++)
			{
				for(int j=0; j < J_TAB_PIECE; j++)
				{
					// On lit le caract�re
					do
					{
						charBuff = (char)fgetc(fichierPiece);
					}while(charBuff == '\n');

					// Si c'est bien un caract�re qui veut dire quelquechose on l'ajoute a la grille
					if(charBuff == SYMB_PIECE || charBuff == SYMB_PAS_PIECE || charBuff == SYMB_PIECE_MORT)
					{
						self->ancre->grille[i][j] = charBuff;

						if(isPiece(charBuff))
							// Incr�mentation de la taille de la pi�ce
							taille++;
					}
				}
			}
			// Ensute, on lit le caract�re qui renseigne la sym�trie de la pi�ce
			do
			{
				if(!feof(fichierPiece))
					charBuff = (char)fgetc(fichierPiece);
			}while(charBuff == '\n' && !feof(fichierPiece));


			if(charBuff == COMPLET || charBuff == DEMI_COMPLET ||
				charBuff == ROTATION_SEULE || charBuff == DEMI_ROTATION
				|| charBuff == SIMPLE)
			{
				self->ancre->symetrie = charBuff;
			}
			fclose(fichierPiece);

			// On attribue un num�ro et une taille � la pi�ce en question
			self->ancre->taille = taille;
			self->ancre->number = num;
			num++;
		}
	}

	fclose(fichierListe);

	// 2 Maintenant on initialise la liste chainee de positions
	addCoin(self, self->start_lig, self->start_col);

	// 3 Intialisation du score � 0
	self->score = 0;
}

void joueurDesinit(t_Joueur * self)
{
	// 0 Variables
	t_Coin * suite;

	// 1 On effectue une boucle dans la liste chainee afin d'effacer toutes les pieces
	while(self->ancre != NULL)
	{
		scrapAncre(self);
	}

	// 2 Boucle pour lib�rer la m�moire des possibilit�s
	while(self->possibilites != NULL)
	{
		suite = self->possibilites->suivant;
		free(self->possibilites);
		self->possibilites = suite;
	}
}

void playAncre(t_Joueur * self, char grid[I_TAB_PIECE][J_TAB_PIECE])
{
	// 0 Variables
	// On stocke la grille de la pi�ce

	// 1 On remplit le tableau avec les valeurs contenues dans la piece
	for(int i=0; i < I_TAB_PIECE; i++)
	{
		for(int j = 0; j < J_TAB_PIECE; j++)
		{
			grid[i][j] = self->ancre->grille[i][j];
		}
	}
	/// Il est possible que l'effa�age de la pi�ce fasse bugger cette fonction
	/// IE : peut etre que le contenu du tableau sera effac� par le free que l'on s'apprete � effectuer
	/// 			A TESTER
	scrapAncre(self);
}

t_Coup * getAleaCoup(t_Joueur * self)
{
	// 0 Variables
	// 0.1 Variable qui permet de compter combien il y a de coups possibles
	int n_coups = 0;
	// 0.2 Curseurs permettant de parcourir les listes chaines
	t_Coin * curs_coin = self->possibilites;
	t_Coup * curs_coup;
	// O.3 Nombre al�atoire permettant de d�terminer le coup � jouer
	int coup_choisi;

	// 1 On d�termine le nombre de coups possibles
	n_coups = get_n_PossiblePlays(self);

	// 2 On choisi un nombre al�atoire en fonction du nombre de coups disponibles
	coup_choisi = rand() % n_coups;

	// 3 On reparcourt les boucles pour trouver le coup correspondant
	curs_coin = self->possibilites;
	// Cette variable sert de nouveau � compter le nombre de coups que l'on a trouv�
	n_coups = 0;
	while(curs_coin && n_coups < coup_choisi)
	{
		curs_coup = curs_coin->ancre;
		while(curs_coup && n_coups < coup_choisi)
		{
			n_coups++;

			if(n_coups == coup_choisi)
			{
				// 4 On log le coup choisi
				FILE * fic;
				fic = fopen(LOG_ALEA_NAME, "a");
				if(fic)
				{
					fprintf(fic, "Coup choisi  : pos : (%i, %i) avec rotation :(%i, %i), sur la piece %i\n", curs_coup->curs_i, curs_coup->curs_j,
								curs_coup->rotation, curs_coup->inversion, curs_coup->piece);
						fclose(fic);
				}
				return curs_coup;
			}

			curs_coup = curs_coup->suivant;
		}
		curs_coin = curs_coin->suivant;
	}

	return NULL;
}

/// Fonctions elementaires
void scrapAncre(t_Joueur * self)
{
	//0 Variables
	// Pointeur utilis� pour garder contact avec la liste pendant que l'on efface
	// la piece contenue dans l'ancre;
	t_Piece * pieceBuffer;

	// 1.0 On recup�re l'ancre
	pieceBuffer = self->ancre;

	// 1.1 On soude les autres elements de la chaine ensemble, en dehors de la piece que l'on veut effacer
	if(pieceBuffer->precedent != NULL && pieceBuffer->suivant != NULL)
	{
		pieceBuffer->precedent->suivant = pieceBuffer->suivant;
		pieceBuffer->suivant->precedent = pieceBuffer->precedent;
	}

	//1.2 Ensuite, on teste si l'on a affaire au dernier maillon qui existe
	if(pieceBuffer->precedent == pieceBuffer || pieceBuffer->precedent == NULL)
	{
		// 1.2.0 Si c'est le cas, met l'ancre � NULL
		self->ancre = NULL;
	}
	else
	{
		//1.2.1 on fait pointer l'ancre sur le maillon precedent
		self->ancre = pieceBuffer->precedent;
	}

	//1.3 Enfin, on lib�re la m�moire de pieceBuffer
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
	// Dans le cas o� il y a une seule piece pour ce joueur
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
	if(self->ancre != NULL && self->ancre->suivant != NULL)
		self->ancre = self->ancre->suivant;
}

void scrollToPrecedent(t_Joueur * self)
{
	if(self->ancre != NULL && self->ancre->precedent != NULL)
		self->ancre = self->ancre->precedent;
}

char testBloc(t_Joueur * self)
{
	if(!self->possibilites)
	{
		self->bloque = 1;
		return 1;
	}
	else
	{
		self->bloque = 0;
		return 0;
	}
}

void scrapCoin(t_Joueur * self, int pos_i, int pos_j)
{
	// 0 Variables
	t_Coin * buffer = self->possibilites;
	t_Coin * avant = NULL;

	// 0.1 Si le buffer est null, on quitte la fonction
	if(!buffer)
		return;

	// 1 On parcourt la liste chainee de coins jusqu'� trouver le coin ayant les positions voulues
	while(buffer && (buffer->pos_i != pos_i || buffer->pos_j != pos_j))
	{
		avant = buffer;
		buffer = buffer->suivant;
	}

	// 1 Si on n'a pas trouv� dans la liste de coin qui correspond � ce que l'on cherchait, on quitte
	if(buffer->pos_i != pos_i || buffer->pos_j != pos_j)
		return;

	// 2 Ensuite on efface tous les coups de la liste chainee du coin
	emptyCoin(buffer);

	// 3 On referme la liste chainee
	if(avant)
		avant->suivant = buffer->suivant;
	else
		self->possibilites = buffer->suivant;

	// 4 Enfin on lib�re ce coin de la cha�ne
	free(buffer);

	// 5 On ecrit le log
	removeCoinLog(self->couleur, pos_i, pos_j);
}

void addCoin(t_Joueur * self, int pos_i, int pos_j)
{
	// 0 Variables
	t_Coin * buffer;

	// 1 On cr�� la variable
	// 1.0 Allocation de l'espace m�moire n�cessaire
	buffer = (t_Coin*)malloc(sizeof(t_Coin));

	// 1.1 On remplit les cases comme il le faut
	buffer->pos_i = pos_i;
	buffer->pos_j = pos_j;
	buffer->ancre = NULL;

	// 3 On ajoute maintenant ce coin � la chaine
	buffer->suivant = self->possibilites;
	self->possibilites = buffer;

	// 4 On ecrit le log
	addCoinLog(self->couleur, pos_i, pos_j);
}

char isBloque(t_Joueur * self)
{
	// 0 Variables
	t_Coin * curs_coin = self->possibilites;

	// Cas special ou l'ancre est NULL, le joueur ne peut donc rien jouer
	if(!self->ancre)
	{
		self->bloque = 1;
		return 1;
	}

	// 1 Boucle
	while(curs_coin)
	{
		// Si on trouve quelquechose � l'ancre de l'un des coins
		if(curs_coin->ancre)
			return 0;

		curs_coin = curs_coin->suivant;
	}
	// Si l'on n'a rien trouv�, on met � jour la variable
	self->bloque = 1;
	return 1;
}

void clearEmptyCoins(t_Joueur * self)
{
	//0 Variables
	t_Coin * precedent = NULL;
	t_Coin * curseur = self->possibilites;

	// 1 On parcourt la liste de coins
	while(curseur)
	{
		//1.0 On teste si ce coin a toujours une liste de coups
		if(!curseur->ancre)
		{
			// 1.0.0 Si non, on efface ce coin
			if(precedent)
				precedent->suivant = curseur->suivant;
			else
				self->possibilites = curseur->suivant;

			removeCoinLog(self->couleur, curseur->pos_i, curseur->pos_j);

			free(curseur);

			if(precedent)
				curseur = precedent->suivant;
			else
				curseur = self->possibilites;
		}
		// 1.1 On avance d'un cran dans la liste
		else
		{
			precedent = curseur;
		curseur = curseur->suivant;
		}
	}
}

int get_n_PossiblePlays(t_Joueur * self)
{
	// 0 Variables
	// 0.1 Variable qui permet de compter combien il y a de coups possibles
	int n_coups = 0;
	// 0.2 Curseurs permettant de parcourir les listes chaines
	t_Coin * curs_coin = self->possibilites;
	t_Coup * curs_coup;

	// 1 Boucles de parcourt des listes cha�n�es
	while(curs_coin)
	{
		curs_coup = curs_coin->ancre;
		while(curs_coup)
		{
			n_coups++;
			curs_coup = curs_coup->suivant;
		}
		curs_coin = curs_coin->suivant;
	}

	return n_coups;
}

t_Piece * get_piece_n(t_Joueur * self, int n)
{
	t_Piece * start = self->ancre;
	t_Piece * retour = NULL;

	if(self->ancre == NULL)
		return NULL;

	while(self->ancre->number != n)
		scrollToSuivant(self);

	retour = self->ancre;

	self->ancre = start;

	return retour;
}
