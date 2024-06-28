#include <iostream>

class Data {
private:
    std::string strData;

public:
    Data(std::string s) {
        this->strData = s;
    }

    std::string getData() const {
        return strData;
    }

    friend class Logger;
};

class Logger {
public:
    void displayValue(Data& obj) const {
        std::cout << "Affichage : " << obj.strData << std::endl;    
    }

    void changeValue(Data& obj) {
        obj.strData = "Valeur modifie";
        std::cout << "Logger : " << obj.strData << std::endl;
    }

};

int main() {
    Data obj("Hello World");

    Logger l;
    l.displayValue(obj);
    l.changeValue(obj);
    std::cout << "Nouvelle valeur : " << obj.getData() << std::endl;
    return 0;
}