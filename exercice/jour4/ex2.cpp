#include <iostream>
#include <thread>
#include <vector>

void calcTotal(const std::vector<int>& array, int& sum) {
    for (auto& number : array) {
        sum += number;
    }
}

int main() {
    std::vector<int> numArray  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    size_t halfSize = numArray.size() / 2;

    std::vector<int> tmpArray1(numArray.begin(), numArray.begin() + halfSize);
    std::vector<int> tmpArray2(numArray.begin() + halfSize, numArray.end());

    int sum1 = 0;
    int sum2 = 0;
    int total = 0;

    // std::thread t1(calcTotal, &tmpArray1, &sum1);
    // std::thread t2(calcTotal, &tmpArray2, &sum2);
    std::thread t1(calcTotal, std::ref(tmpArray1), std::ref(sum1));
    std::thread t2(calcTotal, std::ref(tmpArray2), std::ref(sum2));

    t1.join();
    t2.join();

    total = sum1 + sum2;
    std::cout << "Somme totale : " << total << std::endl;

    return 0;
}