#pragma once

#include <optional>
#include <string>

class ContactDetails
{
public:
    ContactDetails(const std::string& telephone_number,
                   const std::string& personal_email);
    static std::optional<ContactDetails>
    makeDetails(const std::string& telephone_number,
                const std::string& personal_email);

    friend std::ostream& operator<<(std::ostream& os,
                                    const ContactDetails& contactDetails);

private:
    std::string number_;
    std::string email_;
};