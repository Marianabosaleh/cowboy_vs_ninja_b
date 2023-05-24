#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Character.hpp"
#include "Point.hpp"
using namespace std;
namespace ariel
{
    class Cowboy : public Character
    {
        int balls;

    public:
        // Default constructor
        Cowboy();
        // Constructor with location and name
        Cowboy(string name, Point location);
        // destructor
        ~Cowboy(void);
        // Getter and Setter
        int getballs();
        void setballs(int balls);
        // functions
        void shoot(Character *anamy);
        bool hasboolets();
        void reload();
        string print() override;
    };
}