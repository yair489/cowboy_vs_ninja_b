/**
 * Implementation file of class "Point"
 */
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Character.hpp"

// "outline" constructor implementation:
using namespace ariel;

// "outline" method implementation:

bool Character::isAlive()
{
    if (_hitPointS > 0)
        return true;

    return false;
}
double Character::distance(const Character &other)
{
    return _position.distance(other._position);
}
void Character::hit(int hurt)
{
    if (hurt < 0)
        // throw invalid_argument("HURT<0");

        _hitPointS -= hurt;
}
std::string Character::print()
{
    std::string res = "";
    if (isAlive())
    {
        res = _name + std::to_string(_hitPointS) + _position.print();
    }
    else
    {
        res = "(" + _name + ")" + " position: " + _position.print();
    }
    return res;
}
