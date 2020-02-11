#include <gtest/gtest.h>
#include "Porte.h"
#include "Piece.h"
#include <iostream>
#include "string"

using namespace TP1;
using namespace std;

class Studs : public ::testing::Test
{

protected:
    Porte *porte_1;
    Porte *porte_2;
    Porte *porte_3;
    Porte *porte_4;

    Piece *default_piece;
    Piece *nom_piece;
    Piece *piece_with_porte;
    const string nom_attribute_piece = "aaa";
    const string default_nom = "";
    bool default_parcourue = false;
    int default_distanceDuDebut = 0;
    int tested_distanceDuDebut = 55;

    virtual void SetUp()
    {
        porte_1 = new Porte();
        porte_2 = new Porte();
        porte_3 = new Porte();
        porte_4 = new Porte();

        default_piece = new Piece();
        nom_piece = new Piece(nom_attribute_piece);
        piece_with_porte = new Piece(nom_attribute_piece);
        piece_with_porte->ajoutePorte(*porte_1);
        piece_with_porte->ajoutePorte(*porte_2);
        piece_with_porte->ajoutePorte(*porte_3);
        piece_with_porte->ajoutePorte(*porte_4);
    }

    virtual void TearDown()
    {
        delete porte_1;
        delete porte_2;
        delete porte_3;
        delete porte_4;
        delete default_piece;
        delete nom_piece;
        delete piece_with_porte;
    }
};

TEST_F(Studs, GivenNoAttributWhenConstructingAPieceThenDefaultAttributeAreSet)
{
    ASSERT_EQ(default_piece->getParcourue(), default_parcourue);
    ASSERT_EQ(default_piece->getDistanceDuDebut(), default_distanceDuDebut);
    ASSERT_EQ(default_piece->getPortes().size(), 0);
    ASSERT_EQ(default_piece->getNom(), default_nom);
}
TEST_F(Studs, GivenANomWhenConstructingAPieceThenDefaultAttributeAreSet)
{
    ASSERT_EQ(nom_piece->getParcourue(), default_parcourue);
    ASSERT_EQ(nom_piece->getDistanceDuDebut(), default_distanceDuDebut);
    ASSERT_EQ(nom_piece->getPortes().size(), 0);
    ASSERT_EQ(nom_piece->getNom(), nom_attribute_piece);
}
TEST_F(Studs, GivenAPieceWhenChangingParcourueAttributeThenTheAttributeIsChangeAccordingly)
{
    default_piece->setParcourue(false);
    ASSERT_EQ(default_piece->getParcourue(), false);
    default_piece->setParcourue(true);
    ASSERT_EQ(default_piece->getParcourue(), true);
}
TEST_F(Studs, GivenAPieceWhenChangingDistanceDuDebutTheTheAttributeIsChangeAccordingly)
{
    default_piece->setDistanceDuDebut(tested_distanceDuDebut);
    ASSERT_EQ(default_piece->getDistanceDuDebut(), tested_distanceDuDebut);
}
TEST_F(Studs, GivenAPieceWhenAddingAPorteThenThePieceHaveTheAddedPorte)
{
    default_piece->ajoutePorte(*porte_1);
    ASSERT_EQ(default_piece->getPortes().front(), *porte_1);
    ASSERT_EQ(default_piece->getPortes().size(), 1);

    default_piece->ajoutePorte(*porte_2);

    ASSERT_EQ(default_piece->getPortes().front(), *porte_2);
    ASSERT_EQ(default_piece->getPortes().size(), 2);
}
TEST_F(Studs, GivenAPieceWhenConstruitingItWithAnoterPieceThenThePieceIsTheSame)
{
    Piece current(*piece_with_porte);

    ASSERT_EQ(current.getParcourue(), piece_with_porte->getParcourue());
    ASSERT_EQ(current.getDistanceDuDebut(), piece_with_porte->getDistanceDuDebut());
    ASSERT_EQ(current.getPortes(), piece_with_porte->getPortes());
    ASSERT_EQ(current.getNom(), piece_with_porte->getNom());
}
TEST_F(Studs, GivenAPieceWhenAssignatingAnotherPieceThereValueAreEqualAndIndependant)
{
    Piece current;
    current = *piece_with_porte;

    ASSERT_EQ(current.getParcourue(), piece_with_porte->getParcourue());
    ASSERT_EQ(current.getDistanceDuDebut(), piece_with_porte->getDistanceDuDebut());
    ASSERT_EQ(current.getPortes(), piece_with_porte->getPortes());
    ASSERT_EQ(current.getNom(), piece_with_porte->getNom());

    current.ajoutePorte(*porte_1);
    ASSERT_NE(current.getPortes(), piece_with_porte->getPortes());

}
