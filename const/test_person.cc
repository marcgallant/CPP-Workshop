#include <iostream>

#include "person.hh"

int main()
{
    Person my_person("Gordon Freeman", 47);

    const Person& my_person2 = my_person;

    std::cout << "name: " << my_person2.get_name()
              << ", years: " << my_person2.get_age() << std::endl;

    std::string name = "Alyx Vance";
    my_person.set_name(name);
    my_person.set_age(24);

    std::cout << "name: " << my_person2.get_name()
              << ", years: " << my_person2.get_age() << std::endl;
}
