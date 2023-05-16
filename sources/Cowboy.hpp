/**
 * Header file of class "YoungNinja "
 */
#ifndef COWBOY_HPP
#define COWBOY_HPP
#include <iostream>
#include "Character.hpp"
#include <iostream>
// using namespace std;
namespace ariel
{

    class Cowboy : public Character
    {
        int _quantity_bullets;

    public:
        Cowboy();
        Cowboy(const std::string &name = "", int health=6, double x = 0.0, double y = 0.0)
            : ariel::Character(name, 110, Point(x, y)), _quantity_bullets(6)
        {
        }
        Cowboy(const std::string &name, Point p)
            : ariel::Character(name, 100, p), _quantity_bullets(6)
        {
        }
        Cowboy(const Cowboy &other)
            : Character(other), _quantity_bullets(6)
        {
        }
        bool operator==(const Cowboy &other) const{
            return true;
        }
        // destructor
        ~Cowboy() {}

        // inline method

        // "outline" method
        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
        void slash(Character *enemy);

        int getquantityBullets() { return _quantity_bullets; }
    };
}
#endif