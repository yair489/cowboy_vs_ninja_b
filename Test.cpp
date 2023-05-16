#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Point.hpp"
using namespace ariel;
// /*
// CHECK()
// CHECK_GE()
// CHECK_LE()
// CHECK_FALSE()
// CHECK_EQ()
// CHECK_NE()
// CHECK_THROWS_AS()
// CHECK_NOTHROW()
// #include "sources/Fraction.hpp"
// */

TEST_SUITE("constructor")
{

    TEST_CASE("Point")
    {
        CHECK_NOTHROW(Point param(0, 0));
        CHECK_NOTHROW(Point param(1.2, 4567));
        CHECK_NOTHROW(Point param(1.89, 90.0));
    }
    TEST_CASE("character")
    {
        Point p1(1, 1);
        CHECK_NOTHROW(Character c("yair", 100, 0.0, 0.0));
        CHECK_NOTHROW(Character c("yair", 100, Point(1, 3)));
        CHECK_NOTHROW(Character c("yair", 100, p1));
    }
    TEST_CASE("Ninja")
    {
        CHECK_NOTHROW(Ninja c("yair", 10, 0.0, 0.0, 1));
        CHECK_NOTHROW(Ninja c1("yair", 10, Point(0.0, 0.0), 1));
        Ninja c3("yair", 10, Point(0.0, 0.0), 1);
        CHECK_NOTHROW(Ninja c2(c3));
    }
    TEST_CASE("oldninja")
    {
        CHECK_NOTHROW(OldNinja o1("yair", Point(1, 1)));
        OldNinja o1("yair", Point(1, 1));
        CHECK_NOTHROW(OldNinja o2(o1));
    }
    TEST_CASE("youngninja")
    {
        CHECK_NOTHROW(YoungNinja Y1("yair", Point(1, 1)));
        YoungNinja y1("yair", Point(1, 1));
        CHECK_NOTHROW(YoungNinja o2(y1));
    }
    TEST_CASE("TrainedNinja")
    {
        Point p3(1, 3);
        CHECK_NOTHROW(TrainedNinja Y1("yair", Point(1, 1)));
        TrainedNinja y1("yair", Point(1, 1));
        CHECK_NOTHROW(TrainedNinja o2(y1));
        CHECK_NOTHROW(TrainedNinja o2("y1)", p3));
    }

    TEST_CASE("cowboy")
    {
        Point p3(1, 3);
        CHECK_NOTHROW(Cowboy Y1("yair", Point(1, 1)));
        Cowboy y1("yair", Point(1, 1));
        CHECK_NOTHROW(Cowboy o2(y1));
        CHECK_NOTHROW(Cowboy o2("y1)", p3));
        CHECK_NOTHROW(Cowboy Y1("yair", 10, 1, 1));
    }
}

TEST_SUITE("class Point")
{

    TEST_CASE("")
    {
        Point p0(0, 0);
        Point p15(0, 15);
        Point p15b(15, 0);
        Point p1(1, 1);
        Point p11(1, 4);
        Point p2(2, 2);

        SUBCASE("distance")
        {
            CHECK_EQ(p1.distance(p11), 3);
            CHECK_EQ(p0.distance(p15), 15);
            CHECK_EQ(p0.distance(p15), p0.distance(p15b));
            CHECK_EQ(p0.distance(p15), p15.distance(p15b));
        }
        SUBCASE("getx")
        {
            CHECK_EQ(p0.getX(), 0);
            CHECK_EQ(p15.getX(), 0);
            CHECK_EQ(p15b.getX(), 15);
            CHECK_EQ(p1.getX(), 1);
            CHECK_EQ(p11.getX(), 1);
            CHECK_EQ(p2.getX(), 2);
        }
        SUBCASE("gety")
        {
            CHECK_EQ(p0.getY(), 0);
            CHECK_EQ(p15.getY(), 15);
            CHECK_EQ(p15b.getY(), 0);
            CHECK_EQ(p1.getY(), 1);
            CHECK_EQ(p11.getY(), 4);
            CHECK_EQ(p2.getY(), 2);
        }
    }
}
TEST_SUITE("chrecter")
{
    TEST_CASE("chrecter")
    {
        Character c1("yair1", 100, Point(0, 1));
        Character c2("yair2", 200, Point(0, 2));
        Character c3("yair2", 200, Point(0, 3));
        Character c4("yair2", 200, Point(0, 4));
        Character c5("yair2", 200, Point(0, 5));

        SUBCASE("is alive ")
        {
            CHECK(c1.isAlive());
            CHECK(c2.isAlive());
            CHECK(c3.isAlive());
            CHECK(c4.isAlive());
            CHECK(c5.isAlive());
        }

        SUBCASE("distance")
        {
            CHECK_EQ(c1.distance(c2), 1);
            CHECK_EQ(c2.distance(c3), 1);
            CHECK_EQ(c3.distance(c4), 1);
            CHECK_EQ(c4.distance(c5), 1);
            CHECK_EQ(c5.distance(c4), 1);
            CHECK_EQ(c1.distance(c5), 4);
            CHECK_EQ(c1.distance(c4), 3);
            CHECK_EQ(c2.distance(c2), 0);
        }
        SUBCASE("get name")
        {
            CHECK_EQ(c1.getName(), "yair1");
            CHECK_EQ(c2.getName(), "yair2");
            CHECK_EQ(c3.getName(), "yair3");
            CHECK_EQ(c4.getName(), "yair4");
            CHECK_EQ(c5.getName(), "yair5");
        }
    }
}

TEST_SUITE("young ninja")
{

    TEST_CASE("")
    {
        YoungNinja y1("yair1", Point(0, 1));
        YoungNinja y2("yair2", Point(0, 10));
        YoungNinja y3("yair3", Point(0, 20));
        YoungNinja y33("yair3", Point(0, 20));
        YoungNinja y4(y2);
        YoungNinja y5(y3);
        YoungNinja y6("yair6", Point(0, 650));
        YoungNinja y7("yair7", Point(35.467, 1000));

        SUBCASE("equal")
        {
            CHECK_EQ(y4, y2);
            CHECK_EQ(y5, y3);
            CHECK_EQ(y3, y33);
        }

        SUBCASE("distance")
        {
            CHECK_EQ(y2.distance(y3), 10);
            CHECK_EQ(y2.distance(y33), 10);
            CHECK_EQ(y2.distance(y6), 630);
            CHECK_EQ(y7.distance(y3), y33.distance(y7));
            CHECK_EQ(y2.distance(y2), 0);
        }
        SUBCASE("speed")
        {
            CHECK_EQ(y1.getSpeed(), 14);
            CHECK_EQ(y2.getSpeed(), 14);
            CHECK_EQ(y3.getSpeed(), 14);
            CHECK_EQ(y4.getSpeed(), 14);
            CHECK_EQ(y33.getSpeed(), 14);
            CHECK_EQ(y5.getSpeed(), 14);
            CHECK_EQ(y6.getSpeed(), 14);
            CHECK_EQ(y7.getSpeed(), 14);
        }
    }
}

TEST_SUITE("old ninja")
{

    TEST_CASE("")
    {
        OldNinja y1("yair1", Point(0, 1));
        OldNinja y2("yair2", Point(0, 10));
        OldNinja y3("yair3", Point(0, 20));
        OldNinja y33("yair3", Point(0, 20));
        OldNinja y4(y2);
        OldNinja y5(y3);
        OldNinja y6("yair6", Point(0, 650));
        OldNinja y7("yair7", Point(35.467, 1000));

        SUBCASE("equal")
        {
            CHECK_EQ(y4, y2);
            CHECK_EQ(y5, y3);
            CHECK_EQ(y3, y33);
        }

        SUBCASE("distance")
        {
            CHECK_EQ(y2.distance(y3), 10);
            CHECK_EQ(y2.distance(y33), 10);
            CHECK_EQ(y2.distance(y6), 630);
            CHECK_EQ(y7.distance(y3), y33.distance(y7));
            CHECK_EQ(y2.distance(y2), 0);
        }
        SUBCASE("speed")
        {
            CHECK_EQ(y1.getSpeed(), 8);
            CHECK_EQ(y2.getSpeed(), 8);
            CHECK_EQ(y3.getSpeed(), 8);
            CHECK_EQ(y4.getSpeed(), 8);
            CHECK_EQ(y33.getSpeed(), 8);
            CHECK_EQ(y5.getSpeed(), 8);
            CHECK_EQ(y6.getSpeed(), 8);
            CHECK_EQ(y7.getSpeed(), 8);
        }
    }
}

TEST_SUITE("Cowboy")
{

    TEST_CASE("")
    {
        Cowboy y1("yair1", Point(0, 1));
        Cowboy y2("yair2", Point(0, 10));
        Cowboy y3("yair3", Point(0, 20));
        Cowboy y33("yair3", Point(0, 20));
        Cowboy y4(y2);
        Cowboy y5(y3);
        Cowboy y6("yair6", Point(0, 650));
        Cowboy y7("yair7", Point(35.467, 1000));
        Character *y8;
        y8 = &y7;

        SUBCASE("equal")
        {
            CHECK_EQ(y4, y2);
            CHECK_EQ(y5, y3);
            CHECK_EQ(y3, y33);
        }

        SUBCASE("distance")
        {
            CHECK_EQ(y2.distance(y3), 10);
            CHECK_EQ(y2.distance(y33), 10);
            CHECK_EQ(y2.distance(y6), 630);
            CHECK_EQ(y7.distance(y3), y33.distance(y7));
            CHECK_EQ(y2.distance(y2), 0);
        }
        SUBCASE("getquantityBullets")
        {
            CHECK_EQ(y1.getquantityBullets(), 6);
            CHECK_EQ(y2.getquantityBullets(), 6);
            CHECK_EQ(y3.getquantityBullets(), 6);
            CHECK_EQ(y33.getquantityBullets(), 6);
            CHECK_EQ(y4.getquantityBullets(), 6);
            CHECK_EQ(y5.getquantityBullets(), 6);
            CHECK_EQ(y6.getquantityBullets(), 6);
            CHECK_EQ(y7.getquantityBullets(), 6);
            CHECK_NE(y1.getquantityBullets(), 8);
        }
        SUBCASE("get quantity Bullets")
        {
            for (int i = 0; i < 6; i++)
            {
                CHECK_EQ(y1.getquantityBullets(), 6 - i);
                y1.shoot(y8);
            }
        }
    }
}

    TEST_SUITE("team")
    {
        TEST_CASE("")
        {
            Cowboy y1("yair1", Point(0, 1));
            Cowboy y2("yair2", Point(0, 10));
            Cowboy y3("yair3", Point(0, 20));
            Cowboy y33("yair3", Point(0, 20));
            Cowboy y4(y2);
            Cowboy y5(y3);
            Cowboy y6("yair6", Point(0, 650));
            Cowboy y7("yair7", Point(35.467, 1000));
            Character *y8;
            y8 = &y7;
            OldNinja t1("yair1", Point(0, 1));
            OldNinja t2("yair2", Point(0, 10));
            OldNinja t3("yair3", Point(0, 20));
            OldNinja t33("yair3", Point(0, 20));
            Character *r1 =&y1;
            Character *r2=&y2;
            Character *r3=&y3;
            Character *r4=&y4;
            Character *r5=&y5;
            Character *r6=&y6;
            Character *r8=&y7;

            Character *r9=&y1;
            Character *r10=&t1;
            Character *r11=&t2;
            Character *r12=&t3;
        


            SUBCASE("")
            {
                Team te(r1);
                CHECK_NOTHROW(te.add(r1));
                CHECK_NOTHROW(te.add(r2));
                CHECK_NOTHROW(te.add(r3));
                CHECK_NOTHROW(te.add(r4));
                CHECK_NOTHROW(te.add(r5));
                CHECK_NOTHROW(te.add(r6));
                CHECK_NOTHROW(te.add(r12));
                CHECK_NOTHROW(te.add(r8));
                CHECK_NOTHROW(te.add(r9));
                CHECK_NOTHROW(te.add(r10));
                CHECK_THROWS(te.add(r11));


            }

            SUBCASE("")
            {
                Team te1(r1);
                CHECK_NOTHROW(te1.add(r1));
                CHECK_THROWS(te1.add(r1));
            }
        }
    }