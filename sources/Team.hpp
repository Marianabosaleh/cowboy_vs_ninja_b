#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
using namespace std;
namespace ariel
{
    class Team
    {
        std::vector<Character *> team;
        Character *leader;
    
    public:
        Team();
        Team(Character *leader);

        // Copy constructor
        Team(const Team &other);

        // Copy assignment operator
        Team &operator=(const Team &other);

        // Move constructor
        Team(Team &&other) noexcept;

        // Move assignment operator
        Team &operator=(Team &&other) noexcept;
        //getter setter
        Character *getleader() const;
        void setleader(Character *new_leader);
        //functions
        void add(Character *character);
        void attack(Team *enemys);
        int stillAlive();
        virtual string print();
        Character *closestTo(Point location);
        Character *closestAliveTo(Point location);
        ~Team();
    };
}
