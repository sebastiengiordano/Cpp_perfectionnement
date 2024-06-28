#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vectorInt = { 1, 2, 3, 4, 5 };
    std::vector<int> vectorSquare(vectorInt.size());

    std::transform(vectorInt.begin(), vectorInt.end(), vectorSquare.begin(), [](int num) {
        return num * num;
    });

    std::cout << "Resultat attendu : 1 4 9 16 25" << std::endl;
    for (auto num: vectorSquare) {
        std::cout << num << " ";
    }
    return 0;
}