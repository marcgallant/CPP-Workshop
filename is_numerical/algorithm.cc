#include "algorithm.hh"

int main()
{
    algorithm(10); // ok
    algorithm(10.0f); // ok
    algorithm('c'); // ok

    return 0;
}
