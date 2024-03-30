#pragma once

#include <algorithm>

#include "unordered_multimap.hh"

template <typename KeyType, typename ValueType>
bool UnorderedMultimap<KeyType, ValueType>::empty() const
{
    return vector_.empty();
}

template <typename KeyType, typename ValueType>
unsigned UnorderedMultimap<KeyType, ValueType>::size() const
{
    return vector_.size();
}

template <typename KeyType, typename ValueType>
std::pair<typename UnorderedMultimap<KeyType, ValueType>::const_iterator,
          typename UnorderedMultimap<KeyType, ValueType>::const_iterator>
UnorderedMultimap<KeyType, ValueType>::equal_range(const KeyType& key) const
{
    auto equal = [key](std::pair<KeyType, ValueType> x) {
        return x.first == key;
    };

    const_iterator first =
        std::ranges::find_if(vector_.begin(), vector_.end(), equal);

    if (first == vector_.end())
        return std::pair<const_iterator, const_iterator>(first, first);

    const_iterator last =
        std::ranges::find_if_not(vector_.begin(), vector_.end(), equal);

    return std::pair<const_iterator, const_iterator>{ first, last };
}

template <typename KeyType, typename ValueType>
void UnorderedMultimap<KeyType, ValueType>::add(const KeyType& key,
                                                const ValueType& value)
{
    vector_.emplace_back(key, value);
    auto comp = [](auto& left, auto& right) {
        return left.first < right.first;
    };

    std::ranges::sort(vector_.begin(), vector_.end(), comp);
}

template <typename KeyType, typename ValueType>
unsigned UnorderedMultimap<KeyType, ValueType>::count(const KeyType& key) const
{
    unsigned c = 0;
    for (const_iterator it = vector_.begin(); it < vector_.end(); it++)
    {
        if (it->first == key)
            c++; // Inception
    }
    return c;
}

template <typename KeyType, typename ValueType>
void UnorderedMultimap<KeyType, ValueType>::clear()
{
    vector_.clear();
}
