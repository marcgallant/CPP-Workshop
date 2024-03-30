#include "forward_multiplication.hh"

outer_lambda_type mult_by = outer_lambda_type(
    [](int a) { return inner_lambda_type([a](int b) { return a * b; }); });