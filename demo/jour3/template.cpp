#include <iostream>

template<typename T> class Base {
protected:
    T value;

public:
    Base() = default;
    Base(T v) : value(v) {};

    void displayParent() const {
        std::cout << "Valeur du parent : " << value << std::endl;
    }

    T getValue() const { return value; }
    void setValue(T v) { value = v; }
};

template<typename T, typename U>
class Derived : public Base<T> {
protected:
    U data;

public:
    Derived() = default;
    Derived(T v, U d) : Base<T>(v), data(d) { }

    void display() const {
        Base<T>::displayParent();
        std::cout << "Valeur de l'enfant : " << data << std::endl;
    }

    Derived<T, U> operator+(Derived<T, U>& other) {
        Derived<T, U> result;
        result.value = this->value + other.value;
        result.data = this->data + other.data;
        return result;
    }
};

template<>
class Derived<std::string, int> : public Base<std::string> {
protected:
    int data;

public:
    Derived() = default;
    Derived(std::string v, int d) : Base<std::string>(v), data(d) { }

    void display() const {
        std::cout << "SpÃ©cialisation totale : " << std::endl;
        Base<std::string>::displayParent();
        std::cout << "Valeur de l'enfant : " << data << std::endl;
    }

    void operator+(Derived<std::string, int>& other) {
        this->value += other.value;
        this->data += other.data;
    }
};

int main() {

    Derived<int, int> obj1(10, 20);
    Derived<std::string, int> obj2("Specialisation totale", 20);
    Derived<int, std::string> obj3(40, "Template ");
    Derived<int, std::string> obj3bis(30, "GÃ©nÃ©rique");

    obj1.display();
    auto value = obj2.getValue();
    
    obj2.display();

    auto obj4 = obj3 + obj3bis;
    obj4.display();

    return 0;
}