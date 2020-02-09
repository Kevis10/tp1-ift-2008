#include <gtest/gtest.h>
#include "Porte.h"
#include "Piece.h"
#include <iostream>

using namespace TP1;

class Studs : public ::testing::Test
{

protected:
    Porte *default_porte;
    Piece *default_piece;
    Couleur default_couleur = Couleur::Rouge;
    Couleur no_couleur = Couleur::Aucun;
    Porte *argument_porte;
    virtual void SetUp()
    {
        default_porte = new Porte();
        argument_porte = new Porte(default_couleur, default_piece);
    }

    virtual void TearDown()
    {
        delete default_porte;
        delete argument_porte;
    }
};

TEST_F(Studs, GivenACouleurAndAPieceWhenInstantiateAPorteThenCouleurAndPieceAttributeAreTheSame)
{
    ASSERT_EQ(argument_porte->getCouleur(), default_couleur);
    ASSERT_EQ(argument_porte->getDestination(), default_piece);
}
TEST_F(Studs, GivenNoArgumentWhenInstantiateAPorteThenAucunCouleurAndDestinationIsNullPointer)
{
    ASSERT_EQ(default_porte->getCouleur(), no_couleur);
    ASSERT_EQ(default_porte->getDestination(), nullptr);
}
TEST_F(Studs, GivenAPorteWhenInstantiateAporteByCopyThenThePorteHaveTheSameValue)
{
    Porte copie_porte(*argument_porte);

    ASSERT_EQ(copie_porte.getCouleur(),argument_porte->getCouleur());
    ASSERT_EQ(copie_porte.getDestination(),argument_porte->getDestination());
}
TEST_F(Studs,GivenAPorteWhenAsignItWithAnOtherPorteThenThePorteHaveTheSameAttribute)
{
    Porte courant;
    courant=*argument_porte;
    ASSERT_EQ(courant.getCouleur(),argument_porte->getCouleur());
    ASSERT_EQ(courant.getDestination(),argument_porte->getDestination());
}
TEST_F(Studs,GivenTwoPorteIdenticalPorteWhenCheckingIfTheyAreEqualThenTrueIsReturned)
{
    ASSERT_TRUE(default_porte==default_porte);
    ASSERT_TRUE(argument_porte==argument_porte);
}
TEST_F(Studs,GivenTwoPorteNonIdenticalPorteWhenCheckingIfTheyAreEqualThenFalseIsReturned)
{
    ASSERT_FALSE(argument_porte==default_porte);
    ASSERT_FALSE(default_porte==argument_porte);
}