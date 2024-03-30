#pragma once

#include "enable_if.hh"
#include "is_numerical.hh"

template <typename T>
typename enable_if<is_numerical<T>::value>::type algorithm(T)
{}