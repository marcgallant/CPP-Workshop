#pragma once

#include "shared_pointer.hh"

template<typename T>
template<typename U>
bool SharedPointer<T>::is_a() const {
    U* tmp = dynamic_cast<U*>(data_);
    return tmp != nullptr;
}

template<typename T>
SharedPointer<T>::operator bool() const {
    return *data_;
}

template<typename T>
bool SharedPointer<T>::operator!=(const element_type *p) const {
    return *data_ != *p;
}

template<typename T>
bool SharedPointer<T>::operator==(const element_type *p) const {
    return *data_ == *p;
}

template<typename T>
template<typename U>
bool SharedPointer<T>::operator!=(const SharedPointer<U> &rhs) const {
    return *data_ != *(rhs.data_);
}

template<typename T>
template<typename U>
bool SharedPointer<T>::operator==(const SharedPointer<U> &rhs) const {
    return *data_ == *(rhs.data_);
}

template<typename T>
long SharedPointer<T>::use_count() const {
    return *count_;
}

template<typename T>
T *SharedPointer<T>::get() const {
    return data_;
}

//FIXME
template<typename T>
int SharedPointer<T>::operator->() const {
    return 0;
}

//FIXME
template<typename T>
int SharedPointer<T>::operator*() const {
    return 0;
}

//FIXME
template<typename T>
int SharedPointer<T>::operator=(SharedPointer<T>) {
    return 0;
}

//FIXME
template<typename T>
void SharedPointer<T>::reset(element_type *p)
{
    data_ = p;
}

template<typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<element_type> &other)
{
    (*other.count_)++;

    data_ = other.data_;
    count_ = other.count_;
}

template<typename T>
SharedPointer<T>::~SharedPointer()
{
    if (*count_ == 0)
    {
        delete data_;
        delete count_;
    }
    else
        *count_--;
}

template<typename T>
SharedPointer<T>::SharedPointer(element_type *p)
: data_(p)
, count_(new long(1))
{}
