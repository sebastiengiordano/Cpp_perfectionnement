#include "conversion_vehicle.hpp"

using namespace std;

Vehicle::Vehicle(string myType): type(myType) {};


void Car::displayType() {
    cout << "This car has like type : " << type << endl;
}

Car::Car(string myType) : Vehicle(myType) {};


int main() {
    Car anElectricCar("Electric");
    Car anThermalCar("Thermal");

    cout << "Test reinterpret_cast : anElectricCar to Vehicle" << endl;
    Vehicle* vehicle = reinterpret_cast<Vehicle*> (&anElectricCar);
    vehicle->displayType();

    cout << endl;
    cout << "Test reinterpret_cast : Vehicle to Car" << endl;
    Car* anotherElectricCar = reinterpret_cast<Car*> (&vehicle);
    anotherElectricCar->displayType();

    cout << endl;
    cout << "Test dynamic_cast : Car to Vehicle" << endl;
    vehicle = dynamic_cast<Vehicle*> (anotherElectricCar);
    vehicle->displayType();

    cout << endl;

    delete vehicle;
    delete anotherElectricCar;

    return 0;
}
