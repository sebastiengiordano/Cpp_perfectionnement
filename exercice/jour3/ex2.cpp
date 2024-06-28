#include <iostream>

template<typename T, typename U>
class Pair {
protected:
    T firstValue;
    U secondValue;

public:
    Pair(const T& v1, const U& v2) : firstValue(v1), secondValue(v2) { }

    T getFirstValue() const {
        return firstValue;
    }

    U getSecondValue() const {
        return secondValue;
    }
};

template<typename T, typename U>
class LabeledPair : public Pair<T, U> {
private:
    std::string label;

public:
    LabeledPair(const T& v1, const U& v2, const std::string& l) : Pair<T, U>(v1, v2), label(l) { }

    std::string getLabel() const {
        return label;
    }
};

int main() {

    Pair<int, float> pair(1, 1.5);
    LabeledPair<int, float> labelPair(12, 12.6, "Une paire d'int et de float");

    std::cout << pair.getFirstValue() << " - " << pair.getSecondValue() << std::endl;
    std::cout << labelPair.getLabel() << " : " << labelPair.getFirstValue() << " - " << labelPair.getSecondValue() << std::endl;
    return 0;
}