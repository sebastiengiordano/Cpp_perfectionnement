#include <array>
#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iterator>
#include <iostream>


/*
Exercice 2 :
Créez une fonction qui prend un tableau d’entiers en paramètre et divise ce tableau en deux
tableaux temporaires contenant chacun la moitié des nombres du tableau initial.
Effectuez le calcul du total de chacun des deux tableaux dans un thread différent.
Conseil : utilisez std::ref pour passer un objet contenant une référence aux threads.
*/


void sum(std::vector<int> vec, int& ret_val) {
    ret_val = std::accumulate(vec.begin(), vec.end(), 0);
}


template<std::size_t SIZE>
void div_array(std::array<int, SIZE> my_array) {
    auto mid = static_cast<int>(SIZE / 2);

    int res1;
    int res2;
    std::vector<int> vec_1; 
    std::vector<int> vec_2;

    std::copy(
        my_array.begin(),
        my_array.begin() + mid + 1,
        std::back_inserter(vec_1));
    std::copy(
        my_array.begin() + mid + 1,
        my_array.end(),
        std::back_inserter(vec_2));


    std::thread t1 (sum, vec_1, std::ref(res1));
    std::thread t2 (sum, vec_2, std::ref(res2));

    t1.join();
    t2.join();

    std::cout << "Ma somme = " << res1 + res2 << std::endl;

    // std::future<int> ret1 = std::async(std::launch::async, std::accumulate, my_array.begin(), my_array.begin() + mid, 0);
    // std::future<int> ret2 = std::async(std::launch::async, std::accumulate, my_array.begin() + mid + 1, my_array.end(), 0);
    // std::cout << "Ma somme = " << ret1.get() + ret2.get() << std::endl;
    
}

int main () {
    std::array<int, 7> my_array = {12, 27, 36, 159, 753, 654, 22};

    div_array<7>(my_array);

    std::cout << "Ma somme directement = " << std::accumulate(my_array.begin(), my_array.end(), 0) << std::endl;

    return 0;
}
