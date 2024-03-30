#include <iostream>

#include "game.hh"
#include "invalid_argument.hh"
#include "player.hh"

int main()
{
    Game g(42);
    std::string n1 = "Toto";
    std::string n2 = "Frodo";
    std::string n3 = "Feanor";
    std::string n4 = "Pikachu";
    std::string n5 = "";

    try
    {
        Player p1 = Player(n1, 9, 3);
    }
    catch (InvalidArgumentException& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Player p2 = Player(n2, 51, 5);
    }
    catch (InvalidArgumentException& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Player p3 = Player(n3, 3142, 42);
    }
    catch (InvalidArgumentException& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Player p4 = Player(n4, 25, 5000);
    }
    catch (InvalidArgumentException& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Player p5 = Player(n5, 19, 1);
    }
    catch (InvalidArgumentException& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Player p1 = Player(n1, 9, 3);
        Player p2 = Player(n2, 51, -18);
        g.play(p1, p1);
    }
    catch (InvalidArgumentException& e)
    {
        std::cout << e.what() << std::endl;
    }

    Player p1 = Player(n1, 9, 3);
    Player p2 = Player(n2, 51, -18);
    g.play(p1, p2);
}
