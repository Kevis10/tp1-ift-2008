#include <gtest/gtest.h>
#include "Labyrinthe.h"
using namespace TP1;

class Studs : public ::testing::Test
{

protected:
    Labyrinthe *default_labyrinthe;

    virtual void SetUp()
    {
        default_labyrinthe = new Labyrinthe();
    }

    virtual void TearDown()
    {
        delete default_labyrinthe;
    }
};

TEST_F(Studs, GivenALabyrintheWhenConstructThenTheLabyrinhtheHasDefaultAttribute)
{
    ASSERT_EQ(default_labyrinthe->getSize(), 0);
    ASSERT_EQ(default_labyrinthe->getDernier(), nullptr);
    ASSERT_EQ(default_labyrinthe->getDepart(), nullptr);
    ASSERT_EQ(default_labyrinthe->getArrivee(), nullptr);
}