
#include <iostream>

#include "Form.h"


int main() {

    Circle c(2);

    std::cout << "Circle area : " << c.calcArea() <<std::endl;

    c.set_radius(3);
    std::cout << "Circle area : " << c.calcArea() <<std::endl;
    std::cout << "Circle radius : " << c.get_radius() <<std::endl;

    return 0;
}