#pragma once

#include <set>

template <class T>
class Exist
{
public:
    Exist();

    bool operator()(T arr_num);

private:
    std::set<T> set_;
};

#include "exist.hxx"
