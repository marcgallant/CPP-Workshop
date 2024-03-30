#include "contact_details.hh"

#include <algorithm>

ContactDetails::ContactDetails(const std::string& telephone_number,
                               const std::string& personal_email)
    : number_(telephone_number)
    , email_(personal_email)
{}

std::optional<ContactDetails>
ContactDetails::makeDetails(const std::string& telephone_number,
                            const std::string& personal_email)
{
    if (personal_email.find('@') == std::string::npos
        || !std::all_of(telephone_number.begin(), telephone_number.end(),
                        ::isdigit))
        return std::nullopt;
    return ContactDetails(telephone_number, personal_email);
}

std::ostream& operator<<(std::ostream& os, const ContactDetails& contactDetails)
{
    std::string separator = ", ";
    std::string end = "\n";
    return os << contactDetails.number_ << separator << contactDetails.email_
              << end;
}
