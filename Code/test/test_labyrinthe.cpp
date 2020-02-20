#include <gtest/gtest.h>
#include "Labyrinthe.h"
#include "Porte.h"
#include "Piece.h"
#include <string>
using namespace std;
using namespace TP1;


class Studs : public ::testing::Test
{

protected:
    Labyrinthe *default_labyrinthe;
    Labyrinthe *test_labyrinthe;
    Porte *porte_1;
    Porte *porte_2;
    Porte *porte_3;
   

    Piece *default_piece;
    Piece *nom_piece_test;
    Piece *piece_with_porte1;
    Piece *piece_with_porte2;
    Piece *piece_with_porte3;
    const string nom_attribute_piece = "Depart-test";
    const string nom_piece1 ="Debut";
    const string nom_piece2 ="Chambre";
    const string nom_piece3 ="Cuisine";
    const string default_nom = "";
    bool default_parcourue = false;
    int default_distanceDuDebut = 0;
    int tested_distanceDuDebut = 50;

    virtual void SetUp()
    {
        
        default_labyrinthe = new Labyrinthe();
        
        test_labyrinthe = new Labyrinthe();
        porte_1 = new Porte(Couleur::Bleu,piece_with_porte1);
        porte_2 = new Porte(Couleur::Rouge,piece_with_porte2);
        porte_3 = new Porte(Couleur::Vert,piece_with_porte3);
       

        default_piece = new Piece();
        nom_piece_test = new Piece(nom_attribute_piece);
        nom_piece_test->setParcourue(false);
        nom_piece_test->setDistanceDuDebut(0);

        piece_with_porte1 = new Piece(nom_piece1);
        piece_with_porte1->setDistanceDuDebut(100);
        piece_with_porte1->setParcourue(false);
        piece_with_porte1->ajoutePorte(*porte_2);
        piece_with_porte1->ajoutePorte(*porte_3);

        piece_with_porte2 = new Piece(nom_piece2);
        piece_with_porte2->setDistanceDuDebut(200);
        piece_with_porte2->setParcourue(false);

        piece_with_porte3 = new Piece(nom_piece3);
        piece_with_porte3->setDistanceDuDebut(300);
        piece_with_porte3->setParcourue(false);

        nom_piece_test->ajoutePorte(*porte_1);
        nom_piece_test->ajoutePorte(*porte_2);
        nom_piece_test->ajoutePorte(*porte_3);

        

        piece_with_porte2->ajoutePorte(*porte_1);
        piece_with_porte2->ajoutePorte(*porte_3);

        piece_with_porte3->ajoutePorte(*porte_1);
        piece_with_porte3->ajoutePorte(*porte_2);
        
        test_labyrinthe->ajoutePieceLabyrinthe(*nom_piece_test);
        test_labyrinthe->ajoutePieceLabyrinthe(*piece_with_porte1);
        test_labyrinthe->ajoutePieceLabyrinthe(*piece_with_porte2);
        test_labyrinthe->ajoutePieceLabyrinthe(*piece_with_porte3);

    }
/*
    virtual void TearDown()
    {
        delete default_labyrinthe;
        delete porte_1;
        delete porte_2;
        delete porte_3;
        delete default_piece;
        delete nom_piece_test;
        delete piece_with_porte1;
        delete piece_with_porte2;
        delete piece_with_porte3;
        delete test_labyrinthe;
        
    }
    */
};


TEST_F(Studs, GivenALabyrintheWhenConstructThenTheLabyrinhtheHasDefaultAttribute)
{
    ASSERT_EQ(1,1);
    ASSERT_EQ(default_labyrinthe->getDepart(), nullptr);
    ASSERT_EQ(default_labyrinthe->getArrivee(), nullptr);
}

TEST_F(Studs, TestConstructeurCopyEtAccesseurs)
{
    default_labyrinthe=test_labyrinthe;
    ASSERT_EQ(test_labyrinthe->getDepart(),default_labyrinthe->getDepart());
    ASSERT_EQ(test_labyrinthe->getDepart(),default_labyrinthe->getDepart());
}


TEST_F(Studs, TestMethodeAppartient)
{
    
    ASSERT_EQ(test_labyrinthe->appartient((*piece_with_porte1)),true);
    ASSERT_EQ(test_labyrinthe->appartient((*piece_with_porte2)),true);
    ASSERT_EQ(test_labyrinthe->appartient((*piece_with_porte3)),true);
    
}
