#pragma once

#include "exist.hh"

template <class T>
Exist<T>::Exist()
{}

template <class T>
bool Exist<T>::operator()(T t)
{
    bool res = set_.contains(t);
    if (!res)
        set_.insert(t);

    return res;
}
