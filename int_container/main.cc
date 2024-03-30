#include <optional>

#include "int_container.hh"

int main()
{
    MyIntContainer c = MyIntContainer(10);
    for (int i = 0; i < 11; ++i)
        c.add(i);
    c.print();
    if (auto el = c.pop())
        std::cout << "element popped: " << *el << '\n';
    else
        std::cout << "Trying to pop an empty array" << '\n';
    std::cout << '\n';
    for (int i = 0; i < 10; ++i)
    {
        if (auto el = c.get(i))
            std::cout << "got element: " << *el << '\n';
        else
            std::cout << "Trying to access out of bound index: " << i << '\n';
    }
    if (auto pos = c.find(9))
        std::cout << "Position of element `9`: " << *pos << '\n';
    else
        std::cout << "Failed to find number 9" << '\n';
    return 0;
}
