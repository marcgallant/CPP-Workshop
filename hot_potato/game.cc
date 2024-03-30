#include "game.hh"

#include <iostream>

void Game::add_player(const std::string& name, size_t nb_presses)
{
    players_.emplace_back(name, nb_presses);
}

void Game::play(int bomb_ticks)
{
    if (players_.size() < 2)
        throw std::runtime_error("No enough players to start game");

    size_t i = 0;
    std::unique_ptr<Bomb> bomb = std::make_unique<Bomb>(bomb_ticks);
    players_.at(i).set_bomb(std::move(bomb));
    while (true)
    {
        players_.at(i).press_bomb();
        if (players_.at(i).is_dead())
            break;

        players_.at(i).pass_bomb(players_.at((i + 1) % players_.size()));
        i = (i + 1) % players_.size();
    }

    std::cout << players_.at(i).get_name() << " has exploded.\n";
}
