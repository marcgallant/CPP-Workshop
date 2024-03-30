#include <cassert>
#include <limits>

#include "safe_int.hh"

int max_mul(int value, const int constant)
{
    for (SafeInt n = value; n.has_value(); value = n.value(), n *= constant)
    {}
    return value;
}

int max_int()
{
    return (max_mul(1, 2) - 1) * 2 + 1;
}

int main()
{
    SafeInt max{ std::numeric_limits<int>::max() };
    assert(!(max + 1).has_value());

    SafeInt zero{ 0 };
    assert(!(max / zero).has_value());

    SafeInt min{ std::numeric_limits<int>::min() };
    SafeInt minus_one{ -1 };
    assert(!(min / minus_one).has_value());

    assert(max == max_int());

    SafeInt null{};
    assert(!(null / null + null * null - null).has_value());

    return 0;
}
