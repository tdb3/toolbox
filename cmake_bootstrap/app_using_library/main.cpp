#include<iostream>
#include "Car.h"

int main(int argc, char *argv[]) {
    std::cout << "Creating a Car" << std::endl;
    
    Car car1("Toyota", "Camry");
    std::cout << "Manufacturer: " << car1.getManufacturerName() << std::endl;
    std::cout << "Model: " << car1.getModelName() << std::endl;

    return 0;
}
