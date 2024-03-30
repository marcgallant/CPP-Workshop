#pragma once

#include <string>

class Soldier
{
public:
    Soldier();

    void attack(Soldier& s);
    void print_state() const;
    void scream() const;

protected:
    Soldier(int health, unsigned int damage, std::string scream);

    int health_;
    unsigned int damage_;
    std::string scream_;
};
