#include "windows_path.hh"

WindowsPath::WindowsPath(char drive)
    : drive_(drive)
{}

std::string WindowsPath::to_string() const
{
    std::string res;
    res.push_back(drive_);
    res.push_back(':');

    for (size_t i = 0; i < path_.size(); i++)
    {
        res += "\\" + path_.at(i);
    }

    if (!final_)
        res += "\\";

    return res;
}

Path& WindowsPath::join(const std::string& tail, bool is_file)
{
    if (!final_ && (tail.find(':') == std::string::npos)
        && (tail.find('\"') == std::string::npos)
        && (tail.find('|') == std::string::npos)
        && (tail.find('?') == std::string::npos)
        && (tail.find('*') == std::string::npos))
    {
        if (is_file)
        {
            final_ = true;
        }
        path_.push_back(tail);
    }

    return *this;
}
