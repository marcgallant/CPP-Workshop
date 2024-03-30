#include "person.hh"

Person::Person(const std::string& name, uint money)
    : name_(name)
    , money_(money)
{}

std::vector<std::string> Person::enumerate_nfts() const
{
    std::vector<std::string> res;

    for (const std::unique_ptr<std::string>& nft : nfts_)
    {
        res.push_back(*nft);
    }

    return res;
}

void Person::add_nft(NFT nft)
{
    nfts_.push_back(std::move(nft));
}

NFT Person::remove_nft(const std::string& name)
{
    for (auto it = nfts_.begin(); it != nfts_.end();)
    {
        if (*(*it) == name)
        {
            auto tmp = std::move(*it);
            nfts_.erase(it);
            return tmp;
        }
        else
            ++it;
    }
    return create_empty_nft();
}

void Person::add_money(uint money)
{
    money_ += money;
}

bool Person::remove_money(uint money)
{
    bool res = money_ >= money;
    if (res)
        money_ -= money;
    return res;
}

uint Person::get_money() const
{
    return money_;
}

const std::string& Person::get_name() const
{
    return name_;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "Name: " << p.get_name() << "\n";
    os << "Money: " << p.get_money() << "\n";
    os << "NFTs:";

    for (const std::string& nft : p.enumerate_nfts())
    {
        os << " " << nft;
    }

    return os << "\n";
}
