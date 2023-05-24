#include "Character.hpp"

namespace ariel
{

    // Default constructor
    Character::Character() : hit_point(0), name("") {}

    // Constructor with name and location
    Character::Character(string name, Point location) : name(name), location(location), hit_point(0) {}
    // Constructor with name and location
    Character::Character(Point location, string name) : location(location), name(name), hit_point(0) {}
    // Copy constructor
    Character::Character(const Character &other) : name(other.name), location(other.location), hit_point(other.hit_point) {}

    // Move constructor
    Character::Character(Character &&other) noexcept : name(std::move(other.name)), location(std::move(other.location)), hit_point(other.hit_point) {}

    // Copy assignment operator
    Character &Character::operator=(const Character &other)
    {
        if (this != &other)
        {
            name = other.name;
            location = other.location;
            hit_point = other.hit_point;
        }
        return *this;
    }

    // Move assignment operator
    Character &Character::operator=(Character &&other) noexcept
    {
        if (this != &other)
        {
            name = std::move(other.name);
            location = std::move(other.location);
            hit_point = other.hit_point;
        }
        return *this;
    }

    // Destructor
    Character::~Character(void) {}

    // Getter and Setter
    Point Character::getLocation() const
    {
        return location;
    }

    int Character::getHit_point() const
    {
        return hit_point;
    }

    string Character::getName() const
    {
        return name;
    }


    void Character::setLocation(Point new_location)
    {
        location = new_location;
    }

    void Character::setHit_point(int new_hit_point)
    {
        hit_point = new_hit_point;
    }

    void Character::setName(string new_name)
    {
        name = new_name;
    }


    // Functions
    bool Character::isAlive()
    {
        return hit_point > 0;
    }

    double Character::distance(Character *other)
    {
        if (other == nullptr)
            throw invalid_argument("Other is null");
        return location.distance(other->getLocation());
    }

    void Character::hit(int hits)
    {
        if (hits < 0){
            throw invalid_argument("The hit points cant be negative");
            this->hit_point=0;
        }
        this->hit_point -= hits;
    }

    string Character::print()
    {
        stringstream ss;
        if (this->isAlive())
        {
            ss << "C" << this->name << " " << this->hit_point << " " << this->location.print();
        }
        else
        {
            ss << "C(" << this->name << ") " << this->location.print();
        }
        return ss.str();
    }

}
