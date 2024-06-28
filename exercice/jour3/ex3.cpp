#include <iostream>
#include <unordered_map>
#include <string>

// Classe gÃ©nÃ©rique
template <typename T, typename U>
class HashTable {
public:
    void addElement(const T& key, const U& value) {
        table[key] = value;
    }

    U findElement(const T& key) const {
        auto it = table.find(key);
        if (it != table.end()) {
            return it->second;
        } else {
            throw std::out_of_range("ClÃ© non trouvÃ©e.");
        }
    }

    bool containElement(const T& key) const {
        return table.find(key) != table.end();
    }

private:
    std::unordered_map<T, U> table;
};

// SpÃ©cialisation partielle
template <typename T>
class HashTable<std::string, T*> {
public:
    void addElement(const std::string& key, T* value) {
        table[key] = value;
    }

    T* findElement(const std::string& key) const {
        auto it = table.find(key);
        if (it != table.end()) {
            return it->second;
        } else {
            throw std::out_of_range("ClÃ© non trouvÃ©e.");
        }
    }

    bool containElement(const std::string& key) const {
        return table.find(key) != table.end();
    }

    void display() const {
        for (const auto& paire : table) {
            std::cout << "ClÃ© : " << paire.first << " ; value : " << paire.second << std::endl;
        }
    }

private:
    std::unordered_map<std::string, T*> table;
};

int main() {
    HashTable<int, std::string> tableGen;
    tableGen.addElement(1, "un");
    tableGen.addElement(2, "deux");
    std::cout << "Recherche clÃ© 1: " << tableGen.findElement(1) << std::endl;
    std::cout << "Contient la clÃ© 3 ? " << (tableGen.containElement(3) ? "Oui" : "Non") << std::endl;

    HashTable<std::string, int> tablePtr;
    int a = 10, b = 20, c = 30;
    tablePtr.addElement("dix", &a);
    tablePtr.addElement("vingt", &b);
    tablePtr.addElement("trente", &c);
    tablePtr.display();
    std::cout << "Recherche clÃ© 'dix': " << *(tablePtr.findElement("dix")) << std::endl;
    std::cout << "Contient la clÃ© 'quarante' ? " << (tablePtr.containElement("quarante") ? "Oui" : "Non") << std::endl;

    return 0;
}