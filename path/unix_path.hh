#pragma once

#include "path.hh"

class UnixPath : public Path
{
public:
    virtual std::string to_string() const;
};