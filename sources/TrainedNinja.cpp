#include "TrainedNinja.hpp"

namespace ariel {
    // Constructor
    TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location) {
        setspeed(12); 
        setHit_point(120); 
    }

    // Destructor
    TrainedNinja::~TrainedNinja() { }

    // Override print function
    string TrainedNinja::print() {
        stringstream ss;
        if (this->isAlive()) {
            ss << "N (Trained) " << this->getName() << " " << this->getHit_point() << " " << this->getLocation().print();
        } else {
            ss << "N (Trained, dead) (" << this->getName() << ") " << this->getLocation().print();
        }
        return ss.str();
    }
}
