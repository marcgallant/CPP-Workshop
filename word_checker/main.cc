#include <iostream>
#include <vector>

#include "word_checker.hh"

int main()
{
    WordChecker checker("../words.txt");
    std::vector<std::string> list{ "a",       "basic",
                                   "test",    "somtips",
                                   "milkyss", "vwv",
                                   "e",       "toosztrangetobeenglish" };

    for (const auto& word : list)
    {
        std::cout << '"' << word
                  << (checker(word) ? "\" matches" : "\" does not match")
                  << " the language" << '\n';
    }

    return 0;
}
