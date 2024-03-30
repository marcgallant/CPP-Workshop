#include "lambdas.hh"

bool cooperated(int score)
{
    return score == 2 || score == 3;
}

strategy_type cooperator()
{
    return [](iterator_type, iterator_type) { return true; };
}

strategy_type cheater()
{
    return [](iterator_type, iterator_type) { return false; };
}

strategy_type copycat()
{
    return [](iterator_type begin, iterator_type end) {
        if (begin == end)
            return true;

        return cooperated(*(end - 1));
    };
}

strategy_type grudger()
{
    return [](iterator_type begin, iterator_type end) {
        for (auto it = begin; it != end; it++)
        {
            if (!cooperated(*it))
                return false;
        }

        return true;
    };
}

strategy_type detective()
{
    return [](iterator_type begin, iterator_type end) {
        if (begin == end) // First move
            return true;

        if (begin + 1 == end) // Second move
            return false;

        if (begin + 2 == end || begin + 3 == end) // Third and Fourth move
            return true;

        if (cooperated(*begin) && cooperated(*(begin + 1))
            && cooperated(*(begin + 2)) && cooperated(*(begin + 3)))
            return false;

        return cooperated(*(end - 1)); // Copy cat
    };
}

strategy_type copykitten()
{
    return [](iterator_type begin, iterator_type end) {
        if (begin == end || begin + 1 == end)
            return true;

        return cooperated(*(end - 1)) || cooperated(*(end - 2));
    };
}
