#include <iostream>

# define M_PI           3.14159265358979323846  /* pi */

class Shape
{
public:
    Shape() = default;
    virtual ~Shape() {};

    virtual float calcArea() { return 0; };
    virtual float calcPerimeter() { return 0; };
    virtual void getType() { std::cout << kind_of_shape << std::endl; };

protected:
    std::string kind_of_shape;
};


class Circle: public Shape
{
public:
    Circle(int radius): radius{radius} {
        kind_of_shape = "Circle";
    };
    virtual ~Circle() { };

    virtual float calcPerimeter() { return 2 * M_PI * radius; };
    virtual float calcArea() { return M_PI * radius * radius; };

    void set_radius(int radius) { this->radius = radius; }
    int  get_radius() { return radius; }

protected:
    int radius;
};


class Rectangle: public Shape
{
public:
    Rectangle(int hight, int width): hight{hight}, width{width} {
        kind_of_shape = "Rectangle";
    };
    virtual ~Rectangle() { };

    virtual float calcPerimeter() { return 2 * (hight + width); };
    virtual float calcArea() { return hight * width; };

protected:
    int hight;
    int width;
};


class Triangle: public Shape
{
public:
    Triangle(int cote1, int cote2, int cote3): cote1{cote1}, cote2{cote2}, cote3{cote3} {
        kind_of_shape = "Triangle";
    };
    virtual ~Triangle() { };

    virtual float calcPerimeter() { return cote1 + cote2 + cote3; };

protected:
    int cote1;
    int cote2;
    int cote3;
};


class Square: public Shape
{
public:
    Square(int cote): cote{cote} {
        kind_of_shape = "Square";
    };
    virtual ~Square() { };

    virtual float calcPerimeter() { return 4 * cote; };
    virtual float calcArea() { return cote * cote; };


protected:
    int cote;
};

