#include <iostream>

bool checkPointer(void *ptr) {
    if (ptr == nullptr) {
        std::cout << "Pointeur null" << std::endl;
    } else {
        std::cout << "Pointeur valide" << std::endl;
        return true;
    }
    return false;
}

int main() {
    int *test_ptr = new int;

    checkPointer(test_ptr);

    delete test_ptr;
}