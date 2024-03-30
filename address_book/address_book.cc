#include "address_book.hh"

#include <iostream>

bool AddressBook::add(const std::string& full_name, const std::string& email,
                      const std::string& number)
{
    std::optional<ContactDetails> detail =
        ContactDetails::makeDetails(number, email);

    if (detail == std::nullopt || full_name.empty())
        return false;

    contacts_.insert(
        std::pair<std::string, ContactDetails>(full_name, detail.value()));

    return true;
}

std::vector<ContactDetails> AddressBook::find(const std::string& full_name)
{
    std::vector<ContactDetails> v;
    for (const auto& elt : contacts_)
    {
        if (elt.first == full_name)
            v.push_back(elt.second);
    }
    return v;
}

std::size_t AddressBook::count(const std::string& full_name)
{
    return contacts_.count(full_name);
}

bool AddressBook::remove(const std::string& full_name, std::size_t index)
{
    for (auto it = contacts_.begin(); it != contacts_.end(); ++it)
    {
        if (it->first == full_name)
        {
            if (index == 0)
            {
                contacts_.erase(it);
                return true;
            }
            index--;
        }
    }
    return false;
}

void AddressBook::remove_all(const std::string& full_name)
{
    for (auto it = contacts_.begin(); it != contacts_.end(); ++it)
    {
        if (it->first == full_name)
            contacts_.erase(it);
    }
}

std::ostream& operator<<(std::ostream& os, const AddressBook& b)
{
    os << b.contacts_.size() << " contact(s) in the address book.\n";

    for (const auto& elt : b.contacts_)
    {
        os << "- " << elt.first << ": " << elt.second;
    }

    return os;
}
