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
 * \brief Constructeur par défaut de la classe Labyrinthe \n 
 * Assigne aux attributs depart, arrivee et dernier un pointeur nul "nullptr"
*/
Labyrinthe::Labyrinthe() : depart(nullptr), arrivee(nullptr), dernier(nullptr)
{
}

/**
 * \fn Labyrinthe::~Labyrinthe()
 * \brief Destructeur de la classe Labyrinthe , s'assure de libere la memoire des instances NoeudListePieces en appelant la méthode _detruire
 */

Labyrinthe::~Labyrinthe()
{
	_detruire();
}
/**
 * \fn void Labyrinthe::placeDepart(const std::string &nom)
 * \brief met le pointeur depart a la position de la piece de meme nom dans le Labyrinthe. \n
 *  Si la piece n'existe pas une exception logic_error est lance
 * \param[in] nom nom de la piece à placer comme étant le départ
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
/**
  * \fn void Labyrinthe::placeArrivee(const std::string &nom)
  * \brief met le pointeur arrivee à la position de la piece de meme nom dans le Labyrinthe
  * \param[in] nom nom de la piece à placer comme étant l'arrivée
*/
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
/**
  * \fn void Labyrinthe::_detruire()
  * \brief méthode de la classe Labyrinthe qui permet de détruire les instances alloueés dynamiquement
*/
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
/**
  * \fn  const Labyrinthe &Labyrinthe::operator=(const Labyrinthe &source)
  * \brief Surcharge de l'opérateur d'assignation pour la classe Labyrinthe
  * \param[in] source une instance de type labyrinthe passé par référence constante dont on souhaite faire l'assignation 
*/
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
/**
  * \fn bool Labyrinthe::appartient(const Piece &p) const
  * \brief Méthode de la classe Labyrinthe qui vérifie si une pièce appartient au Labyrinthe
  * \param[in] p une instance de type piece passée par référence constante
  * \return un booléen qui indique si la pièce appartient au labyrinthe ou non
*/
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
/**
  * \fn Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(const std::string &nom) const
  * \brief méthode permettant de retourner l'adresse du noeud de la liste de pièces contenue dans le labyrinthe qui correspond à la pièce portant le nom fournit
  * \param[in] nom de la pièce
*/
Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(const std::string &nom) const 
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
/**
  * \fn Labyrinthe::Labyrinthe(const Labyrinthe &source)
  * \brief  Constructeur copie de la classe Labyrinthe qui appelle la méthode _copier
  * \param[in] source une instance de type labyrinthe passé par référence constante
*/
Labyrinthe::Labyrinthe(const Labyrinthe &source)
{

	if (source.dernier == nullptr)
	{
		dernier = nullptr;
	}
	else
	{
		_copier(source);
	}
}
/**
  * \fn void Labyrinthe::_copier(const Labyrinthe &source)
  * \brief méthode de la classe Labyrinthe permettant de faire une deep copy d'une instance de type Labyrinthe
  * \param[in] source une instance de type Labyrinthe passée par référence constante
*/
void Labyrinthe::_copier(const Labyrinthe &source)
{
	try
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
	catch (const std::exception &)
	{
		_detruire();
	}
}
/**
  * \fn int Labyrinthe::solutionner(Couleur joueur)
  * \brief Méthode de la classe Labyrinthe qui permet de solutionner le labyrinthe pour un joueur d'une couleur donnée
  * \param[in] joueur une couleur 
  * \return un int qui indique en combien d'étapes le joueur peut solutionner le labyrinthe
*/
int Labyrinthe::solutionner(Couleur joueur)
{
	std::queue<Piece *> file;
	// 0 mettre tous les parcours a faux

	setTousParcoursFalse();
	// 1 commence par le depart
	depart->setParcourue(true);
	depart->setDistanceDuDebut(0);
	file.push(depart);
	// 2 resous le probleme
	Piece *courant = nullptr;

	do
	{
		courant = file.front();
		file.pop();
		const int distance_courante = courant->getDistanceDuDebut();

		std::list<Porte> portes = courant->getPortes();
		//cherche les piece adjacente
		chercherPortePieceDefiler(portes, joueur, file, distance_courante);
		// cherche les piece qui peuve se rendre a la piece courante
		chercherSiUnePieceQuiMenePieceCourante(file, courant);

	} while (!file.empty() && courant != arrivee);

	if (courant != arrivee)
	{
		return -1;
	}
	return courant->getDistanceDuDebut();
}
/**
  * \fn void Labyrinthe::chercherPortePieceDefiler(const std::list<Porte> &portes, Couleur joueur, std::queue<Piece *> &file, int distance_courante)
  * \brief méthode utilisée dans solutionner() afin de déterminer si une piece contient une porte de la couleur du joueur qui permet le passage vers la piece courante 
  * \param[in] portes une liste de portes
  * \param[in] joueur la couleur du joueur pour la quelle on souhaite trouver un passage existant
  * \param[in] file queue contenant des pointeurs de pieces
  * \param[in] distance_courante distance_courante actuelle
*/
void Labyrinthe::chercherPortePieceDefiler(const std::list<Porte> &portes, Couleur joueur, std::queue<Piece *> &file, int distance_courante)
{
	for (auto &porte : portes)
	{
		if (porte.getCouleur() == joueur)
		{
			if (!porte.getDestination()->getParcourue())
			{

				porte.getDestination()->setParcourue(true);
				porte.getDestination()->setDistanceDuDebut(distance_courante + 1);
				file.push(porte.getDestination());
			}
		}
	}
}
/**
  * \fn void Labyrinthe::chercherSiUnePieceQuiMenePieceCourante(std::queue<Piece *> &file, Piece *pieceCourante)
  * \brief méthode utiliseé dans solutionner() afin de déterminer si une piece permet le passage vers la piece courante 
  * \param[in] file queue contenant des pointeurs de pieces
  * \param[in] pieceCourante pointeur de la piece dont on cherche des passages y menant
*/
void Labyrinthe::chercherSiUnePieceQuiMenePieceCourante(std::queue<Piece *> &file, Piece *pieceCourante)
{
	NoeudListePieces *courant_parcours_complet = dernier->suivant;
	while (courant_parcours_complet != dernier)
	{
		Piece *piece_courante_parcours_complet = &(courant_parcours_complet->piece);
		if (piece_courante_parcours_complet->getParcourue() == false)
		{
			for (const auto &porte : piece_courante_parcours_complet->getPortes())
			{
				if (porte.getDestination() == pieceCourante)
				{
					piece_courante_parcours_complet->setDistanceDuDebut(pieceCourante->getDistanceDuDebut() + 1);
					file.push(piece_courante_parcours_complet);
				}
			}
		}
		courant_parcours_complet = courant_parcours_complet->suivant;
	}
}
/**
  * \fn void Labyrinthe::setTousParcoursFalse()
  * \brief Méthode mettant à false l'attribut parcourue de toutes les pieces du labyrinthes
*/
void Labyrinthe::setTousParcoursFalse()
{
	NoeudListePieces *courantIni = dernier->suivant;
	while (courantIni != dernier)
	{
		courantIni->piece.setParcourue(false);
		courantIni->piece.setDistanceDuDebut(0);
		courantIni = courantIni->suivant;
	}
	dernier->piece.setParcourue(false);
}
/**
  * \fn Couleur Labyrinthe::trouveGagnant()
  * \brief Méthode faisant 4 appels sur solutionner() pour déterminer quel joueur de Couleur solutionne le labyrinthe en moins d'étapes en faisant appelle à la méthode chercheMeilleurScore
*/
Couleur Labyrinthe::trouveGagnant()
{
	const std::map<Couleur, int> joueurs = {{Couleur::Bleu, solutionner(Couleur::Bleu)},
											{Couleur::Rouge, solutionner(Couleur::Rouge)},
											{Couleur::Vert, solutionner(Couleur::Vert)},
											{Couleur::Jaune, solutionner(Couleur::Jaune)}};
	return chercheMeilleurScore(joueurs);
}
/**
  * \fn Couleur Labyrinthe::chercheMeilleurScore(const std::map<Couleur, int> &joueurs)
  * \brief Méthode permettant de comparer les résultats des differents joueurs apres leur appel à la méthode solutionner
  * \param[in] joueurs une map <Couleur,int>
*/
Couleur Labyrinthe::chercheMeilleurScore(const std::map<Couleur, int> &joueurs)
{
	std::pair<std::vector<Couleur>, int> min = {{Couleur::Aucun}, std::numeric_limits<int>::max()};

	for (const auto &kv : joueurs)
	{
		if (kv.second < min.second && kv.second != -1)
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
/**
  * \fn Couleur Labyrinthe::gagantAmbigue(const std::vector<Couleur> &joueurs) const
  * \brief méthode utilisé dans le cas d'ambiguité dans la recherche du score d'un joueur pour solutionner un labyrinthe
  * \param[in] joueur un vecteur de couleur des joueurs
  * \return une couleur du gagnant dans le cas d'ambiguité
*/
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

} // namespace TP1
