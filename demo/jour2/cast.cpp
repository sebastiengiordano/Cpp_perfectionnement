#include <iostream>
#include <limits>

class A {
public:
    A() = default;
    virtual ~A() {}
};

class B : public A {
private:
    char v;
public:
    B() { v = 'a'; };
    void doSomething() const { std::cout << "Class B" << std::endl; }
};

class C : public A {
private:
    int value;

public:
    C() { value = 42; };
    void doSomething() const { std::cout << "Class C" << std::endl; }
    int getValue() const { return value; }
};

int main() {

    // static_cast et explicite cast
    float f = 3.5;
    int value = static_cast<int>(f);
    std::cout << "Conversion statique : " << std::endl;
    std::cout << value << std::endl;
    std::cout << (int)f << std::endl;

    // const_cast
    // A n'utilisez qu'en cas d'absolue nécessitée (utilisation d'API legacy par exemple qui retournerait des structures ou des objets ne pouvant pas Ãªtre copiés  ...)   
    const int const_value = 10;
    int *newValue = const_cast<int*>(&const_value);
    std::cout << "const_value : " << const_value << " ; newValue : " << *newValue << std::endl;
    *newValue = 20;
    std::cout << "const_value : " << const_value << " ; newValue : " << *newValue << std::endl;

    int i = 3;                 // i is not declared const
    const int& rci = i;
    const_cast<int&>(rci) = 4; // OK: modifies i
    std::cout << "i = " << i << '\n';
    std::cout << "rci = " << rci << '\n';
 

    // reinterpret_cast
    int *ptr_int = new int(48);
    char *ptr_char = reinterpret_cast<char*>(ptr_int);
    std::cout << *ptr_char << std::endl;
    ptr_int = reinterpret_cast<int*>(ptr_char);
    std::cout << *ptr_int << std::endl;
    delete(ptr_int);

    double *my_double = new double(std::numeric_limits<double>::max());
    float *my_float = reinterpret_cast<float*>(my_double);
    std::cout << "Float : " << *my_float << std::endl;
    // Résultat obtenu : nan

    void *data = static_cast<void*>(my_double);
    my_float = static_cast<float*>(data);
    std::cout << "Float : " << *my_float << std::endl;
    // Résultat obtenu : nan
    
    delete(my_double);

    std::string str = "Hello World";
    A a;
    B b;
    void *voidPtr = &str;

    // Exemple de reinterpret_cast "fonctionnel"
    C *c = reinterpret_cast<C*>(&b);
    c->doSomething();
    std::cout << "Value : " << c->getValue() << std::endl;

    std::cout << "Entier : " << typeid(i).name() << std::endl;
    std::cout << "Float : " << typeid(f).name() << std::endl;
    std::cout << "String : " << typeid(str).name() << std::endl;
    std::cout << "Classe A : " << typeid(a).name() << std::endl;
    std::cout << "Classe B : " << typeid(b).name() << std::endl;
    std::cout << "Void * 1 : " << typeid(data).name() << std::endl;
    std::cout << "Void * 2 : " << typeid(voidPtr).name() << std::endl;

    if (typeid(b) == typeid(B)) {
        std::cout << "b est bien une classe de type B" << std::endl;
    }

    if (typeid(b) == typeid(A))
        std::cout << "b est bien une classe de type A" << std::endl;
    else 
        std::cout << "b n'est pas une classe de type A" << std::endl;

    try {

        // Dynamic_cast
        B derived;

        // upcast : conversion d'une classe dérivée en classe de base
        derived.doSomething();
        A *ptr = dynamic_cast<A*>(&derived);
        // A *ptr = static_cast<A*>(&derived);
        if (ptr) {
            std::cout << "Conversion upcast réussie" << std::endl;
            if (typeid(*ptr) == typeid(B))
                std::cout << "ptr contient bien une classe de type B" << std::endl;
            if (typeid(ptr) == typeid(A*))
                std::cout << "ptr est bien pointeur de type A" << std::endl;
            //ptr->doSomething();  => ne compile pas !
        }

        // downcast : conversion d'une classe de base en classe dérivée
        A *ptrBase = new B();
        //ptrBase->doSomething();     => ne compile toujours pas ! =(

        B *ptrDerived = dynamic_cast<B*>(ptrBase);
        if (ptrDerived != nullptr) {
            ptrDerived->doSomething();
        } else {
            std::cout << "Conversion échouée ! " << std::endl;
        }
    
    // Dans le cas d'une conversion dynamique, on a un risque d'exception de type bad_cast
    } catch (std::bad_cast e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}