#include <iostream>

#include "for_each.hh"

int main()
{
    auto v = { 'M', 'y', 'S', 'T', 'L', '\n' };

    my_foreach(v.begin(), v.end(), [](auto c) { std::cout << c; });
}
