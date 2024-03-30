#include "game.hh"

Game::Game(const strategy_type& strategy1, const strategy_type& strategy2)
    : player1_(strategy1)
    , player2_(strategy2)
{}

std::tuple<int, int> Game::play(size_t nb_round)
{
    for (size_t i = 0; i < nb_round; i++)
    {
        auto res1 = player1_.play();
        auto res2 = player2_.play();

        if (res1 && res2)
        {
            player1_.add_res(2);
            player2_.add_res(2);
        }
        else if (res1)
        {
            player1_.add_res(-1);
            player2_.add_res(3);
        }
        else if (res2)
        {
            player1_.add_res(3);
            player2_.add_res(-1);
        }
        else
        {
            player1_.add_res(0);
            player2_.add_res(0);
        }
    }
    return std::make_tuple(player1_.score(), player2_.score());
}
