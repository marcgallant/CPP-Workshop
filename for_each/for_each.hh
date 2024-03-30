#pragma once

template <typename T, typename U>
void my_foreach(T begin, T end, U&& fun);

#include "for_each.hxx"