#pragma once

#include "bimap.hh"

template <typename Lhs, typename Rhs>
const typename Bimap<Lhs, Rhs>::mapLhs& Bimap<Lhs, Rhs>::get_lhs() const
{
    return lhs_;
}

template <typename Lhs, typename Rhs>
const typename Bimap<Lhs, Rhs>::mapRhs& Bimap<Lhs, Rhs>::get_rhs() const
{
    return rhs_;
}

template <typename Lhs, typename Rhs>
std::size_t Bimap<Lhs, Rhs>::size() const
{
    return lhs_.size();
}

template <typename Lhs, typename Rhs>
void Bimap<Lhs, Rhs>::clear()
{
    lhs_.clear();
    rhs_.clear();
}

template <typename Lhs, typename Rhs>
bool Bimap<Lhs, Rhs>::insert(const Lhs& vl, const Rhs& vr)
{
    if (lhs_.contains(vl) || rhs_.contains(vr))
        return false;
    return lhs_.insert({ vl, vr }).second && rhs_.insert({ vr, vl }).second;
}

template <typename Lhs, typename Rhs>
bool Bimap<Lhs, Rhs>::insert(const Rhs& vr, const Lhs& vl)
{
    if (lhs_.contains(vl) || rhs_.contains(vr))
        return false;
    return lhs_.insert({ vl, vr }).second && rhs_.insert({ vr, vl }).second;
}

template <typename Lhs, typename Rhs>
std::size_t Bimap<Lhs, Rhs>::erase(const Lhs& vl)
{
    Rhs vr = lhs_.find(vl)->second;
    rhs_.erase(vr);

    return lhs_.erase(vl);
}

template <typename Lhs, typename Rhs>
std::size_t Bimap<Lhs, Rhs>::erase(const Rhs& vr)
{
    Lhs vl = rhs_.find(vr)->second;
    lhs_.erase(vl);

    return rhs_.erase(vr);
}

template <typename Lhs, typename Rhs>
typename Bimap<Lhs, Rhs>::iteratorLhs Bimap<Lhs, Rhs>::find(const Lhs& vl) const
{
    return lhs_.find(vl);
}

template <typename Lhs, typename Rhs>
typename Bimap<Lhs, Rhs>::iteratorRhs Bimap<Lhs, Rhs>::find(const Rhs& vr) const
{
    return rhs_.find(vr);
}
