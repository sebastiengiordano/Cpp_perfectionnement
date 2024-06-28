#include <iostream>
#include <boost/any.hpp>

int main() {
    boost::any value = 42;

    try {
        int intValue = boost::any_cast<int>(value);
        //float floatValue = boost::any_cast<float>(value);
        std::cout << intValue << std::endl;
    } catch (const boost::bad_any_cast& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}
