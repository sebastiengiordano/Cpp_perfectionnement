#include <iostream>
#include <boost/signals2.hpp>

// https://www.boost.org/doc/libs/1_83_0/doc/html/signals2/tutorial.html

void slot1() {
    std::cout << "Slot 1 appelÃ©" << std::endl;
}

void slot2() {
    std::cout << "Slot 2 appelÃ©" << std::endl;
}

int main() {
    boost::signals2::signal<void()> mySignal;

    mySignal.connect(slot1);
    mySignal.connect(slot2);
    mySignal(); // Emet le signal
    mySignal.disconnect(slot1);
    mySignal();
    return 0;
}
