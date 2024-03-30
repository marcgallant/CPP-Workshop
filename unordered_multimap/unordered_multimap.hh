#pragma once

#include <utility>
#include <vector>

template <typename KeyType, typename ValueType>
class UnorderedMultimap
{
    using const_iterator =
        typename std::vector<std::pair<KeyType, ValueType>>::const_iterator;

    using vector = typename std::vector<std::pair<KeyType, ValueType>>;

public:
    bool empty() const;
    unsigned size() const;
    std::pair<const_iterator, const_iterator>
    equal_range(const KeyType& key) const;
    void add(const KeyType& key, const ValueType& value);
    unsigned count(const KeyType& key) const;
    void clear();

private:
    vector vector_;
};

#include "unordered_multimap.hxx"
