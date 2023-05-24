#include "Team.hpp"
#include <algorithm>

namespace ariel
{
    Team::Team() : leader(nullptr) {}

    Team::Team(Character *leader)
    {
        if (leader->isteam_member)
            throw std::runtime_error("already in a team");
        this->setleader(leader);
        this->add(leader);
        leader->isteam_member = true;
    }
    // Copy constructor
    Team::Team(const Team &other) : leader(nullptr), team(other.team.size())
    {
        if (other.leader != nullptr)
        {
            leader = new Character(*other.leader);
        }

        for (size_t i = 0; i < other.team.size(); i++)
        {
            team[i] = new Character(*other.team[i]);
        }
    }

    // Copy assignment operator
    Team &Team::operator=(const Team &other)
    {
        if (this != &other)
        {
            delete leader;
            for (Character *member : team)
            {
                delete member;
            }
            leader = nullptr;
            if (other.leader != nullptr)
            {
                leader = new Character(*other.leader);
            }
            team.resize(other.team.size());
            for (size_t i = 0; i < other.team.size(); i++)
            {
                team[i] = new Character(*other.team[i]);
            }
        }
        return *this;
    }

    // Move constructor
    Team::Team(Team &&other) noexcept
        : leader(std::move(other.leader)), team(std::move(other.team))
    {
        other.leader = nullptr;
        other.team.clear();
    }

    // Move assignment operator
    Team &Team::operator=(Team &&other) noexcept
    {
        if (this != &other)
        {
            // Delete existing leader and team members
            delete leader;
            for (Character *member : team)
            {
                delete member;
            }

            // Move the leader and team members from 'other'
            leader = std::move(other.leader);
            team = std::move(other.team);

            // Set 'other' to a valid state
            other.leader = nullptr;
            other.team.clear();
        }
        return *this;
    }

    Character *Team::getleader() const
    {
        return leader;
    }

    void Team::setleader(Character *new_leader)
    {
        if (new_leader == nullptr)
        {
            throw std::runtime_error("Leader cannot be null.");
        }
        if (new_leader->isleader)
        {
            throw std::runtime_error("already team leader!");
        }
        leader = new_leader;
        new_leader->isleader = true;
    }

    void Team::add(Character *character)
    {
        if (character == nullptr)
        {
            throw std::runtime_error("Character cannot be null.");
        }
        if (character->isteam_member)
        {
            throw std::runtime_error("already in a team!");
        }

        if (this->team.size() >= 10)
        {
            throw std::runtime_error("team is full!");
        }
        team.push_back(character);
        character->isteam_member = true;
    }
    void Team::attack(Team *enemy_team)
    {
        if (enemy_team == nullptr)
        {
            throw std::invalid_argument("Can't attack null!");
        }
        else if (enemy_team == this)
            throw runtime_error("Cant attack team self");
        else if (!(enemy_team->stillAlive()))
            throw runtime_error("other team is dead");
        else if (!(this->stillAlive()))
            throw runtime_error("team is dead");
        if (!this->leader->isAlive())
        {
            // Find new leader if current one is dead
            Character *new_leader = this->closestAliveTo(this->leader->getLocation());
            if (new_leader == nullptr)
            {
                throw std::runtime_error("No members alive in the team");
            }
            this->setleader(new_leader);
        }

        // Now start the attack
        Character *target = enemy_team->closestAliveTo(this->leader->getLocation());
        if (target == nullptr)
        {
            throw std::runtime_error("No members alive in the enemy team");
        }

        // Process attack for cowboys first
        for (Character *member : this->team)
        {
            Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
            if (cowboy && cowboy->isAlive())
            {
                if (cowboy->hasboolets())
                {
                    cowboy->shoot(target);
                }
                else
                {
                    cowboy->reload();
                }

                if (!target->isAlive())
                {
                    // Choose next target if current one is dead
                    target = enemy_team->closestAliveTo(this->leader->getLocation());
                    if (target == nullptr)
                    {
                        return; // return if there are no more alive members in the enemy team
                    }
                }
            }
        }

        // Then process attack for ninjas
        for (Character *member : this->team)
        {
            Ninja *ninja = dynamic_cast<Ninja *>(member);
            if (ninja && ninja->isAlive())
            {
                if (ninja->getLocation().distance(target->getLocation()) < 1)
                {
                    ninja->slash(target);
                }
                else
                {
                    ninja->move(target);
                }

                if (!target->isAlive())
                {
                    // Choose next target if current one is dead
                    target = enemy_team->closestAliveTo(this->leader->getLocation());
                    if (target == nullptr)
                    {
                        return; // return if there are no more alive members in the enemy team
                    }
                }
            }
        }
    }

    int Team::stillAlive()
    {
        int count = 0;
        for (Character *character : team)
        {
            if (character->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    string Team::print()
    {
        std::stringstream ss;
        for (Character *character : team)
        {
            ss << character->print() << std::endl;
        }
        return ss.str();
    }

    Character *Team::closestTo(Point location)
    {
        Character *closest = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character *character : team)
        {
            double distance = character->getLocation().distance(location);
            if (distance < minDistance)
            {
                closest = character;
                minDistance = distance;
            }
        }

        return closest;
    }

    Character *Team::closestAliveTo(Point location)
    {
        Character *closest = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character *character : team)
        {
            if (!character->isAlive())
            {
                continue;
            }

            double distance = character->getLocation().distance(location);
            if (distance < minDistance)
            {
                closest = character;
                minDistance = distance;
            }
        }

        if (minDistance == std::numeric_limits<double>::max())
        {
            return nullptr; // return null if no characters are alive
        }
        else
        {
            return closest;
        }
    }

    Team::~Team()
    {
        for (Character *character : team)
        {
            delete character;
        }
    }
}
