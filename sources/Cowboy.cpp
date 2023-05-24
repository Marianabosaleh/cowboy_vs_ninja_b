#include "Cowboy.hpp"

namespace ariel
{
    // Default constructor
    Cowboy::Cowboy() : Character()
    {
        balls = 6;
        setHit_point(110);
    }

    // Constructor with location and name
    Cowboy::Cowboy(string name, Point location) : Character(name, location)
    {
        balls = 6;
        setHit_point(110);
    }

    // destructor
    Cowboy::~Cowboy() {}

    // Getter for balls
    int Cowboy::getballs()
    {
        return balls;
    }

    // Setter for balls
    void Cowboy::setballs(int balls)
    {
        this->balls = balls;
    }

    // functions
    void Cowboy::shoot(Character *enemy)
    {
        if (enemy == nullptr)
            throw invalid_argument("null enemy");
        else if (enemy == this)
            throw runtime_error("enemy is the same character");
        else if (this->isAlive() == false || enemy->isAlive() == false)
            throw runtime_error("character is dead");
        else if (this->hasboolets())
        {
            enemy->hit(10);
            balls--;
        }
    }

    bool Cowboy::hasboolets()
    {

        return balls > 0;
    }

    void Cowboy::reload()
    {
        if (!(this->isAlive()))
            throw runtime_error("cowboy is dead");
        else 
            balls = 6;
    }

    // Print override
    string Cowboy::print()
    {
        stringstream ss;
        if (this->isAlive())
        {
            ss << "C " << this->getName() << " " << this->getHit_point() << " " << this->getLocation().print();
        }
        else
        {
            ss << "C (" << this->getName() << ") " << this->getLocation().print();
        }
        return ss.str();
    }
}
