#include "OldNinja.hpp"

namespace ariel {
    // Constructor
    OldNinja::OldNinja(string name, Point location) : Ninja(name, location) {
        setspeed(8); 
        setHit_point(150);
    }

    // Destructor
    OldNinja::~OldNinja() { }

    // Override print function
    string OldNinja::print() {
        stringstream ss;
        if (this->isAlive()) {
            ss << "N (Old) " << this->getName() << " " << this->getHit_point() << " " << this->getLocation().print();
        } else {
            ss << "N (Old, dead) (" << this->getName() << ") " << this->getLocation().print();
        }
        return ss.str();
    }
}
