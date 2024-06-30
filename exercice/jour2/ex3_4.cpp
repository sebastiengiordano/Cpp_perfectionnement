#include <iostream>
#include <vector>

class Accumulator {
    private:
        int total = 0;

    public:
        int getTotal() const {
            return total;
        }

        void operator()(int value) {
            total += value;
        }
};

class ProxyArray {
    private:
        std::vector<int> *intArray;
        int* references;

    public:
        ProxyArray(std::vector<int> *tab, int *ref) : intArray(tab), references(ref) {
            (*references)++;
        }

        ~ProxyArray() {
            (*references)--;
            if (*references == 0) {
                delete intArray;
                delete references;
            }
        }

        size_t getSize() const {
            return intArray->size();
        }

        // Affichage de l'adresse via une méthode "classique" :
        std::vector<int>* getAddress() const {
            return intArray;
        }

        // Affichage de l'adresse Ã  travers la surcharge de l'opérateur "&" :
        std::vector<int>* operator&() const {
            return intArray;
        }

        bool operator==(const ProxyArray& other) const {
            return intArray == other.intArray;
        }

        bool operator!=(const ProxyArray& other) const {
            return intArray != other.intArray;
        }

        int& operator[](size_t index) const {
            return (*intArray)[index];
        }

        void operator>>(int value) {
            intArray->push_back(value);
        }

        friend std::ostream& operator<<(std::ostream& os, const ProxyArray& proxy);
};

std::ostream& operator<<(std::ostream& os, const ProxyArray& proxy) {
    for (size_t i = 0; i < proxy.getSize(); i++) {
        os << proxy[i] << " ";
    }
    return os;
}

int main() {
    std::vector<int> *tab = new std::vector<int>{1, 2, 3, 4, 5, 6};
    ProxyArray proxy(tab, new int(1));
    Accumulator accumulator;

    // Utilisation de l'accumulateur pour afficher le total des valeurs :
    for (size_t i = 0; i < proxy.getSize(); i++) {
        accumulator(proxy[i]);
    }
    std::cout << "Total des valeurs : " << accumulator.getTotal() << std::endl;

    // Ajout d'une nouvelle valeur et affichage du proxy : 
    proxy >> 7;
    std::cout << proxy << std::endl;

    // Affichage de l'adresse du proxy :
    std::vector<int>* ptr = &proxy;
    std::cout << "Adresse du proxy : " << ptr << std::endl;    

    return 0;
}