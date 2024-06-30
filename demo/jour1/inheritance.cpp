#include <iostream>

class IAnimal {
public:
    virtual ~IAnimal() {};
    virtual void sleep() = 0;
    virtual void eat() = 0;
};

class AbstractAnimal : public IAnimal {
    public:
        virtual ~AbstractAnimal() { };
        virtual void sleep() = 0;
        virtual void eat() { std::cout << "Animal mange" << std::endl; }
};

class Herbivore : public AbstractAnimal {
    public:
        Herbivore() = default;
        void sleep() override { std::cout << "Zzz" << std::endl; };
        virtual void eat() override { std::cout << "Herbivore mange" << std::endl; }
};

class Rabbit : public Herbivore {
    public:
        Rabbit() = default;
        void eat() override { std::cout << "Lapin mange" << std::endl; }
};

class Cat : public AbstractAnimal {
    public:
        Cat() = default;
        void sleep() { std::cout << "Zzz" << std::endl; }
        void eat() { std::cout << "Chat mange" << std::endl; }
};

class A {
    public:
        A() { std::cout << "A" << std::endl; }
};

class B : virtual public A {
    public:
        B() { std::cout << "B" << std::endl; }
};

class C : virtual public A {
    public:
        C() { std::cout << "C" << std::endl; }
};

class D : public B, public C {
    public:
        D() { std::cout << "D" << std::endl; }
};

int main() {
    D d;
    C c;
    Rabbit lapin;
    lapin.eat();

    AbstractAnimal *animal;

    animal = &lapin;
    animal->eat();

    Herbivore *h;
    h = &lapin;
    h->eat();
    return 0;
}