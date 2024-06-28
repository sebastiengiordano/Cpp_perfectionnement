#include "Form_Manager.h"

FormManager::FormManager (Shape* shape[], int shape_list_size) {
    for(int i = 0; i < shape_list_size; i++) {
        shape_list.push_back(shape[i]);
    }
};

void FormManager::Add_form(Shape* shape) {
    shape_list.push_back(shape);
};

void FormManager::calcAllArea() {
    for(Shape* shape : shape_list) {
        std::cout << "shape type = ";
        shape->getType();
        std::cout << "\t Perimeter of shape :" << shape->calcPerimeter() << std::endl;
    }
};

int main() {
    Circle*     c;
    Rectangle*  r;
    Triangle*   t;
    Square*     s;

    c = new Circle(3);
    r = new Rectangle(3, 4);
    t = new Triangle(1, 2, 3);
    s = new Square(7);

    Shape* shape[] = {c, r, t, s};

    FormManager f(shape, 4);

    f.calcAllArea();

    return 0;
}
