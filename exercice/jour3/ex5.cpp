#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {11, 12, 3, 14, 5, 166, 71, 81, 9, 10, 11, 12};
    std::vector<int> squaredNumbers;
    std::vector<int> mergeVector;
    std::vector<int> copyVector;
    int nbToFind = 9;

    std::sort(numbers.begin(), numbers.end());
    for (const auto& elem : numbers) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    std::transform(numbers.begin(), numbers.end(), std::back_inserter(squaredNumbers), [](int num) {
        return num * num;
    });
    for (const auto& elem : squaredNumbers) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Somme des nombres du vecteur : " << sum << std::endl;


    std::merge(numbers.begin(), numbers.end(), squaredNumbers.begin(), squaredNumbers.end(), std::back_inserter(mergeVector));
    for (const auto& elem : mergeVector) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int num) {
        return num % 2 == 0;
    }), numbers.end());
    for (const auto& elem : numbers) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    auto nbFound = std::find(numbers.begin(), numbers.end(), nbToFind);
    if (nbFound != numbers.end()) {
        std::cout << "On a bien trouvé le nombre " << nbToFind << std::endl;
    }

    std::size_t nbElements = numbers.size();
    std::cout << "Le vecteur contient " << nbElements << " éléments." << std::endl;

    copyVector.insert(copyVector.begin(), numbers.begin(), numbers.end());
    for (const auto& elem : copyVector) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
    return 0;
}