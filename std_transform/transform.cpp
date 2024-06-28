#include <vector>
#include <algorithm>
#include <iostream>


int main (){
    std::vector<int> v = {2, 7, 3, 8, 111, 6};

    std::transform(v.cbegin(), v.cend(), v.begin(), [](auto& num) {
        return num * num;
    });

    int i = 0;
    for (auto num: v){
        i++;
        std::cout << i << ": " << num <<  std::endl;
    }
    return 0;
}