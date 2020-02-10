/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Piece
 * \author Étudiant(e)
 * \version 0.1
 * \date janvier 2020
 *
 */

#include "Piece.h"

namespace TP1
{

//! Constructeur par défaut
Piece::Piece()
{
	//portes;
	m_parcourue = false;
	m_distanceDuDebut = 0;
}

//! Surcharge du constructeur
Piece::Piece(const std::string & p_nom):m_nom(p_nom)
{
	Piece();
}

//! Constructeur de copie
Piece::Piece(const Piece & p_source):m_nom(p_source.m_nom),m_distanceDuDebut(p_source.m_distanceDuDebut),m_parcourue(p_source.m_parcourue)
{
	list<Porte>::const_iterator it;
	for(it=p_source.m_portes.begin();it<p_source.m_portes.end();++it)
	{
		ajoutePorte(**it);
	}
}

//! Destructeur
Piece::~Piece()
{
	list<Porte>::iterator it;
	for(it=m_portes.begin();it<m_portes.end();++it)
	{
		erase(*it);
	}
}

//! Surcharge de l'opérateur =
const Piece & Piece::operator=(const Piece & p_source)
{
	if(this!=&p_source)
	{
		list<Porte>::iterator it;
		for(it=m_portes.begin();it<m_portes.end();++it)
		{
			delete *it
		}
		m_portes.clear()
		list<Porte> portes=p_source.m_portes;
		list<Porte>::iterator it_1;
		for(it=m_portes.begin();it<m_portes.end();++it)
		{
			ajoutePorte (**it)
		}
		m_parcourue=p_source.getParcourue();
		m_distanceDuDebut=p_source.getDistanceDuDebut();
		m_nom=p_source.getNom();
	}
	return this
	
}

//! Accesseur du nom d'une pièce
std::string Piece::getNom() const
{
	return m_nom;
}

//! Pour initialiser l'attribut parcourue à true ou false
void Piece::setParcourue(bool p)
{
	m_parcourue=p;
}

//! Pour initialiser l'attribut distanceDuDebut
void Piece::setDistanceDuDebut(int p_d)
{
	m_distanceDuDebut=p_d;
}

//! Accéder au membre parcourue
bool Piece::getParcourue() const
{
	return m_parcourue;
}

//! Accéder à la liste des portes qui partent de la pièce
const std::list<Porte> & Piece::getPortes() const
{
	return m_portes;
}

//! Accéder au membre distanceDuDebut
int Piece::getDistanceDuDebut() const
{
	return m_distanceDuDebut;
}

//! Ajouter une porte à la liste des portes qui partent de la pièce
void Piece::ajoutePorte(const Porte & p_p)
{
	m_portes.push_front(Porte(p_p)) //une copie de la porte passé en paramètre avec le constructeur copie(pas certain); sinon utiliser p_p directement
}

}
