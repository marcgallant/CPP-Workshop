#include "dnl.hh"

#include <algorithm>
#include <numeric>
#include <string>

size_t min_elt_length(const std::vector<std::string>& req)
{
    auto comp = [](auto left, auto right) {
        return left.size() < right.size();
    };
    std::string res = *std::min_element(req.begin(), req.end(), comp);
    return res.size();
}

size_t max_elt_length(const std::vector<std::string>& req)
{
    auto comp = [](auto left, auto right) {
        return left.size() < right.size();
    };
    std::string res = *std::max_element(req.begin(), req.end(), comp);
    return res.size();
}

size_t sum_elt_length(const std::vector<std::string>& req)
{
    auto func = [](size_t accumulator, std::string it) {
        return accumulator + it.size();
    };
    return std::accumulate(req.begin(), req.end(), 0, func);
}

size_t count_elt(const std::vector<std::string>& req, const std::string& elt)
{
    size_t res = std::count(req.begin(), req.end(), elt);
    return res;
}

size_t count_duplicate(const std::vector<std::string>& req)
{
    std::vector<std::string> vector = req;

    std::sort(vector.begin(), vector.end());

    auto last = std::unique(vector.begin(), vector.end());
    vector.erase(last, vector.end());
    return req.size() - vector.size();
}
