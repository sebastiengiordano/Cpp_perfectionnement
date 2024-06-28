#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <numeric>

std::mutex m;

int calc(int a, int b) {
    // std::this_thread::sleep_for(std::chrono::seconds(5));
    return a * b;
} 

void f(const std::string& str) {
    std::cout << str << std::endl;
}

void reverseStr(std::vector<std::string>& vec) {
    // Verrouillage du mutex
    // m.lock();
    // if (m.try_lock())       => Vérifie si on peut verrouiller le mutex
    // lock_guard permet de gérer automatiquement le verrouillage et le déverrouillage du mutex
    std::lock_guard<std::mutex> lockguard(m);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::reverse(vec.begin(), vec.end());
    for (auto str : vec) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << str << " ";
    }
    // Déverrouillage du mutex
    // m.unlock();
}

int main() {
    // auto result;
    std::cout << "Démo de std::async " << std::endl;
    // std::future<int> future = std::async(calc, 3, 5);
    std::future<int> future = std::async(std::launch::async, calc, 3, 5);
    // std::future<int> future = std::async(std::launch::deferred, calc, 3, 5);
    // On peut différer l'appel Ã  get pour récupérer le résultat beaucoup plus tard
    int result = future.get();
    std::cout << "Résultat : " << result << std::endl;
    // std::cout << "Résultat : " << future.get() << std::endl;     => on ne peut faire appel qu'une fois Ã  get()

    int newResult = result * 10;
    std::cout << "15 x 10 = " << newResult << std::endl;

    std::vector<std::string> vec = { "abc", "abcd","abce","abcf","abcg","abch","abci","abcj","abck","abcl","abcm", "abcn", "abco"};

    std::thread t(f, "Je suis un thread");
    std::cout << "Identifiant du thread : " << t.get_id() << std::endl;
    // t.detach();      => un thread peut Ãªtre détaché mais ne peut plus Ãªtre remis dans un état joignable. Il va fonctionner de maniÃ¨re autonome en arriÃ¨re-plan.
    t.join();

    std::thread t1(reverseStr, std::ref(vec));
    std::thread t2(reverseStr, std::ref(vec));
    std::thread t3(reverseStr, std::ref(vec));
    std::thread t4(reverseStr, std::ref(vec));
    std::thread t5(reverseStr, std::ref(vec));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout << "Résultat final : " << std::endl;
    for (auto str : vec) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::vector<int> v = {12,1,2,3,5};
    std::future<int> future_2 = std::async(std::launch::async, std::accumulate, v.begin(), v.end(), 0);

    return 0;
}