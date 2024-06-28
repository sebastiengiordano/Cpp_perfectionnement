#include <vector>
#include <iostream>
#include <algorithm>

class Functor {
public:
    Functor () = default;

    bool operator() (const std::string& string_1, const std::string& string_2){
        return string_1.size() <=  string_2.size();
    }

    bool operator() (const int& myInt){
        return bool (myInt % 2);
    }
};


int main() {
    std::vector<std::string> chaine = {"Une chaine", "de", "caractère", "plus ou moins", "longue", "."};

    std::sort(chaine.begin(), chaine.end(), Functor());

    std::cout << std::endl << "Ma chaine de caractère triée : " << std::endl;
    for (auto elem : chaine){
        std::cout << elem << std::endl;
    }


    std::vector<int> entiers = {112, 27, 3, 58, 97, 1, 1000, 159};

    auto remove = std::remove_if(entiers.begin(), entiers.end(), Functor());
    entiers.erase(remove, entiers.end());

    std::cout << std::endl << "Suppresion des nombres impairs : " << std::endl;
    for (auto elem : entiers){
        std::cout << elem << std::endl;
    }


    return 0;
}