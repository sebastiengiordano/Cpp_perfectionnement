#include <iostream>
#include <ostream>
#include <string>

class Ingredient {
public:
    std::string type;

    Ingredient(std::string t) { type = t; }
    friend std::ostream& operator<<(std::ostream& os, Ingredient i);
};

std::ostream& operator<<(std::ostream& os, Ingredient i) {
    os << i.type;
    return os;
}

class Tomate : public Ingredient {
public:
    Tomate() : Ingredient("tomate") {}
};

class Oignon : public Ingredient {
public:
    Oignon() : Ingredient("oignon") {}
};

class Beurre : public Ingredient {
public:
    Beurre() : Ingredient("beurre") {}
};

template<typename V>
class Snack {
protected: 
    V composition;

public:
    Snack() = default;
    Snack(V compo) : composition(compo) { }

    V getComposition() const { return composition; }
    void setComposition(V newCompo) { composition = newCompo; }

};

// ClassÃ© gÃ©nÃ©rique hÃ©ritant d'une autre classe gÃ©nÃ©rique
template<typename T, typename U, typename V>
class Sandwich : Snack<V> {
protected:
    T ingredient1;
    U ingredient2;
    int nbIngredient1;
    int nbIngredient2;

public:
    Sandwich() = default;
    Sandwich(T ing1, U ing2, V comp) : Snack<V>(comp) {
        ingredient1 = ing1;
        ingredient2 = ing2;
        nbIngredient1 = 1;
        nbIngredient2 = 1;

        // Snack<V>::setComposition(comp);
    }

    T getIngredient1() const { return ingredient1; }
    U getIngredient2() const { return ingredient2; }

    void display() const {
        std::cout << "Sandwich : " << nbIngredient1 << " " << ingredient1 << " et " << nbIngredient2 << " " << ingredient2 << std::endl;
    }

    Sandwich<T, U, V> operator+(Sandwich<T, U, V>& other) {
        Sandwich<T, U, V> plusGros(ingredient1, ingredient2, Snack<V>::getComposition());
        plusGros.nbIngredient1 = nbIngredient1 + other.nbIngredient1;
        plusGros.nbIngredient2 = nbIngredient2 + other.nbIngredient2;
        return plusGros;
    }

    Sandwich<T, U, V> operator+(Tomate tomate) {
        Sandwich<T, U, V> plusGros(ingredient1, ingredient2, Snack<V>::getComposition());
        plusGros.nbIngredient1++;
        return plusGros;
    }
};

// SpÃ©cialisation partielle
template<typename T, typename U>
class Sandwich<T, U, std::string> : Snack<std::string> {
protected:
    T ingredient1;
    U ingredient2;
    int nbIngredient1;
    int nbIngredient2;

public:
    Sandwich(T ing1, U ing2, std::string comp) : Snack<std::string>(comp) {
        ingredient1 = ing1;
        ingredient2 = ing2;
        nbIngredient1 = 1;
        nbIngredient2 = 1;
        // Snack<std::string>::setComposition(comp);
    }

    T getIngredient1() const { return ingredient1; }
    U getIngredient2() const { return ingredient2; }

    void display() const {
        std::cout << "SpÃ©cialisation partielle : " << Snack<std::string>::getComposition() << std::endl;
        std::cout << "Sandwich : " << ingredient1 << " et " << ingredient2 << std::endl;
    }

    Sandwich<T, U, std::string> operator+(Sandwich<T, U, std::string>& other) {
        Sandwich<T, U, std::string> plusGros(ingredient1, ingredient2, Snack<std::string>::getComposition());
        plusGros.nbIngredient1 = nbIngredient1 + other.nbIngredient1;
        plusGros.nbIngredient2 = nbIngredient2 + other.nbIngredient2;
        return plusGros;
    }
};

// SpÃ©cialisation totale
template<>
class Sandwich<int, int, std::string> : Snack<std::string> {
protected:
    int ingredient1;
    int ingredient2;
    int nbIngredient1;
    int nbIngredient2;

public:
    Sandwich() = default;
    Sandwich(int ing1, int ing2, std::string comp) : Snack<std::string>(comp) {
        ingredient1 = ing1;
        ingredient2 = ing2;
        nbIngredient1 = 1;
        nbIngredient2 = 1;
        // Snack<int>::setComposition(comp);
    }

    int getIngredient1() const { return ingredient1; }
    int getIngredient2() const { return ingredient2; }

    void display() const {
        std::cout << "SpÃ©cialisation totale : " << Snack<std::string>::getComposition() << std::endl;
        std::cout << "Sandwich : " << ingredient1 << " et " << ingredient2 << std::endl;
    }

    Sandwich<int, int, std::string> operator+(Sandwich<int, int, std::string>& other) {
        Sandwich<int, int, std::string> plusGros(ingredient1, ingredient2, Snack<std::string>::getComposition());
        plusGros.nbIngredient1 = nbIngredient1 + other.nbIngredient1;
        plusGros.nbIngredient2 = nbIngredient2 + other.nbIngredient2;
        return plusGros;
    }
};

int main() {
    Sandwich<std::string, std::string, char> tomateOignon("tomate", "oignon", 'B');
    Sandwich<std::string, std::string, char> tomateOignon2("tomate", "oignon", 'C');
    Sandwich<std::string, std::string, std::string> jambonBeurre("jambon", "beurre", "Le classique jambon-beurre !");
    Sandwich<int, int, std::string> specialeDuChef(3, 12, "Laissez-vous transporter par ce sandwich inoubliable !");

    Oignon oignon;
    Tomate tomate;

    // Sandwich<Oignon, Tomate, char> nouveauOignonTomate(oignon, tomate, 'B');
    
    tomateOignon.display();
    jambonBeurre.display();
    specialeDuChef.display();

    // nouveauOignonTomate.display();

    auto nouveauSandwich = tomateOignon + tomateOignon2;
    nouveauSandwich.display(); 

    nouveauSandwich = tomateOignon + tomate;
    nouveauSandwich.display(); 

    return 0;
}