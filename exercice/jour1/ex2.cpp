#include <iostream>

class Shape {
public:
    double calcArea() const {
        std::cout << "Calcul de l'aire de forme" << std::endl;
        return 0;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) { }

    using Shape::calcArea;

    double calcArea() const {
        return 3.14 * radius * radius;
    }
};

int main() {
    Circle circle(3);

    std::cout << "Aire du cercle : " << circle.calcArea() << std::endl;
    std::cout << "Aire de la forme : " << circle.Shape::calcArea() << std::endl;
    return 0;
}