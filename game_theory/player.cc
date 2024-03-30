#include "player.hh"

#include <numeric>

Player::Player(const strategy_type& brain)
    : brain_(brain)
{}

bool Player::play()
{
    return brain_(history_.begin(), history_.end());
}

void Player::add_res(int res)
{
    history_.push_back(res);
}

int Player::score()
{
    return std::accumulate(history_.begin(), history_.end(), 0);
}
