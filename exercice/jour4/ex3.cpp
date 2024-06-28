#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx;

void calcTotal(const std::vector<int>& array, int& sum, size_t start, size_t end) {
    for (size_t i = start; i < end; i++) {
        sum += array[i];
        std::cout << "sum : " << sum << ", i : " << i << std::endl;
    }
}

int main() {
    std::vector<int> numArray  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    };
    size_t halfSize = numArray.size() / 2;

    int total = 0;

    // std::thread t1(calcTotal, std::ref(numArray), std::ref(total), 0, halfSize);
    // std::thread t2(calcTotal, std::ref(numArray), std::ref(total), halfSize, numArray.size());
    std::thread t1([&]() {
        std::lock_guard<std::mutex> lock(mtx);
        calcTotal(numArray, total, 0, halfSize);
    });
    std::thread t2([&]() {
        std::lock_guard<std::mutex> lock(mtx);
        calcTotal(numArray, total, halfSize, numArray.size());
    });

    t1.join();
    t2.join();

    std::cout << "Somme totale : " << total << std::endl;

    return 0;
}