#include "Ninja.hpp"

namespace ariel
{
    // Default constructor
    Ninja::Ninja() : Character()
    {
        speed = 0;
    }

    // Constructor with location and name
    Ninja::Ninja(string name, Point location) : Character(name, location)
    {
        speed = 0;
    }

    // Destructor
    Ninja::~Ninja() {}

    // Getter for speed
    int Ninja::getspeed()
    {
        return speed;
    }

    // Setter for speed
    void Ninja::setspeed(int speed)
    {
        this->speed = speed;
    }

    // Move towards an enemy
    void Ninja::move(Character *enemy)
    {
        if (!(this->isAlive()))
            throw runtime_error("character is dead");
        else if (enemy == nullptr)
            throw invalid_argument("null p");
        else if (enemy == this)
            throw invalid_argument("the same chracter");
        Point newLocation = Point::moveTowards(getLocation(), enemy->getLocation(), speed);
        setLocation(newLocation);
    }

    // Slash an enemy
    void Ninja::slash(Character *enemy)
    {
        if (enemy == nullptr)
            throw invalid_argument("null enemyl");
        else if (enemy == this)
            throw runtime_error("the same chracter");
        else if (this->isAlive() == false || enemy->isAlive() == false)
            throw runtime_error("character is dead!");
        if (this->getLocation().distance(enemy->getLocation()) < 1){
            enemy->hit(40);
        }
       
    }

    // Print override
    string Ninja::print()
    {
        stringstream ss;
        if (this->isAlive())
        {
            ss << "N " << this->getName() << " " << this->getHit_point() << " " << this->getLocation().print();
        }
        else
        {
            ss << "N (" << this->getName() << ") " << this->getLocation().print();
        }
        return ss.str();
    }
}
