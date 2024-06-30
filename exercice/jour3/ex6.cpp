#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>

class Product {
private:
    int id;
    std::string name;
    float price;
    int quantity;

public:
    Product(int i, std::string n, float p, int qty) : id(i), name(n), price(p), quantity(qty) { }

    int getId() const { return id; }
    std::string getName() const { return name; }
    float getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    void setQuantity(int newQuantity) {
        if (newQuantity > 0) {
            quantity = newQuantity;
        }
    }
    void display() const {
        std::cout << "Id : " << id << " - nom : " << name << std::endl;
    }
};

class Catalog {
private:
    std::list<Product> listProducts;

public:
    void addProduct(const Product& product) {
        listProducts.push_back(product);
    }

    void deleteProductById(int id) {
        listProducts.remove_if([id](const Product& p) {
            return p.getId() == id;
        });
    }

    void displayListProduct() const {
        for (auto& product: listProducts) {
            std::cout << "Id : " << product.getId() << ", nom : " << product.getName() << ", prix : " << product.getPrice() << ", quantité : " << product.getQuantity() << std::endl;
        }
    }

    Product *searchByName(const std::string& name) {
        // for (auto& product: listProducts) {
        //     if (product.getName() == name) {
        //         return &product;
        //     }
        // }
        auto it = find_if(listProducts.begin(), listProducts.end(), [name](const Product& p) {
            return p.getName() == name;
        });
        if (it != listProducts.end()) {
            return &*it;
        }
        return nullptr;
    }

    void displayProductById(int id) const {
        auto it = find_if(listProducts.begin(), listProducts.end(), [id](const Product& p) {
            return p.getId() == id;
        });
        if (it != listProducts.end()) {
            const Product& product = *it;
            std::cout << "Id : " << product.getId() << ", nom : " << product.getName() << ", prix : " << product.getPrice() << ", quantité : " << product.getQuantity() << std::endl;
        } else {
            std::cout << "Aucun produit trouvé !" << std::endl;
        }
    }

    void updateQuantity(int id, int newQuantity) {
        auto it = find_if(listProducts.begin(), listProducts.end(), [id](const Product& p) {
            return p.getId() == id;
        });
        if (it != listProducts.end()) {
            it->setQuantity(newQuantity);
        }
    }

    void sortByName() {
        listProducts.sort([](const Product& p1, const Product& p2) {
            return p1.getName() < p2.getName();
        });
    }

    void sortByPrice() {
        listProducts.sort([](const Product& p1, const Product& p2) {
            return p1.getPrice() < p2.getPrice();
        });
    }

    std::list<Product> getListProduct() const {
        return listProducts;
    }
};

class LogProduct {
public:
    void saveProduct(const Product& product) {
        try {
            std::ofstream productFile(product.getName() + ".txt");

            productFile << "Produit : " << product.getId() << std::endl;
            productFile << "Nom : " << product.getName() << std::endl;
            productFile << "Prix : " << product.getPrice() << std::endl;
            productFile << "Quantite : " << product.getQuantity() << std::endl;
            productFile.close();
        } catch (std::exception e) {
            std::cerr << "Erreur : impossible de sauvegarder le produit ! " << e.what() << std::endl;
        }
    }

    void saveCatalog(const Catalog& catalog) {
        try {
            std::ofstream catalogFile("Catalogue.txt");
            catalogFile << "   ###   CATALOGUE   ###   " << std::endl;
            
            for (const auto& product : catalog.getListProduct()) {
                catalogFile << "Produit : " << product.getId() << std::endl;
                catalogFile << "Nom : " << product.getName() << std::endl;
                catalogFile << "Prix : " << product.getPrice() << std::endl;
                catalogFile << "Quantite : " << product.getQuantity() << std::endl;
                catalogFile << std::endl;
            }
            catalogFile.close();
            
        } catch (std::exception e) {
            std::cerr << "Erreur : impossible de sauvegarder le produit ! " << e.what() << std::endl;
        }
    }
};

int main() {
    Product banane(1, "banane", 2, 10);
    Product chocolat(2, "chocolat", 5, 20);
    Product lait(3, "lait", 10, 5);
    Product tomate(4, "tomate", 1.5, 300);
    Catalog catalog;
    LogProduct logger;

    catalog.addProduct(banane);
    catalog.addProduct(chocolat);
    catalog.addProduct(lait);
    catalog.addProduct(tomate);
    catalog.displayListProduct();

    std::cout << "###  Suppression un produit avec l'id 1 : " << std::endl;
    catalog.deleteProductById(1);
    catalog.displayListProduct();
    
    std::cout << "###  Affichage du produit ayant l'id 2 : " << std::endl;
    catalog.displayProductById(2);

    std::cout << "### Récupération des tomates : " << std::endl;
    Product *p = catalog.searchByName("machin");
    if (p != nullptr)
        p->display();
    else
        std::cout << "Produit introuvable !" << std::endl;

    std::cout << "###  Modification de la quantité du produit ayant l'id 3 : " << std::endl;
    catalog.updateQuantity(3, 8);
    catalog.displayProductById(3);

    std::cout << "###  Tri par prix : " << std::endl;
    catalog.sortByPrice();
    catalog.displayListProduct();
    std::cout << "###  Tri par nom : " << std::endl;
    catalog.sortByName();
    catalog.displayListProduct();

    logger.saveProduct(tomate);
    logger.saveCatalog(catalog);

    return 0;
}