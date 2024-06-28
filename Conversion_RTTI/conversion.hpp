#include <iostream>


class Animal
{
public:
    Animal() = default;
    virtual ~Animal() = default;

    virtual void makeNoise() {
        std::cout << "The Animal make noise" << std::endl;};
};



class Dog : public Animal
{
public:
    Dog() = default;
    virtual ~Dog() = default;

    void makeNoise() override;
};


class Cat : public Animal
{
public:
    Cat() = default;
    virtual ~Cat() = default;

    void makeNoise() override;
};
