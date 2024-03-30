#include "merge_sort.hh"

#include <algorithm>

void merge_sort(iterator_type begin, iterator_type end)
{
    if (begin + 1 < end)
    {
        iterator_type mid = begin + (end - begin) / 2;

        merge_sort(begin, mid);
        merge_sort(mid, end);

        std::inplace_merge(begin, mid, end);
    }
}
