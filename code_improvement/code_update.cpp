#include <vector>
#include <iostream>
#include <algorithm>

void printvector(std::vector<int> vector) {
    for (auto& elem: vector){
        std::cout << elem << std::endl;
    }
}

void reverseVector(std::vector<int>& vector){
    std::vector<int> tmp(vector.size());
    std::reverse(vector.begin(), vector.end());
    // printvector(tmp);
    // std::copy(tmp.begin(), tmp.end(), , vector);
    // vector = &tmp;
}

int main() {
    std::vector<int> vector(5, 0);

    auto i = 0;
    std::transform(vector.cbegin(), vector.cend(), vector.begin(), [i](auto elem) mutable {
        i++;
        return i;
    });

    printvector(vector);

    std::cout << std::endl << "reverseVector" << std::endl;
    reverseVector(vector);
    printvector(vector);
    return 0;
}
