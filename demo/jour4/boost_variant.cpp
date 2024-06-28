#include <iostream>
#include <boost/variant.hpp>

int main() {

    boost::variant<int, std::string> variant("Hello World !");
    variant = 42;

    try {
        if (variant.type() == typeid(int)) {
            int value = boost::get<int>(variant);
            std::cout << value;
        } else if (variant.type() == typeid(std::string)) {
            std::string value = boost::get<std::string>(variant);
            std::cout << value;
        }
        std::cout << " : " << variant.which() << std::endl;
    } catch (const boost::bad_get& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}
