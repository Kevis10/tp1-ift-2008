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
/**
 * \fn Piece::Piece()
 * constructeur par default de la piece parcourue est faux, le nom est un chiffre aleatoire 
 * (aucune garantit que se nom soit unique) et la distance vers le debut est de 0
 */
Piece::Piece() : parcourue(false), nom(std::to_string(std::rand())), distanceDuDebut(0)
{
}
/**
 * Piece::~Piece()
 * destucteur de l'instance
 */
Piece::~Piece()
{
}

//Mettez l'implémentation de vos méthodes ici.

} // namespace TP1
