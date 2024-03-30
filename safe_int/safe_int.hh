#pragma once

// stl
#include <optional>

class SafeInt final
{
public:
    // nullopt
    SafeInt();
    // implicit conversion from int
    SafeInt(int value);

    // default copy/move ctors
    SafeInt(const SafeInt&) = default;
    SafeInt(SafeInt&&) = default;

    // default copy/move assigment
    SafeInt& operator=(const SafeInt&) = default;
    SafeInt& operator=(SafeInt&&) = default;

    // default cmp operators
    friend auto operator<=>(SafeInt, SafeInt) = default;
    friend bool operator==(SafeInt, SafeInt) = default;

    // default dtor
    ~SafeInt() = default;

    // optional access
    int operator*() const;
    int value() const;
    int value_or(int value) const;
    bool has_value() const;

    // in place operations
    SafeInt& operator+=(SafeInt rhs);
    SafeInt& operator-=(SafeInt rhs);
    SafeInt& operator*=(SafeInt rhs);
    SafeInt& operator/=(SafeInt rhs);

    // pre increments (returns incemented value)
    SafeInt& operator++();
    SafeInt& operator--();

    // post increments (returns copy of the value before increment)
    SafeInt operator++(int);
    SafeInt operator--(int);

    // unary operations
    SafeInt operator+() const;
    SafeInt operator-() const;

private:
    std::optional<int> value_;
};

// basic operations
SafeInt operator+(SafeInt lhs, SafeInt rhs);
SafeInt operator-(SafeInt lhs, SafeInt rhs);
SafeInt operator*(SafeInt lhs, SafeInt rhs);
SafeInt operator/(SafeInt lhs, SafeInt rhs);

#include "safe_int.hxx"
