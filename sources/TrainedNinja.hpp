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


    class TrainedNinja : public Ninja
    {

    public:
        // constructors:
        TrainedNinja(string name, Point location);
        ~TrainedNinja(void);
        string print() override;
    };


}
