#include <algorithm>
#include <iostream>
#include <vector>

class SortVector {
    public:
        bool operator()(const std::string& a, const std::string& b) {
            return a.length() < b.length();
        }
};

int main() {
    std::vector<std::string> animals = { "chien", "chat", "ornythorique", "lion", "poisson" };

    // Exemple d'utilisation de std::sort avec une lambda
    // std::sort(animals.begin(), animals.end(), [](const auto& a, const auto& b) {
    //     return a.length() < b.length();
    // });

    SortVector sv;

    // Exemple d'utilisation de std::sort avec un foncteur
    std::sort(animals.begin(), animals.end(), sv);

    for (const auto& animal: animals) {
        std::cout << animal << " ";
    }
    return 0;
}