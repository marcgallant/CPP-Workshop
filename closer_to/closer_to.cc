#include "closer_to.hh"

CloserTo::CloserTo(int i)
    : i_(i)
{}

int abs(int a)
{
    return a < 0 ? -a : a;
}

bool CloserTo::operator()(int a, int b) const
{
    int dist_a = abs(i_ - a);
    int dist_b = abs(i_ - b);

    if (dist_a != dist_b)
        return dist_a < dist_b;

    return a < b;
}