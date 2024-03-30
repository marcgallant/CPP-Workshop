#include "regiment.hh"

Regiment::Regiment()
    : list_({})
{}

void Regiment::join_by(Regiment& r)
{
    for (Soldier& s : r.list_)
    {
        list_.push_back(s);
    }

    r.list_ = {};
}

size_t Regiment::count() const
{
    return list_.size();
}

void Regiment::add_soldier(Soldier& s)
{
    list_.push_back(s);
}

void Regiment::print_state() const
{
    for (Soldier s : list_)
    {
        s.print_state();
    }
}

void Regiment::scream() const
{
    for (Soldier s : list_)
    {
        s.scream();
    }
}
