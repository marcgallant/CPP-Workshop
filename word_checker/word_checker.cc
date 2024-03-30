#include "word_checker.hh"

#include <fstream>

WordChecker::WordChecker(std::string filename)
{
    std::ifstream file_in;
    file_in.open(filename);

    std::string token;
    while (std::getline(file_in, token))
    {
        vector_.push_back(token);
    }
}

bool contains_pair(std::string string, char first, char second)
{
    for (size_t i = 0; i < string.size() - 1; i++)
    {
        if (string.at(i) == first && string.at(i + 1) == second)
            return true;
    }
    return false;
}

bool list_contains_pair(std::vector<std::string> vector, char first,
                        char second)
{
    for (auto it = vector.begin(); it < vector.end(); ++it)
    {
        if (it->size() != 1 && contains_pair(*it, first, second))
            return true;
    }
    return false;
}

bool WordChecker::operator()(std::string arr_num)
{
    if (arr_num.size() == 1)
    {
        for (auto it = vector_.begin(); it != vector_.end(); ++it)
        {
            if ((*it).size() == 1 && *it == arr_num)
                return true;
        }
        return false;
    }
    else
    {
        for (size_t i = 0; i < arr_num.size() - 1; i++)
        {
            if (!list_contains_pair(vector_, arr_num.at(i), arr_num.at(i + 1)))
                return false;
        }
        return true;
    }
}
