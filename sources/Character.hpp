/**
 * Header file of class "Character"
 */
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <stdio.h>
#include <iostream>
#include "Point.hpp"
// using namespace std;

#include <string>
namespace ariel
{
    class Character 
    {
        Point _position;
        int  _hitPointS;
        std::string _name;
        bool inteam;
        bool isleader;

    public:
        Character(const std::string &name = "",int health=0, double x = 0.0, double y = 0.0) : _name(name),_hitPointS(health), _position(x, y)
        {
        }
        Character(const std::string &name ,int health, Point p) : _name(name),_hitPointS(health), _position(p)
        {
        }

        // Character() {  _x = _y  = 0; }    // inline constructor
        // "outline" method

        bool isAlive();
        double distance(const Character &other);
        void hit(int hurt);
        std::string print();

                // inline method
        std::string getName()
        {
            return _name;
        }
        Point getLocation(const Character &other){
            return other._position;
        }
        bool inTeam(){return inteam;}
        bool isLeader(){return isleader;}
        void setInTeam(bool inTeamm){this->inteam=inTeamm;}
        void setisleader(bool leader){this->isleader=leader;}
    };
}
#endif 