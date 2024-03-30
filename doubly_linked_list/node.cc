#include "node.hh"

Node::Node(int val)
    : val_(val)
    , next_(nullptr)
    , prev_(std::weak_ptr<Node>())
{}

int Node::get_val() const
{
    return val_;
}

void Node::set_val(int val)
{
    val_ = val;
}

std::shared_ptr<Node> Node::get_next() const
{
    return next_;
}

void Node::set_next(std::shared_ptr<Node> next)
{
    next_ = std::move(next);
}

std::shared_ptr<Node> Node::get_prev() const
{
    return prev_.lock(); // FIXME
}

void Node::set_prev(std::shared_ptr<Node> prev)
{
    prev_ = prev;
}
