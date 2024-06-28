#include <iostream>
#include "Form.h"

void check_pointeur(void* myPtr) {
    if (myPtr == nullptr) {
        std::cout << "Pointeur nul" << std::endl;
    }
    else {
        std::cout << "Pointeur valide" << std::endl;        
    }
}


int main() {
    Square*     s;
    s = new Square(3);

    std::cout << "Test avec un pointeur valide :" << std::endl;
    check_pointeur(s);

    delete(s);
    std::cout << std::endl << "Test avec un pointeur null :" << std::endl;
    check_pointeur(s);

    return 0;
}