#include "conversion.hpp"

using namespace std;

/* My Dog class */
void Dog::makeNoise()
{
    cout << "The dog barks" << endl;
}



/* My Cat class */
void Cat::makeNoise()
{
    cout << "The cat is meowing" << endl;
}


int main() {
    Dog myDog;
    Cat myCat;

    cout << "Test conversion : With Dog to Animal" << endl;
    Animal* myAnimal = dynamic_cast<Animal*>(&myDog);
    myAnimal->makeNoise();


    cout << endl;
    cout << "Test conversion : With Dog to Animal to Dog" << endl;
    Dog* aDog = dynamic_cast<Dog*>(myAnimal);
    aDog->makeNoise();


    cout << endl;
    cout << "Test conversion : With Cat to Animal" << endl;
    myAnimal = dynamic_cast<Animal*>(&myCat);
    myAnimal->makeNoise();


    cout << endl;
    cout << "Test conversion : With Cat to Animal to Cat" << endl;
    Cat* aCat = dynamic_cast<Cat*>(myAnimal);
    aCat->makeNoise();


    cout << endl;

    return 0;
}
