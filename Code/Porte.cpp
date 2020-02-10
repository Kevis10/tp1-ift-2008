  
/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Porte
 * \author Étudiant(e)s
 * \version 0.1
 * \date janvier 2020
 *
 */

#include "Porte.h"

namespace TP1
{
/**
 * \fn Porte::Porte(Couleur c, Piece *d) : color(c), destination(d)
 * \param c couleur de la porte
 * \param d pointeur de la piece destination
 * constructeur de la porte avec une couleur et une piece destination define par l'utilisateur.
 */
Porte::Porte(Couleur c, Piece *d) : color(c), destination(d)
{
}
/**
 * \fn Porte::Porte(Couleur c, Piece *d) : color(c), destination(d)
 * constructeur de la porte par default, la Couleur AUCUN et un pointeur nulle sont
 * les parametres de l'instance 
 */
Porte::Porte() : color(Couleur::Aucun), destination(nullptr)
{
}
/**
 * Porte::Porte(const Porte&)
 * \param Porte porte a copier
 * constructeur de copie de la porte, cree une porte identique,mais independante
 */
Porte::Porte(const Porte &porte) : color(porte.getCouleur()), destination(porte.getDestination())
{
	distination = new Porte (*porte.distination);
}
/**
 * \fn const Porte & Porte::operator=(const Porte& source)
 * \param source porte a assigner
 * assigne une porte sur l'instance
 */
const Porte &Porte::operator=(const Porte &source)
{
	color = source.getCouleur();
	destination = source.getDestination();
	return *this;
}
/**
 * \fn bool Porte::operator==(const Porte &source) const
 * \param source porte a comparer
 * retourne vrai si les attributs sont identiques
 */
bool Porte::operator==(const Porte &source) const
{
	return color == source.getCouleur() && destination == source.getDestination();
}
/**
 * \fn Couleur Porte::getCouleur() const
 * ascesseur de la couleur de la Porte
 */
Couleur Porte::getCouleur() const
{
	return color;
}
/**
 * \fn Piece * Porte::getDestination() const
 * ascesseur de la destination de la Porte
 */
Piece *Porte::getDestination() const
{
	return destination;
}
/**
 * \fn Porte::~Porte()
 * destructeur de l'objet
 */
Porte::~Porte()
{
}


} // namespace TP1

