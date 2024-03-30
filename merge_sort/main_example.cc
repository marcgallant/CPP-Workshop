// main_example.cc

#include <iostream>

#include "merge_sort.hh"

int main()
{
    auto vect = std::vector{ 2, 1 };
    std::cout << std::boolalpha << std::is_sorted(vect.begin(), vect.end())
              << '\n';

    merge_sort(vect.begin(), vect.end());

    std::cout << std::boolalpha << std::is_sorted(vect.begin(), vect.end())
              << '\n';

    vect = std::vector{ 1, 2, 3, 4, 5 };
    std::cout << std::boolalpha << std::is_sorted(vect.begin(), vect.end())
              << '\n';

    merge_sort(vect.begin(), vect.end());

    std::cout << std::boolalpha << std::is_sorted(vect.begin(), vect.end())
              << '\n';

    vect = std::vector{ 7, 0, 19, 34, 9, 14, 96 };
    std::cout << std::boolalpha << std::is_sorted(vect.begin(), vect.end())
              << '\n'; // false

    merge_sort(vect.begin(), vect.end());

    std::cout << std::boolalpha << std::is_sorted(vect.begin(), vect.end())
              << '\n'; // true
}
