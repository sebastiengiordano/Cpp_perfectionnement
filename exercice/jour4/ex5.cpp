#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class ArrayManager {
public:
    ArrayManager(int size) : size(size), arr(std::make_unique<std::vector<int>>(size)) {
        for (int i = 0; i < size; ++i) {
            (*arr)[i] = i + 1;
        }
    }

    const std::vector<int>& getArray() const {
        return *arr;
    }

    void setArray(const std::vector<int>& newArr) {
        if (newArr.size() == size) {
            *arr = newArr;
        }
    }

    void printArray() const {
        for (const auto& elem : *arr) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    void reverseArray() {
        std::reverse(arr->begin(), arr->end());
    }

private:
    int size;
    std::unique_ptr<std::vector<int>> arr;
};

int main() {
    ArrayManager arrayManager(5);

    std::cout << "Original array: ";
    arrayManager.printArray();

    arrayManager.reverseArray();

    std::cout << "Reversed array: ";
    arrayManager.printArray();

    return 0;
}