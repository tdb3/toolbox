#include "Car.h"

Car::Car(std::string manufacturerName, std::string modelName) {
    this->manufacturerName = manufacturerName;
    this->modelName = modelName;
}

std::string Car::getModelName() {
    return modelName;
}

std::string Car::getManufacturerName() {
    return manufacturerName;
}
