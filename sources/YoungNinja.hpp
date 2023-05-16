/**
 * Header file of class "YoungNinja "
 */
#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP
#include <iostream>
#include "Ninja.hpp"
#include <iostream>
// using namespace std;
namespace ariel
{

    class YoungNinja: public Ninja
    {
    

    public:


        // inline method

        // "outline" method
        YoungNinja(std::string name, Point p):Ninja(name, 100, p,14){

        }
        YoungNinja(const YoungNinja &other):Ninja(other){

        }
        ~YoungNinja(){

        }
        bool operator==(const YoungNinja &other) const;

    };
}
#endif