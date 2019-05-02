/*Name: Prinn Prinyanut
 Class: CSCI 1410
 Description: PA3
 Status: Successfully compiled and run. Using Xcode as IDE.
 */

#ifndef DEALER_H
#define DEALER_H
#include <iostream>
#include <string>

class Vehicle {
    
    //private vairables
private:
    std::string vin;
    std::string make;
    std::string model;
    int year;
    double price;
    
    
    //public functions
public:
    
    //constructors
    Vehicle();
    Vehicle(std::string _vin, std::string _make, std::string _model, int _year, double _price);
    
    //all set functions
    void setVIN(std::string _vin) {
        vin = _vin;
    }
    void setMake(std::string _make) {
        make = _make;
    }
    void setModel(std::string _model) {
        model = _model;
    }
    void setYear(int _year) {
        year = _year;
    }
    void setPrice(double _price) {
        price = _price;
    }
    
    //all get functions
    std::string getVIN() const {
        return vin;
    }
    std::string getMake() const {
        return make;
    }
    std::string getModel() const {
        return model;
    }
    int getYear() const {
        return year;
    }
    double getPrice() const {
        return price;
    }

    friend std::ostream& operator << (std::ostream& out, Vehicle _Vehicle);
    
};

class Dealer {
    
    //private vairables
private:
    std::string name;
    int number, numOfCars;
    Vehicle *vehicleArrayPtr;
    
    //public functions
public:
    
    //constructors
    Dealer();
    Dealer(std::string _name, int _number, int _numOfCars, Vehicle *vehiclePtr);
    
    //all set functions
    void setName(std::string _name) {
        name = _name;
    }
    void setNumber(int _number) {
        number = _number;
    }
    void setNumOfCars(int _numOfCars){
        numOfCars = _numOfCars;
    }
    void setVehicleArrayPtr(Vehicle *tempvehicleArrayPtr) {
        vehicleArrayPtr = tempvehicleArrayPtr;
    }
    
    //all get functions
    std::string getName() const {
        return name;
    }
    int getNumber() const {
        return number;
    }
    
    int getNumOfCars() const {
        return numOfCars;
    }
    
    Vehicle* getVehicleArrayPtr() const {
        return vehicleArrayPtr;
    }
    
    friend std::ostream& operator << (std::ostream& out, Dealer _Dealer);
    
    
};


#endif /* dealer_h */

