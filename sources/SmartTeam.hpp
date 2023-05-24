#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include "Point.hpp"
#include "Character.hpp"
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

    class SmartTeam : public Team
    {

    public:
        SmartTeam();
        SmartTeam(Character *leader);

    };

}
