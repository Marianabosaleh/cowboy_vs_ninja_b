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
#include "Team.hpp"
using namespace std;
namespace ariel
{

    class Team2 : public Team
    {

    public:
        Team2();
        Team2(Character *leader);
    };

}
