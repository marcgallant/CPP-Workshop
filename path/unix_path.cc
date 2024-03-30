#include "unix_path.hh"

std::string UnixPath::to_string() const
{
    std::string res = "";

    for (size_t i = 0; i < path_.size(); i++)
    {
        res += "/" + path_.at(i);
    }

    if (!final_)
        res += "/";

    return res;
}