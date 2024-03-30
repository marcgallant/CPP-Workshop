#include "replace.hh"

#include <fstream>
#include <iostream>

void replaceSubStr(std::string& str, const std::string& subStr,
                   const std::string& replacement)
{
    size_t pos = str.find(subStr);
    while (pos != std::string::npos)
    {
        str.replace(pos, subStr.length(), replacement);
        pos = str.find(subStr, pos + replacement.length());
    }
}

void replace(const std::string& input_filename,
             const std::string& output_filename, const std::string& src_token,
             const std::string& dst_token)
{
    std::ifstream file_in;
    file_in.open(input_filename);

    std::string token;
    if (!file_in.is_open())
    {
        std::cerr << "Cannot open input file\n";
        return;
    }

    std::ofstream file_out;
    file_out.open(output_filename);

    if (!file_out.is_open())
    {
        std::cerr << "Cannot write output file\n";
        return;
    }

    while (std::getline(file_in, token))
    {
        replaceSubStr(token, src_token, dst_token);
        file_out << token << '\n';
    }
}
