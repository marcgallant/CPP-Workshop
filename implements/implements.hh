#pragma once

template <typename T, typename U = T>
concept impl_basic_op = requires(const T& t, const U& u)
{
    +t;
    -t;
    +u;
    -u;

    t + u;
    u + t;

    t - u;
    u - t;

    t* u;
    u* t;

    t / u;
    u / t;
};

template <typename T, typename U = T>
concept impl_modulo = requires(const T& t, const U& u)
{
    t % u;
    u % t;
};

template <typename T, typename U = T>
concept impl_bitwise_op = requires(const T& t, const U& u)
{
    ~t;
    ~u;

    t& u;
    u& t;

    t | u;
    u | t;

    t ^ u;
    u ^ t;

    t << u;
    u << t;

    t >> u;
    u >> t;
};

template <typename T, typename U = T>
concept impl_arith_op = requires(const T& t, const U& u)
{
    requires impl_basic_op<T, U>;
    requires impl_modulo<T, U>;
    requires impl_bitwise_op<T, U>;
};
