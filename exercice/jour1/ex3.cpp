#include <iostream>
#include <cmath>
#include <vector>

class Shape {
public:
    virtual ~Shape() {}
    virtual double calcArea() const = 0;
    virtual double calcPerimeter() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) { }

    double calcArea() const override {
        return 3.14 * radius * radius;
    }

    double calcPerimeter() const override {
        return 2 * 3.14 * radius;
    }
};

class Triangle : public Shape {
private:
    double base;
    double side1;
    double side2;

public:
    Triangle(double b, double s1, double s2) : base(b), side1(s1), side2(s2) { }

    double calcArea() const override {
        double half_perimeter = calcPerimeter() / 2;
        return sqrt(half_perimeter * (half_perimeter - base) * (half_perimeter - side1) * (half_perimeter - side2));
    }

    double calcPerimeter() const override {
        return base + side1 + side2;
    }
};

class Rectangle : public Shape {
protected:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) { }

    double calcArea() const override {
        return length * width;
    }

    double calcPerimeter() const override {
        return length * 2 + width * 2;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {};
};

class ShapeManager {
private:
    std::vector<Shape*> vectorShapes;

public:
    ShapeManager() = default;

    void addShape(Shape *shape) {
        vectorShapes.push_back(shape);
    }

    double calcTotalArea() const {
        double totalArea = 0;

        for (const auto& shape: vectorShapes) {
            totalArea += shape->calcArea();
        }
        return totalArea;
    }
};

int main() {
    Circle circle(3);
    Triangle triangle(4, 2, 2.5);
    Rectangle rectangle(6, 5);
    Square square(4);
    ShapeManager sm;

    std::cout << "Aire du cercle : " << circle.calcArea() << std::endl;
    std::cout << "Perimetre du cercle : " << circle.calcPerimeter() << std::endl;
    std::cout << "Aire du triangle : " << triangle.calcArea() << std::endl;
    std::cout << "Perimetre du triangle : " << triangle.calcPerimeter() << std::endl;
    std::cout << "Aire du rectangle : " << rectangle.calcArea() << std::endl;
    std::cout << "Perimetre du rectangle : " << rectangle.calcPerimeter() << std::endl;
    std::cout << "Aire du square : " << square.calcArea() << std::endl;
    std::cout << "Perimetre du square : " << square.calcPerimeter() << std::endl;

    sm.addShape(&circle);
    sm.addShape(&triangle);
    sm.addShape(&rectangle);
    sm.addShape(&square);

    std::cout << "Aire totale des formes : " << sm.calcTotalArea() << std::endl;
    return 0;
}