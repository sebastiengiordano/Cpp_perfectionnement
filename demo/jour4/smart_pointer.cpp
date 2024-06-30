#include <iostream>
#include <memory>

int main() {

    std::unique_ptr<std::string> uniquePtr = std::make_unique<std::string>("Hello World !");
    std::cout << *uniquePtr << std::endl;
    // Ne compile pas car il n'y a qu'un seul propriétaire de la ressource
    // std::unique_ptr<std::string> copyUniquePtr = uniquePtr;

    // Libération de la mémoire
    uniquePtr.reset();

    // Segfault => la mémoire a déjÃ  été libéré ici
    //    std::cout << *uniquePtr << std::endl;

    std::shared_ptr<float> sharePtr = std::make_shared<float>(4.21);
    std::shared_ptr<float> sharePtr2 = sharePtr;
    std::weak_ptr<float>  weakPtr = sharePtr;

    // Donne le nombre de références sur la ressource ciblée avec des sharePtr
    std::cout << "Nombre de propriétaires : " << sharePtr.use_count() << std::endl;

    {
        std::shared_ptr<float> sharePtr3 = weakPtr.lock();
        std::cout << "Nombre de propriétaires dans un sous bloc : " << sharePtr.use_count() << std::endl;
    }

    std::cout << "Nombre de propriétaires : " << sharePtr.use_count() << std::endl;

    std::cout << *sharePtr << std::endl;
    std::cout << *sharePtr2 << std::endl;
    // std::cout << *sharePtr3 << std::endl;

    *sharePtr2 = 42.42;

    std::cout << *sharePtr << std::endl;
    std::cout << *sharePtr2 << std::endl;
    // std::cout << *sharePtr3 << std::endl;

    return 0;
}