#include "print_visitor.hh"

#include <iostream>

#include "add.hh"
#include "div.hh"
#include "leaf.hh"
#include "mul.hh"
#include "node.hh"
#include "sub.hh"
#include "tree.hh"

namespace visitor
{
    void PrintVisitor::visit(const tree::Tree& e)
    {
        e.accept(*this);
    }

    void PrintVisitor::visit(const tree::Node& e)
    {
        e.accept(*this);
    }

    void PrintVisitor::visit(const tree::AddNode& e)
    {
        std::cout << '(';
        visit(*e.get_lhs());
        std::cout << ' ';
        std::cout << e.get_value();
        std::cout << ' ';
        visit(*e.get_rhs());
        std::cout << ')';
    }

    void PrintVisitor::visit(const tree::SubNode& e)
    {
        std::cout << '(';
        visit(*e.get_lhs());
        std::cout << ' ';
        std::cout << e.get_value();
        std::cout << ' ';
        visit(*e.get_rhs());
        std::cout << ')';
    }

    void PrintVisitor::visit(const tree::MulNode& e)
    {
        std::cout << '(';
        visit(*e.get_lhs());
        std::cout << ' ';
        std::cout << e.get_value();
        std::cout << ' ';
        visit(*e.get_rhs());
        std::cout << ')';
    }

    void PrintVisitor::visit(const tree::DivNode& e)
    {
        std::cout << '(';
        visit(*e.get_lhs());
        std::cout << ' ';
        std::cout << e.get_value();
        std::cout << ' ';
        visit(*e.get_rhs());
        std::cout << ')';
    }

    void PrintVisitor::visit(const tree::Leaf& e)
    {
        std::cout << e.get_value();
    }
} // namespace visitor