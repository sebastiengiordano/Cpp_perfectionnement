#include <algorithm>
#include <iostream>
#include <vector>

class FunctorRemoveIf {
    public:
        bool operator()(int number) const {
            return number % 2 != 0;
        }
};

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    FunctorRemoveIf fri;

    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), fri), numbers.end());

    for (const auto& n: numbers) {
        std::cout << n << " ";
    }

    return 0;
}