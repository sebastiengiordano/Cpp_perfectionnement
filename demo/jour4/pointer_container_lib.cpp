#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp>

class Fruit {
public:
    std::string name;
    Fruit(std::string n) : name(n) { }
    ~Fruit() {
        std::cout << "Destructeur" << std::endl;
    }
};

int main() {
    boost::ptr_vector<Fruit> fruitsVector;

    fruitsVector.push_back(new Fruit("kiwi"));
    fruitsVector.push_back(new Fruit("papaye"));
    fruitsVector.push_back(new Fruit("banane"));
    std::cout << fruitsVector[0].name << std::endl;
    fruitsVector.pop_back();
    typedef boost::ptr_vector<Fruit>  ptr_vec;
    for (ptr_vec::iterator i = fruitsVector.begin(); i != fruitsVector.end(); ++i) {
        std::cout << i->name << std::endl;
    }
    return 0;
}
