#include "compute_visitor.hh"

#include "add.hh"
#include "div.hh"
#include "leaf.hh"
#include "mul.hh"
#include "node.hh"
#include "sub.hh"
#include "tree.hh"

namespace visitor
{
    void ComputeVisitor::visit(const tree::Tree& e)
    {
        e.accept(*this);
    }

    void ComputeVisitor::visit(const tree::Node& e)
    {
        e.accept(*this);
    }

    void ComputeVisitor::visit(const tree::AddNode& e)
    {
        visit(*e.get_lhs());
        int a = value_;

        visit(*e.get_rhs());
        int b = value_;

        value_ = a + b;
    }

    void ComputeVisitor::visit(const tree::SubNode& e)
    {
        visit(*e.get_lhs());
        int a = value_;

        visit(*e.get_rhs());
        int b = value_;

        value_ = a - b;
    }

    void ComputeVisitor::visit(const tree::MulNode& e)
    {
        visit(*e.get_lhs());
        int a = value_;

        visit(*e.get_rhs());
        int b = value_;

        value_ = a * b;
    }

    void ComputeVisitor::visit(const tree::DivNode& e)
    {
        visit(*e.get_lhs());
        int a = value_;

        visit(*e.get_rhs());
        int b = value_;

        if (b == 0)
            throw std::overflow_error("Divide by zero exception");

        value_ = a / b;
    }

    void ComputeVisitor::visit(const tree::Leaf& e)
    {
        value_ = std::stoi(e.get_value());
    }

    int ComputeVisitor::get_value()
    {
        return value_;
    }
} // namespace visitor