#include "bomb.hh"

#include <exception>
#include <iostream>
#include <stdexcept>

Bomb::Bomb(int ticks)
    : max_ticks_(ticks)
    , count_(0)
{
    if (ticks <= 0)
        throw std::runtime_error("Negative ticks");
}

void Bomb::tick()
{
    if (count_ >= max_ticks_)
        throw std::runtime_error("Bomb already exploded");

    if (count_ % 2 == 0)
        std::cout << "Tic!\n";
    else
        std::cout << "Tac!\n";

    count_++;
}

bool Bomb::has_exploded() const
{
    return max_ticks_ == count_;
}
