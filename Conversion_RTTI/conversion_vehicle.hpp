#include <iostream>
#include <vector>

using namespace std;

class Vehicle
{
protected:
    string type;

public:
    Vehicle(string myType);
    virtual ~Vehicle() = default;

    virtual void displayType () const {
        cout << "This vehicle has like type : " << type << endl;
    };
};


class Car: public Vehicle
{
public:
    Car(string myType);
    ~Car() = default;

    void displayType ();
};
