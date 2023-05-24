#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Point.hpp"
using namespace std;

namespace ariel
{

    class Character
    {
        Point location;
        int hit_point;
        string name;

    public:
        bool isleader = false;
        bool isteam_member = false;
        // constructors
        Character();
        Character(string name, Point location);
        Character(Point location, string name);
        // Copy constructor
        Character(const Character &other);
        // Move constructor
        Character(Character &&other) noexcept;
        // Copy assignment operator
        Character &operator=(const Character &other);
        // Move assignment operator
        Character &operator=(Character &&other) noexcept;

        // destructor
        virtual ~Character(void);
        // Getter and Setter
        Point getLocation() const;
        int getHit_point() const;
        string getName() const;
        void setLocation(Point location);
        void setHit_point(int hit_point);
        void setName(string name);
        // functions
        bool isAlive();
        double distance(Character *other);
        void hit(int hits);
        virtual string print();
    };
}
