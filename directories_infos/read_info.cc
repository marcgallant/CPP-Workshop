#include "read_info.hh"

#include <fstream>
#include <sstream>

DirectoryInfo read_info(std::istream& file_in)
{
    char* line = new char[1001];
    file_in.getline(line, 1000);
    std::stringstream tmp;
    tmp << line;
    delete[] line;

    std::string name;
    size_t size;
    uint16_t rights;
    std::string owner;

    if (!(tmp >> name) || !(tmp >> std::dec >> size)
        || !(tmp >> std::oct >> rights) || !(tmp >> owner) || !(tmp.eof()))
        return DirectoryInfo("", 0, 0, "");

    return DirectoryInfo(name, size, rights, owner);
}
