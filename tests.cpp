#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OList.h"

TEST_CASE("Testing insert()")
{
    OList *l1 = new OList();
    CHECK(l1->toString() == "nullptr");

    l1->insert(235);
    l1->insert(5423);
    l1->insert(1);
    l1->insert(-123);
    l1->insert(21);
    l1->insert(0);
    CHECK(l1->toString() == "-123 --> 0 --> 1 --> 21 --> 235 --> 5423 --> nullptr");

    l1->insert(-1);
    l1->insert(99999);
    CHECK(l1->toString() == "-123 --> -1 --> 0 --> 1 --> 21 --> 235 --> 5423 --> 99999 --> nullptr");

    delete l1;
}

TEST_CASE("Testing contains()")
{
    OList * l2 = new OList();

    CHECK(!l2->contains(9218490));

    l2->insert(0);
    l2->insert(1);
    l2->insert(2);
    CHECK(l2->contains(0));
    CHECK(l2->contains(1));
    CHECK(l2->contains(2));
    CHECK(!l2->contains(554837));

    delete l2;
}

TEST_CASE("Testing get()")
{
    OList * l3 = new OList();
    l3->insert(235);
    l3->insert(5423);
    l3->insert(1);
    l3->insert(-123);
    l3->insert(21);
    l3->insert(0);

    CHECK(l3->get(0) == -123);
    CHECK(l3->get(1) == 0);
    CHECK(l3->get(2) == 1);
    CHECK(l3->get(3) == 21);
    CHECK(l3->get(4) == 235);
    CHECK(l3->get(10) == -1); //out of bounds

    delete l3;
}

TEST_CASE("Testing remove()")
{
    OList * l4 = new OList();
    l4->insert(235);
    l4->insert(5423);
    l4->insert(1);
    l4->insert(-123);
    l4->insert(21);
    l4->insert(0);
    CHECK(l4->toString() == "-123 --> 0 --> 1 --> 21 --> 235 --> 5423 --> nullptr");

    l4->remove(2);
    CHECK(l4->toString() == "-123 --> 0 --> 21 --> 235 --> 5423 --> nullptr");

    l4->remove(1);
    l4->remove(1);
    CHECK(l4->toString() == "-123 --> 235 --> 5423 --> nullptr");

    CHECK_THROWS_AS(l4->remove(10), std::out_of_range); //out of bounds

    delete l4;
}

TEST_CASE("Testing reverse()")
{
    OList * l5 = new OList();
    
    l5->reverse();
    CHECK(l5->toString() == "nullptr");

    l5->insert(111);
    l5->reverse();
    CHECK(l5->toString() == "111 --> nullptr");

    delete l5;

    OList * l6 = new OList();
    l6->insert(235);
    l6->insert(5423);
    l6->insert(1);
    l6->insert(-123);
    l6->insert(21);
    l6->insert(0);

    l6->reverse();
    CHECK(l6->toString() == "5423 --> 235 --> 21 --> 1 --> 0 --> -123 --> nullptr");
    l6->reverse();
    CHECK(l6->toString() == "-123 --> 0 --> 1 --> 21 --> 235 --> 5423 --> nullptr");

    delete l6;
}