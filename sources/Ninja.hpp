/**
 * Header file of class "YoungNinja "
 */
#ifndef NINJA_HPP
#define NINJA_HPP
#include <iostream>
#include "Character.hpp"
#include <iostream>
// using namespace std;
namespace ariel
{

    class Ninja : public Character
    {
        int _speed;

    public:
        Ninja();
        Ninja(const std::string &name = "", int health=10, double x = 0.0, double y = 0.0,int speed=1)
            : ariel::Character(name, 100, Point(x, y)), _speed(100)
        {
        }
        Ninja(const std::string &name, int health, Point p, int speed)
            : ariel::Character(name, 100, p), _speed(speed)
        {
        }
        Ninja(const Ninja &other)
            : Character(other), _speed(other._speed)
        {
        }

        // destructor
        ~Ninja() {}

        // inline method

        // "outline" method
        void move(Character *enemy);
        void slash(Character *enemy);

        int getSpeed() { return _speed; }
    };
}
#endif