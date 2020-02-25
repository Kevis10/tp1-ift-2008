  
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
 * \brief Constructeur avec paramètres de porte prenant une couleur et un pointeur de piece destination définie par l'utilisateur.
 * \param[in] c couleur de la porte
 * \param[in] d pointeur de la piece destination
 */
Porte::Porte(Couleur c, Piece *d) : color(c), destination(d)
{
}
/**
 * \fn Porte::Porte(Couleur c, Piece *d) : color(c), destination(d)
 * \brief Constructeur de porte par default, l'attribut Color prend la valeur par défaut "Aucin" et l'attribut destination un pointeur nul.
 */
Porte::Porte() : color(Couleur::Aucun), destination(nullptr)
{
}
/**
 * \fn Porte::Porte(const Porte&)
 * \brief Constructeur copie de la classe Porte,cree une porte identique,mais independante.
 * \param[in] porte, un objet porte passé par référence constante duquel on veut faire une copie .
 */
Porte::Porte(const Porte &porte) : color(porte.getCouleur()), destination(porte.getDestination())
{
}
/**
 * \fn const Porte & Porte::operator=(const Porte& source)
 * \brief Surcharge de l'opérateur d'assignation afin de pouvoir assigner des objets de type porte.
 * \param[in] source ,un objet de type porte passé par référence constante.
 * \return l'objet de type porte copié.
 */
const Porte &Porte::operator=(const Porte &source)
{
	color = source.getCouleur();
	destination = source.getDestination();
	return *this;
}
/**
 * \fn bool Porte::operator==(const Porte &source) const.
 * \brief surcharge de l'opérateur d'égalité "==", afin de comparer des objets de type porte.
 * \param[in] source ,objet de type porte  passé par référence constante.
 * \return un booléen qui est à true si les portes comparées sont identiques, false sinon.
 */
bool Porte::operator==(const Porte &source) const
{
	return color == source.getCouleur() && destination == source.getDestination();
}
/**
 * \fn Couleur Porte::getCouleur() const
 * \brief Accesseur de l'attribut Color de la classe Porte
 * \return l'attribut color
 */
Couleur Porte::getCouleur() const
{
	return color;
}
/**
 * \fn Piece * Porte::getDestination() const
 * \brief Accesseur de l'attribut destination de la classe Porte
 * \return l'attribut destination
 */
Piece *Porte::getDestination() const
{
	return destination;
}
/**
 * \fn Porte::~Porte()
 * \brief destructeur de la classe Porte
 */
Porte::~Porte()
{
}


} // namespace TP1

