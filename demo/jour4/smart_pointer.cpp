#include <iostream>
#include <memory>

int main() {

    std::unique_ptr<std::string> uniquePtr = std::make_unique<std::string>("Hello World !");
    std::cout << *uniquePtr << std::endl;
    // Ne compile pas car il n'y a qu'un seul propriÃ©taire de la ressource
    // std::unique_ptr<std::string> copyUniquePtr = uniquePtr;

    // LibÃ©ration de la mÃ©moire
    uniquePtr.reset();

    // Segfault => la mÃ©moire a dÃ©jÃ  Ã©tÃ© libÃ©rÃ© ici
    //    std::cout << *uniquePtr << std::endl;

    std::shared_ptr<float> sharePtr = std::make_shared<float>(4.21);
    std::shared_ptr<float> sharePtr2 = sharePtr;
    std::weak_ptr<float>  weakPtr = sharePtr;

    // Donne le nombre de rÃ©fÃ©rences sur la ressource ciblÃ©e avec des sharePtr
    std::cout << "Nombre de propriÃ©taires : " << sharePtr.use_count() << std::endl;

    {
        std::shared_ptr<float> sharePtr3 = weakPtr.lock();
        std::cout << "Nombre de propriÃ©taires dans un sous bloc : " << sharePtr.use_count() << std::endl;
    }

    std::cout << "Nombre de propriÃ©taires : " << sharePtr.use_count() << std::endl;

    std::cout << *sharePtr << std::endl;
    std::cout << *sharePtr2 << std::endl;
    // std::cout << *sharePtr3 << std::endl;

    *sharePtr2 = 42.42;

    std::cout << *sharePtr << std::endl;
    std::cout << *sharePtr2 << std::endl;
    // std::cout << *sharePtr3 << std::endl;

    return 0;
}