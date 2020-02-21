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

	if (dernier->piece.getNom() == nom)
	{
		depart = &(dernier->piece);
		return;
	}
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
	if (dernier->piece.getNom() == nom)
	{
		arrivee = &(dernier->piece);
		return;
	}
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
	if (dernier != nullptr)
	{
		NoeudListePieces *courant = dernier->suivant;
		NoeudListePieces *destructeur = courant;
		while (courant != dernier)
		{
			courant = courant->suivant;
			destructeur->suivant = nullptr;
			delete destructeur;
			destructeur = courant;
		}
		dernier->suivant = nullptr;
		delete dernier;
	}
	dernier = nullptr;
}

const Labyrinthe &Labyrinthe::operator=(const Labyrinthe &source)
{
	if (dernier != nullptr)
	{
		_detruire();
	}
	if (source.dernier != 0)
	{
		_copier(source);
	}
	return (*this);
}

bool Labyrinthe::appartient(const Piece &p) const
{
	if (dernier == nullptr)
	{
		return false;
	}
	NoeudListePieces *courant = dernier->suivant;
	while (courant != dernier)
	{
		if (courant->piece.getNom() == p.getNom())
		{
			return true;
		}
		courant = courant->suivant;
	}
	if (dernier->piece.getNom() == p.getNom())
	{
		return true;
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

	if (source.dernier == nullptr)
	{
		dernier = nullptr;
	}
	else
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
int Labyrinthe::solutionner(Couleur joueur)
{
	std::queue<Piece *> file;
	// 1
	depart->setDistanceDuDebut(0);
	file.push(depart);
	// 2
	Piece *courant = nullptr;
	while (!file.empty() && courant != arrivee)
	{
		courant = file.front();
		file.pop();

		const std::list<Porte> portes = courant->getPortes();

		for (const auto &val : portes)
		{

			if (val.getCouleur() == joueur)
			{

				if (!val.getDestination()->getParcourue())
				{

					val.getDestination()->setParcourue(true);
					val.getDestination()->setDistanceDuDebut(courant->getDistanceDuDebut() + 1);
					file.push(val.getDestination());
				}
			}
		}
	}

	if (courant != arrivee)
	{
		return -1;
	}
	return courant->getDistanceDuDebut();
}
Couleur Labyrinthe::trouveGagnant()
{
	const std::map<Couleur, int> joueurs = {{Couleur::Bleu, solutionner(Couleur::Bleu)},
											{Couleur::Rouge, solutionner(Couleur::Rouge)},
											{Couleur::Vert, solutionner(Couleur::Vert)},
											{Couleur::Jaune, solutionner(Couleur::Jaune)}};
	std::pair<std::vector<Couleur>, int> min = {{Couleur::Aucun}, std::numeric_limits<int>::max()};
	for (const auto &kv : joueurs)
	{
		if (kv.second < min.second)
		{
			min.first = std::vector<Couleur>(1, kv.first);
			min.second = kv.second;
		}
		else if (kv.second == min.second)
		{
			min.first.push_back(kv.first);
			min.second = kv.second;
		}
	}
	if (min.first.size() == 1)
	{
		return min.first[0];
	}
	else
	{
		return gagantAmbigue(min.first);
	}
}
Couleur Labyrinthe::gagantAmbigue(const std::vector<Couleur> &joueurs) const
{
	if (std::find(joueurs.begin(), joueurs.end(), Couleur::Rouge) != joueurs.end())
	{
		return Couleur::Rouge;
	}
	else if (std::find(joueurs.begin(), joueurs.end(), Couleur::Vert) != joueurs.end())
	{
		return Couleur::Vert;
	}
	else if (std::find(joueurs.begin(), joueurs.end(), Couleur::Bleu) != joueurs.end())
	{
		return Couleur::Bleu;
	}
	return Couleur::Jaune;
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
