#include <iostream>
 
class Animal {
public:
    virtual void eat() { std::cout << "Animal mange" << std::endl; }
    void sleep() { std::cout << "Animal dort" << std::endl; }
};

class Oiseau : public Animal {
public:
    void eat() { std::cout << "Oiseau mange" << std::endl; }
    void sleep() { std::cout << "Oiseau dort" << std::endl; }
};

class Rabbit : public Animal {
public:
    void eat() { std::cout << "Lapin mange" << std::endl; }
    void sleep() { std::cout << "Lapin dort" << std::endl; }
};
 
int main()
{
    Animal *animal;
    Rabbit lapin;
    animal = &lapin;
 
    animal->eat();
    animal->sleep();
 
    Oiseau oiseau;
    animal = &oiseau;
    animal->eat();
    return 0;
}