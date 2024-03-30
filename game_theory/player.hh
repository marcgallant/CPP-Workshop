#pragma once

#include <functional>
#include <vector>

#include "lambdas.hh"

class Player
{
public:
    Player(const strategy_type& brain);
    bool play();
    void add_res(int res);
    int score();

private:
    strategy_type brain_;
    std::vector<int> history_;
};
