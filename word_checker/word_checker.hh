#pragma once

#include <string>
#include <vector>

class WordChecker
{
public:
    WordChecker(std::string filename);

    bool operator()(std::string arr_num);

private:
    std::vector<std::string> vector_;
};