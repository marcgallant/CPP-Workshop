#pragma once

#include "is_prime.hh"

constexpr bool is_prime(unsigned a)
{
    if (a == 1)
        return false;

    for (unsigned i = 2; i * i <= a; i++)
    {
        if ((a % i) == 0)
            return false;
    }

    return true;
}