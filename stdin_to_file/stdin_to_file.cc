#include <fstream>
#include <iostream>

ssize_t stdin_to_file(const std::string& filename)
{
    std::ofstream file_out;
    file_out.open(filename);

    std::string token;
    ssize_t lines = 0;

    if (file_out.is_open())
    {
        while (std::cin >> token)
        {
            lines++;
            file_out << token << '\n';
        }
    }

    return lines;
}
