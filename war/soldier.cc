#include "soldier.hh"

#include <iostream>

Soldier::Soldier()
    : health_(15)
    , damage_(3)
    , scream_("No pity for losers!")
{}

Soldier::Soldier(int health, unsigned int damage, std::string scream)
    : health_(health)
    , damage_(damage)
    , scream_(scream)
{}

void Soldier::attack(Soldier& s)
{
    s.health_ -= damage_;
}

void Soldier::print_state() const
{
    std::cout << "I have " << health_ << " health points.\n";
}

void Soldier::scream() const
{
    std::cout << scream_ << "\n";
}
