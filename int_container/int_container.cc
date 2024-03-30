#include "int_container.hh"

MyIntContainer::MyIntContainer(size_t size)
    : current_size_(0)
    , max_size_(size)
    , elems_(std::make_unique<int[]>(size))
{}

void MyIntContainer::print() const
{
    size_t i = 0;

    for (; i < current_size_ - 1; i++)
    {
        std::cout << elems_[i] << " | ";
    }

    if (current_size_ != 0)
        std::cout << elems_[i];

    std::cout << "\n";
}

size_t MyIntContainer::get_len() const
{
    return current_size_;
}

bool MyIntContainer::add(int elem)
{
    if (current_size_ >= max_size_)
    {
        return false;
    }

    elems_[current_size_++] = elem;

    return true;
}

std::optional<int> MyIntContainer::pop()
{
    if (current_size_ <= 0)
    {
        return std::nullopt;
    }

    current_size_--;

    return elems_[current_size_];
}

std::optional<int> MyIntContainer::get(size_t position) const
{
    if (position >= current_size_)
    {
        return std::nullopt;
    }

    return elems_[position];
}

std::optional<size_t> MyIntContainer::find(int elem) const
{
    for (size_t i = 0; i < current_size_; i++)
    {
        if (elems_[i] == elem)
            return i;
    }

    return std::nullopt;
}

void MyIntContainer::sort()
{
    for (size_t i = 1; i < current_size_; i++)
    {
        int key = elems_[i];
        int j = i - 1;

        while (j >= 0 && elems_[j] > key)
        {
            elems_[j + 1] = elems_[j];
            j = j - 1;
        }

        elems_[j + 1] = key;
    }
}

bool MyIntContainer::is_sorted() const
{
    for (size_t i = 1; i < current_size_; i++)
    {
        if (elems_[i - 1] > elems_[i])
            return false;
    }

    return true;
}
