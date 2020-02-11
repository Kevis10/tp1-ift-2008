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
 * constructeur par default de la piece parcourue est faux, le nom est un chiffre aleatoire 
 * (aucune garantit que se nom soit unique) et la distance vers le debut est de 0
 */
Piece::Piece() : m_parcourue(false), m_nom(), m_distanceDuDebut(0)
{
}
/**
 * Piece::~Piece()
 * destucteur de l'instance
 */
Piece::~Piece()
{
}
/**
 * \fn Piece::Piece(const std::string & p_nom)
 * \param p_nom nom de la piece
 * constructeur par default de la piece parcourue est faux, le nom est definie par l'usager 
 * et la distance vers le debut est de 0
 */
Piece::Piece(const std::string &p_nom) : m_parcourue(false), m_nom(p_nom), m_distanceDuDebut(0)
{
}
/**
 * \fn int Piece::getDistanceDuDebut() const
 * retourne la distance de l'instance par rapport au debut du labyrinthe
 */
int Piece::getDistanceDuDebut() const
{
	return m_distanceDuDebut;
}
/**
 * \fn std::string Piece::getNom() const
 * retourne le nom de la piece en instance
 */
std::string Piece::getNom() const
{
	return m_nom;
}
/**
 * \fn bool Piece::getParcourue() const
 * retourne true si la piece a ete parcourus
 */
bool Piece::getParcourue() const
{
	return m_parcourue;
}
/**
 * \fn const std::list<Porte> & getPortes() const
 * retourne les porte de l'instance
 */
const std::list<Porte> &Piece::getPortes() const
{
	return m_portes;
}
/**
 * \fn void Piece::setParcourue(bool p)
 * \param p nouvel etat de parcouru
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
 * \param p_p porte
 * Ajoute une porte a la piece
 */
void Piece::ajoutePorte(const Porte &p_p)
{
	m_portes.push_front(p_p); //une copie de la porte passé en paramètre avec le constructeur copie(pas certain); sinon utiliser p_p directement
}
/**
 * \fn Piece::Piece(const Piece &p_source)
 * \param p_source piece a copier
 * construit une de Piece a partir d'une autre piece
 */
Piece::Piece(const Piece &p_source) : m_nom(p_source.m_nom), m_distanceDuDebut(p_source.m_distanceDuDebut),
									  m_parcourue(p_source.m_parcourue), m_portes(p_source.getPortes())
{
}
/**
 * \fn const Piece & Piece::operator=(const Piece & p_source)
 * \param p_source
 * surcharge de l'operateur egal
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
