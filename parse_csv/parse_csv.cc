#include "parse_csv.hh"

#include <fstream>
#include <sstream>

std::vector<std::vector<std::string>> parse_csv(const std::string& file_name)
{
    // Open file
    std::string token;
    std::ifstream file_in;

    file_in.open(file_name);
    if (!file_in.is_open())
    {
        throw std::ios_base::failure("Error opening file");
    }
    // Create vector of vectors of string
    std::vector<std::vector<std::string>> lines;
    int col = -1;
    int row = 1;

    while (std::getline(file_in, token, '\n'))
    {
        int curr_col = 0;

        // Create vector of string
        std::vector<std::string> line;

        // Separate by comma
        std::stringstream stream(token);
        while (stream.good())
        {
            // Get current case
            std::string substr;
            std::getline(stream, substr, ',');

            line.push_back(substr);
            curr_col++;
        }

        if (col == -1) // Get number of case for first iteration
            col = curr_col;
        else if (col != curr_col) // Non-consistent number of columns
        {
            throw std::ios_base::failure(
                "Non consistent number of columns at line "
                + std::to_string(row));
        }

        lines.push_back(line); // Add line
        row++;
    }

    return lines;
}
