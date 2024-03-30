#pragma once

#include "path.hh"

class WindowsPath : public Path
{
public:
    WindowsPath(char drive);
    virtual std::string to_string() const;

    virtual Path& join(const std::string& tail, bool is_file = false);

private:
    char drive_;
};