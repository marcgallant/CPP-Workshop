#pragma once

template <typename T, typename U>
void my_foreach(T begin, T end, U&& fun)
{
    for (auto it = begin; it != end; ++it)
    {
        fun(*it);
    }
}
