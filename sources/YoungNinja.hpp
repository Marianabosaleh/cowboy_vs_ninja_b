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

    class YoungNinja : public Ninja
    {

    public:
        // constructors:
        YoungNinja(string name, Point location);
        ~YoungNinja(void);
        string print() override;
    };



}
