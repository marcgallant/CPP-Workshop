#include <algorithm>
#include <iostream>
#include <vector>

#include "closer_to.hh"

void print_elt(int i)
{
    std::cout << ' ' << i;
}

int main()
{
    auto v = std::vector<int>{ 2, 4, 4, 2 };

    std::cout << "Unsorted vector:";
    std::for_each(v.begin(), v.end(), print_elt);
    std::cout << '\n';

    auto n = 3;

    std::sort(v.begin(), v.end(), CloserTo(n));

    std::cout << "Sorted vector closed to " << n << ':';
    std::for_each(v.begin(), v.end(), print_elt);
    std::cout << '\n';

    return 0;
}
