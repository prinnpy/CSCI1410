/*Name: Prinn Prinyanut
 Class: CSCI 1410
 Description: PA3
 Status: Successfully compiled and run. Using Xcode as IDE.
 */

//includes
#include "Dealer.h"
#include <iostream>

//default dealer constructors
Dealer::Dealer()
{
    name = "";
    number = 0;
    numOfCars = 0;
    vehicleArrayPtr = nullptr;
}

//constructors that has paramaters for dealer
Dealer::Dealer(std::string _name, int _number, int _numOfCars, Vehicle *vehiclePtr)
{
    name = _name;
    number = _number;
    numOfCars = _numOfCars;
    vehicleArrayPtr = vehiclePtr;
    
    
}

//default car constructors
Vehicle::Vehicle()
{
    vin = "";
    make = "";
    model = "";
    year = 0;
    price = 0.0;
}

//constructors that has paramaters for cars
Vehicle::Vehicle(std::string _vin, std::string _make, std::string _model, int _year, double _price)
{
    vin = _vin;
    make = _make;
    model = _model;
    year = _year;
    price = _price;
}

//operater overload for dealer
std::ostream& operator << (std::ostream& out, Dealer tempDealer)
{
    out << "Dealer Name: " << tempDealer.getName() << std::endl;
    
    return out;
}

//operater overload for cars
std::ostream& operator << (std::ostream& out, Vehicle tempVehicle)
{
    out << "Vin: " << tempVehicle.getVIN() << std::endl;
    out << "Make: " << tempVehicle.getMake() << std::endl;
    out << "Model: " << tempVehicle.getModel() << std::endl;
    out << "Year: " << tempVehicle.getYear() << std::endl;
    out << "Price: $" << tempVehicle.getPrice() << std::endl << std::endl;
    
    return out;
}


