#include "shared_pointer.hh"

class Animal
{
public:
    virtual ~Animal()
    {}
};

class Cat : public Animal
{
public:
    void meow()
    {
        std::cout << "Meow!\n";
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        std::cout << "Woof!\n";
    }
};

int main()
{
    SharedPointer<Animal> animalPtr{ new Cat };
    if (animalPtr.is_a<Cat>())
    { // true
        std::cout << "The pointer points to a Cat.\n";
    }

    SharedPointer<Animal> animalPtr2{ new Dog };
    if (animalPtr2.is_a<Cat>())
    { // false
        std::cout << "The pointer points to a Cat.\n";
    }
    else if (animalPtr2.is_a<Dog>())
    {
        std::cout << "The pointer points to a Dog.\n";
    }

    return 0;
}
