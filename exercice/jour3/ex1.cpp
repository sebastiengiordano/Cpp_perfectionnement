#include <iostream>
#include <vector>

template <typename T>
class Liste {
private:
    std::vector<T> myList;

public:
    Liste() {}
    Liste(std::vector<T> listElements) : myList(listElements) { }

    void addElement(const T& element) {
        myList.push_back(element);
    }

    void removeElement(const T& element) {
        for (auto it = myList.begin(); it != myList.end(); ++it) {
            if (*it == element) {
                myList.erase(it);
                break;
            }
        }
    }

    void displayElements() const {
        for (const auto& element : myList) {
            std::cout << element << " - ";
        }
        std::cout << std::endl;
    }

    void clearElements() {
        myList.clear();
    }
};

int main() {
    Liste<int> listeInt;

    listeInt.addElement(21);
    listeInt.addElement(42);
    listeInt.addElement(84);
    listeInt.addElement(421);
    listeInt.displayElements();
    std::cout << "Suppression d'un Ã©lÃ©ment : " << std::endl;
    listeInt.removeElement(421);
    listeInt.displayElements();
    std::cout << "Nettoyage de la liste : " << std::endl;
    listeInt.clearElements();
    listeInt.displayElements();

    Liste<std::string> listeStr;

    listeStr.addElement("Hello");
    listeStr.addElement("Salut");
    listeStr.addElement("Hi");
    listeStr.addElement("World");
    listeStr.displayElements();
    std::cout << "Suppression d'un Ã©lÃ©ment : " << std::endl;
    listeStr.removeElement("World");
    listeStr.displayElements();
    std::cout << "Nettoyage de la liste : " << std::endl;
    listeStr.clearElements();
    listeStr.displayElements();
    
    return 0;
}