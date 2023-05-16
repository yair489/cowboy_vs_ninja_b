/**
 * Header file of class "YoungNinja "
 */
#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP
#include <iostream>
#include "Ninja.hpp"
#include <iostream>
// using namespace std;
namespace ariel
{

    class OldNinja: public Ninja
    {
    

    public:


        // inline method

        // "outline" method
        OldNinja(std::string name, Point p):Ninja(name, 150, p,8){

        }
        OldNinja(const OldNinja &other):Ninja(other){

        }
        ~OldNinja(){

        }
        bool operator==(const OldNinja &other) const;

    };
}
#endif