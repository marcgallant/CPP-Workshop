#include "list.hh"

List::List()
    : nb_elts_(0)
    , first_(nullptr)
    , last_(nullptr)
{}

void List::push_front(int i)
{
    std::shared_ptr<Node> elt = std::make_shared<Node>(Node(i));

    if (nb_elts_ == 0)
    {
        last_ = elt;
    }
    else
    {
        elt->set_next(first_);
        first_->set_prev(elt);
    }
    first_ = elt;

    nb_elts_++;
}

void List::push_back(int i)
{
    std::shared_ptr<Node> elt = std::make_shared<Node>(Node(i));

    if (nb_elts_ == 0)
    {
        first_ = elt;
    }
    else
    {
        last_->set_next(elt);
        elt->set_prev(last_);
    }
    last_ = elt;

    nb_elts_++;
}

std::optional<int> List::pop_front()
{
    if (nb_elts_ == 0)
        return std::nullopt;

    nb_elts_--;

    std::shared_ptr<Node> tmp = first_;
    first_ = first_->get_next();

    if (first_)
        first_->set_prev(nullptr);

    return tmp->get_val();
}

std::optional<int> List::pop_back()
{
    if (nb_elts_ == 0)
        return std::nullopt;

    nb_elts_--;

    std::shared_ptr<Node> tmp = last_;
    last_ = last_->get_prev();

    if (last_)
        last_->set_next(nullptr);

    return tmp->get_val();
}

void List::print(std::ostream& os) const
{
    std::shared_ptr<Node> tmp = first_;

    for (size_t i = 1; i < nb_elts_; i++)
    {
        os << tmp->get_val() << " ";
        tmp = tmp->get_next();
    }

    if (nb_elts_ != 0)
        os << tmp->get_val();
}

size_t List::length() const
{
    return nb_elts_;
}