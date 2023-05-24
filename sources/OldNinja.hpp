#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Character.hpp"
#include "Point.hpp"
#include "Ninja.hpp"
using namespace std;
namespace ariel
{

    class OldNinja : public Ninja
    {

    public:
        // constructors:
        OldNinja(string name, Point location);
        ~OldNinja(void);
        string print() override;
    };
}
