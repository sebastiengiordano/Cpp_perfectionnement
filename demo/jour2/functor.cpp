#include <algorithm>
#include <iostream>
#include <vector>

class Date
{
private:
    int day, month, year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {};
    ~Date() = default;

    friend std::ostream& operator<<(std::ostream& os, const Date& dt);/* {
        os << dt.day << "/" << dt.month << "/" << dt.year;
        return os;
    }*/

    void operator+(const Date& dt) {
        this->day += dt.day;
    }
};

std::ostream& operator<<(std::ostream& os, const Date& dt) {
    os << dt.day << "/" << dt.month << "/" << dt.year;
    return os;
}

void display(int i) {
    std::cout << i << std::endl;
}

class Display {
public:
    Display() = default;

    void operator()(int value) {
        std::cout << value << std::endl;
    }
};

class Operande {
private:
    char operande;
    int total;

public:
    Operande(char op) : operande(op) {
        total = 0;
    }

    int operator()(int value) {
        if (operande == '+') {
            total += value;
        } else if (operande == '-') {
            total -= value;
        }
        return total;
    }

    int operator()(int v1, int v2) {
        if (operande == '+') {
            total = v1 + v2;
        } else if (operande == '-') {
            total = v1 - v2;
        }
        return total;
    }
};

int main() {
    int a = 10;
    // 'r' est une rÃ©fÃ©rence de 'a'
    int& r = a;

    std::cout << "r : " << r << std::endl;

    int b = 20;
    // 'r' prend la valeur de 'b' mais ne devient pas une rÃ©fÃ©rence 'b'
    r = b;

    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "r : " << r << std::endl;

    // Ici on modifie la valeur de 'r', ce qui n'impact pas la variable 'b' 
    r = 30;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "r : " << r << std::endl;
    
    Date dt(26, 6, 2024);
    std::cout << dt << std::endl;

    std::vector<int> v = { 1, 2, 3, 4, 5 };
    Display myDisplayFunctor;

    std::cout << v[0] << std::endl;

    std::for_each(v.begin(), v.end(), display);
    std::for_each(v.begin(), v.end(), [](int i) {
        std::cout << i << std::endl;
    });
    std::for_each(v.begin(), v.end(), myDisplayFunctor);

    Operande op('+');
    int result = 0;

    for (int i = 0; i < 5; i++) {
        result = op(i);
        std::cout << "On ajoute i : " << i << " = " << result << std::endl;
    }

    result = op(20, 22);
    std::cout << "20 + 22 = " << result << std::endl;
    return 0;
}