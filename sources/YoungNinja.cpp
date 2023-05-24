#include "YoungNinja.hpp"

namespace ariel {
    // Constructor
    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location) {
        setspeed(14); 
        setHit_point(100); 
    }

    // Destructor
    YoungNinja::~YoungNinja() { }

    // Override print function
    string YoungNinja::print() {
        stringstream ss;
        if (this->isAlive()) {
            ss << "N (Young) " << this->getName() << " " << this->getHit_point() << " " << this->getLocation().print();
        } else {
            ss << "N (Young, dead) (" << this->getName() << ") " << this->getLocation().print();
        }
        return ss.str();
    }
}
