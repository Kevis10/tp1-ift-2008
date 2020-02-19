/**
 * \file Labyrinthe.cpp
 * \brief Le code des méthodes membres et privés de la classe Labyrinthe.
 * \author IFT-2008, Étudiant(e)
 * \version 0.1
 * \date janvier 2020
 * 
 */

//Fichiers à compléter par les autres méthodes de la classe Labyrinthes demandées

#include "Labyrinthe.h"

using namespace std;

namespace TP1
{
/**
 * \fn Labyrinthe::Labyrinthe()
 * constructeur de la classe declare declare comme etant des pointeur nulle
 * depart arrive et dernier et define la taille a 0
*/
Labyrinthe::Labyrinthe() : depart(nullptr), arrivee(nullptr), dernier(nullptr)
{
}

/**
 * \fn Labyrinthe::~Labyrinthe()
 * Destructeur de la classe, s'assure de libere la memoire des NoeudListePieces
 */

Labyrinthe::~Labyrinthe()
{
	_detruire();
}
/**
 * \fn void Labyrinthe::placeDepart(const std::string &nom)
 * \param nom nom de la piece a place comme etant le depart
 * place le pointeur depart a la position de la piece du meme nom dans la chaine des 
 * NoeudListePiece, si la piece n'existe pas une exception logic_error est lance
 */
void Labyrinthe::placeDepart(const std::string &nom)
{
	NoeudListePieces *courant = dernier->suivant;
	while (courant != dernier)
	{
		if (courant->piece.getNom() == nom)
		{
			depart = &(courant->piece);
			return;
		}
		courant = courant->suivant;
	}
	throw logic_error("La pièce portant le nom spécifié n'appartient pas au Labyrinthe ");
}

void Labyrinthe::placeArrivee(const std::string &nom)
{
	NoeudListePieces *courant = dernier->suivant;
	while (courant != dernier)
	{
		if (courant->piece.getNom() == nom)
		{
			arrivee = &(courant->piece);
			return;
		}
		courant = courant->suivant;
	}
	throw logic_error("La pièce portant le nom spécifié n'appartient pas au Labyrinthe ");
}
void Labyrinthe::_detruire()
{
	NoeudListePieces *courant = dernier;
	while (courant != nullptr)
	{
		dernier = dernier->suivant;
		delete courant;
		courant = dernier;
	}
}

const Labyrinthe &Labyrinthe::operator=(const Labyrinthe &source)
{
	if (source.dernier->suivant != nullptr)
	{
		_detruire();
	}

	if (source.dernier->suivant != 0)
	{
		_copier(source);
	}

	return (*this);
}
bool Labyrinthe::appartient(const Piece &p) const
{
	NoeudListePieces *courant = dernier->suivant;
	while (courant != dernier)
	{
		if (courant->piece.getNom() == p.getNom())
		{
			return true;
		}
		courant = courant->suivant;
	}
	return false;
}

Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(const std::string &nom) const //Pourquoi mettre Labyrinthe:: devant NoeudListePieces *
{
	if (nom == "")
	{
		throw invalid_argument("Le nom ne doit pas être vide");
	}
	NoeudListePieces *courant = dernier->suivant;
	while (courant != dernier)
	{
		if (courant->piece.getNom() == nom)
		{
			return &(*courant);
		}
		courant = courant->suivant;
	}
}

Labyrinthe::Labyrinthe(const Labyrinthe &source)
{

	_copier(source);
}

void Labyrinthe::_copier(const Labyrinthe &source)
{
	dernier = source.dernier;
	dernier->piece = Piece(source.dernier->piece);

	NoeudListePieces *courant_source = source.dernier->suivant;
	NoeudListePieces *courant = dernier->suivant;

	while (courant_source != dernier)
	{
		courant->suivant = new NoeudListePieces;
		courant->piece = Piece(courant_source->piece);
		courant = courant->suivant;
		courant_source = courant_source->suivant;
	}
	courant->suivant = dernier;
}

// -------------------------------------------------------------------------------------------------
//	Méthodes fournies
// -------------------------------------------------------------------------------------------------

/**
  * \fn Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream & entree)
  * \brief Fonction déjà fournie permettant de charger un labyrinthe depuis un fichier
  * \param[in] couleur La couleur du jouer auquel le labyrinthe chargé s'applique
  * \param[in] entree Fichier contenant la définition du labyrinthe
  */
void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
{
	int nbCols, nbRangs;

	if (!entree.is_open())
		throw logic_error("Labyrinthe::chargeLabyrinthe: Le fichier n'est pas ouvert !");

	entree >> nbCols >> nbRangs;
	entree.ignore(); // Pour consommer le \n (le caractère fin de ligne)

	const int MAX_LIGNE = 1000;
	char ligne[MAX_LIGNE];

	entree.getline(ligne, MAX_LIGNE);
	entree.getline(ligne, MAX_LIGNE);

	std::ostringstream s; // Une chaîne pour écrire dedans, cette chaîne servira pour nommer les pièces du labyrinthe

	for (int i = 0; i < nbCols; i++)
	{
		for (int j = 0; j < nbRangs; j++)
		{
			s << i << "," << j;
			Piece p(s.str());
			s.str("");
			ajoutePieceLabyrinthe(p);
		}
	}

	for (int i = 0; i < nbCols; i++)
	{
		if (ligne[i * 4 + 1] == 'D' || ligne[i * 4 + 1] == 'd')
		{
			std::string nom;
			s << i << ",0";
			nom = s.str();
			s.str("");
			placeDepart(nom);
		}
		if (ligne[i * 4 + 1] == 'F' || ligne[i * 4 + 1] == 'f' || ligne[i * 4 + 1] == 'A' || ligne[i * 4 + 1] == 'a')
		{
			std::string nom;
			s << i << ",0";
			nom = s.str();
			s.str("");
			placeArrivee(nom);
		}
	}

	for (int j = 0; j < nbRangs; j++)
	{
		entree.getline(ligne, MAX_LIGNE);

		for (int i = (j == nbRangs - 1 && (j & 1)) ? 1 : 0; i < nbCols; i++)
		{
			if (j & 1)
			{
				if (j < nbRangs - 2 && ligne[i * 4 + 3] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 2);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 1);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
				{
					ajoutePassage(couleur, i - 1, j, i, j + 1);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'D' || ligne[i * 4 + 1] == 'd'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeDepart(nom);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'F' || ligne[i * 4 + 1] == 'f' || ligne[i * 4 + 1] == 'A' || ligne[i * 4 + 1] == 'a'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeArrivee(nom);
				}
			}
			else
			{
				if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
				{
					ajoutePassage(couleur, i - 1, j + 1, i, j);
				}
				if (j < nbRangs - 2 && ligne[i * 4 + 1] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 2);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 1);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'D' || ligne[i * 4 + 3] == 'd'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeDepart(nom);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'F' || ligne[i * 4 + 3] == 'f' || ligne[i * 4 + 3] == 'A' || ligne[i * 4 + 3] == 'a'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeArrivee(nom);
				}
			}
		}
	}
}

/**
  * \fn Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
  * \brief Fonction déjà fournie permettant d'ajouter une porte à une pièce
  * \param[in]	Couleur couleur Couleur de la porte à ajouter
  * \param[in]	int i1
  * \param[in]	int j1
  * \param[in]	int i2
  * \param[in]	int j2
  */
void Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
{

	NoeudListePieces *piece1, *piece2;
	string nomPiece1, nomPiece2;
	ostringstream s;

	s << i1 << "," << j1;
	nomPiece1 = s.str();

	s.str("");

	s << i2 << "," << j2;
	nomPiece2 = s.str();

	s.str("");

	piece1 = trouvePiece(nomPiece1);
	piece2 = trouvePiece(nomPiece2);

	Porte nouvellePorte(couleur, &(piece2->piece));

	piece1->piece.ajoutePorte(nouvellePorte);
}

/**
  * \fn Labyrinthe::ajoutePieceLabyrinthe(Piece & p)
  * \brief Fonction déjà fournie permettant d'ajouter une pièce au labyrinthe (si elle ne s'y trouve pas déjà)
  * \param[in]	p La pièce à ajouter
  * \post	La pièce appartient au labyrinthe;
  */
void Labyrinthe::ajoutePieceLabyrinthe(const Piece &p)
{
	Labyrinthe::NoeudListePieces *noeud = new Labyrinthe::NoeudListePieces;
	noeud->piece = p;

	if (dernier == nullptr)
	{
		noeud->suivant = noeud;
		dernier = noeud;
	}
	else if (!appartient(p))
	{
		noeud->suivant = dernier->suivant;
		dernier->suivant = noeud;
	}
}

//Mettez l'implémentation de vos autres méthodes ici.

} // namespace TP1
