/**
 * Character.
 * Character
 * Header file of class "YoungNinja "
 */
#ifndef TrainedNinja_HPP
#define TrainedNinja_HPP
#include <iostream>
#include "Ninja.hpp"
#include <iostream>
// using namespace std;
namespace ariel
{

    class TrainedNinja: public Ninja
    {
    

    public:


        // inline method


        // "outline" method
        TrainedNinja(std::string name, Point p):Ninja(name, 120, p,8){

        }
        TrainedNinja(const TrainedNinja &other):Ninja(other){

        }
        ~TrainedNinja(){

        }
        bool operator==(const TrainedNinja &other) const;

    };
}
#endif