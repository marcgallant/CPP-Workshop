#pragma once

#include <functional>
#include <tuple>

#include "player.hh"

class Game
{
public:
    Game(const strategy_type& strategy1, const strategy_type& strategy2);
    std::tuple<int, int> play(size_t nb_round);

private:
    Player player1_;
    Player player2_;
};
