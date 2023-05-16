
#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <vector>

#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
namespace ariel
{

    class Team
    {
        Character *leader;
    public:

        Team(Character *leader): leader(leader){

        }
        std::vector <Character> team;
        

        
        void add(Character *player);
        void attack(Team * enemy);
        int stillAlive();
        void print();
        

    };

}
#endif