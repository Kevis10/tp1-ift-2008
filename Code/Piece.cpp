/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Piece
 * \author Étudiant(e)
 * \version 0.1
 * \date janvier 2020
 *
 */

#include "Piece.h"
using namespace std;
namespace TP1
{

/**
 * \fn Piece::Piece()
 * \brief Constructeur par défault de la classe Piece \n 
 * L'attribut m_parcourue est mis à "false", l'attribut m_nom à une chaine vide et l'attribut m_distanceDuDebut est initialisé à 0.
 */
Piece::Piece() : m_parcourue(false), m_nom(""), m_distanceDuDebut(0)
{
}
/**
 * \fn Piece::~Piece()
 * \brief destucteur de la classe Piece
 */
Piece::~Piece()
{
}
/**
 * \fn Piece::Piece(const std::string & p_nom)
 * \brief constructeur avec paramètre de la classe Piece.
 * \param[in] p_nom nom de l'instance piece
 * 
 */
Piece::Piece(const std::string &p_nom) : m_parcourue(false), m_nom(p_nom), m_distanceDuDebut(0)
{
}
/**
 * \fn int Piece::getDistanceDuDebut() const
 * \brief Accesseur de l'attribut m_distanceDuDebut de la classe Piece
 * \return m_distanceDuDebut la distance de l'instance Piece par rapport au debut du labyrinthe
 */
int Piece::getDistanceDuDebut() const
{
	return m_distanceDuDebut;
}
/**
 * \fn std::string Piece::getNom() const
 * \Accesseur de l'attrbut m_nom de la classe Piece
 * \return m_nom le nom de l'instance de type piece
 */
std::string Piece::getNom() const
{
	return m_nom;
}
/**
 * \fn bool Piece::getParcourue() const
 * \brief Accesseur de l'attribut m_parcourue de la classe Piece
 * \return m_parcourue un booléen qui indique si l'instance de type pièce à été parcourue ou non
 */
bool Piece::getParcourue() const
{
	return m_parcourue;
}
/**
 * \fn const std::list<Porte> & getPortes() const
 * \brief Accesseur de l'attribut m_portes de la classe Piece
 * \return m_portes une liste des porte de l'instance de type Piece
 */
const std::list<Porte> &Piece::getPortes() const
{
	return m_portes;
}
/**
 * \fn void Piece::setParcourue(bool p)
 * \brief Mutateur de l'attribut m_parcourue de la classe Piece
 * \param[in] p un booléen nouvel etat de parcouru
 * Change l'etat de m_parcouru 
 */
void Piece::setParcourue(bool p)
{
	m_parcourue = p;
}
/**
 * \fn void Piece::setDistanceDuDebut(int p_d)
 * \param p_d distance par rapport au debut
 * change la distance du debut
 */
void Piece::setDistanceDuDebut(int p_d)
{
	m_distanceDuDebut = p_d;
}
/**
 * \fn void Piece::ajoutePorte(const Porte & p_p)
 * \brief Permet d'ajouter une porte à la liste de portes de la piece
 * \param[in] p_p une porte passé par référence constante
 */
void Piece::ajoutePorte(const Porte &p_p)
{
	m_portes.push_front(p_p); //une copie de la porte passé en paramètre avec le constructeur copie(pas certain); sinon utiliser p_p directement
}
/**
 * \fn Piece::Piece(const Piece &p_source)
 * \brief Constructeur copie  de la classe Piece,permet de construire une copie profonde d'une piece passée en paramètre
 * \param[in] p_source la piecea à copier passé par référence constante
 */
Piece::Piece(const Piece &p_source) : m_nom(p_source.m_nom), m_distanceDuDebut(p_source.m_distanceDuDebut),
									  m_parcourue(p_source.m_parcourue), m_portes(p_source.getPortes())
{
}
/**
 * \fn const Piece & Piece::operator=(const Piece & p_source)
 * \brief Surcharge de l'operateur d'assignation pour la classe Piece. 
 * \param[int] p_source une instance de type piece passé par référence constante dont on souhaite faire l'assignation
 * \return une piece apres copie
 */
const Piece &Piece::operator=(const Piece &p_source)
{
	if (this != &p_source)
	{
		m_nom = p_source.getNom();
		m_distanceDuDebut = p_source.getDistanceDuDebut();
		m_parcourue = p_source.getParcourue();
		m_portes = p_source.getPortes();
	}
	return *this;
}
} // namespace TP1
