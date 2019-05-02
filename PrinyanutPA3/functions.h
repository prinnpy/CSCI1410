/*Name: Prinn Prinyanut
 Class: CSCI 1410
 Description: PA3
 Status: Successfully compiled and run. Using Xcode as IDE.
 */

#ifndef functions_h
#define functions_h

//includes
#include "Dealer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


//option 1
void readFile(std::vector<Dealer> &dealer) {
    
    //create temp dealer and cars
    Dealer tempDealer;
    Vehicle tempVehicle;
    
    //vars for temp
    std::string dealerName, tempVin, tempMake, tempModel;
    int dealerNumber, numOfCars, tempYear;
    double tempPrice;
    Vehicle *vehiclePtr;
    //create and open file
    std::ifstream inFile;
    
    inFile.open("/Users/itzpr1nn/Desktop/PA3File.txt");
    
    //check for errors
    if (inFile.fail()) {
        std::cerr << "Error Opening File" << std::endl;
        exit(1);
        
    }//if
    
    //read in file loop
    while (inFile.good()) {
        
        //put in temp var for dealer
        getline(inFile, dealerName);
        inFile >> dealerNumber;
        inFile >> numOfCars;
        inFile.ignore();
        
        //set dealer info
        tempDealer.setName(dealerName);
        tempDealer.setNumber(dealerNumber);
        tempDealer.setNumOfCars(numOfCars);
        
        //new array for cars
        vehiclePtr = new Vehicle[numOfCars];
        
        //put in temp var for cars
        for (int i = 0; i < numOfCars; i++) {
            getline(inFile, tempVin);
            getline(inFile, tempMake);
            getline(inFile, tempModel);
            inFile >> tempYear;
            inFile >> tempPrice;
            inFile.ignore();
            
            //set cars info
            tempVehicle.setVIN(tempVin);
            tempVehicle.setMake(tempMake);
            tempVehicle.setModel(tempModel);
            tempVehicle.setYear(tempYear);
            tempVehicle.setPrice(tempPrice);
            
            //put it in the array
            vehiclePtr[i] = tempVehicle;
            
        }
        //set cars to dealer
        tempDealer.setVehicleArrayPtr(vehiclePtr);
        
        //add dealer back to the vector
        dealer.push_back(tempDealer);
        
    }//
    //close file
    inFile.close();
    //print out
    std::cout << "success!" << std::endl;
    
}

//option 2
void printDealer(std::vector<Dealer> dealer)
{
    //print out dealer info
    for (int i = 0; i < dealer.size(); i++)
    {
        std::cout << dealer[i];
    }
}


//option 3
void searchDealerDisplay(std::vector<Dealer> &dealer)
{
    //vars
    int dealerNum, dealerIndex = 0;
    bool found = false;
    Vehicle *vehicleArrayPtr;
    
    //asks for dealer number
    std::cout << "What is the dealer number?" << std::endl;
    std::cin >> dealerNum;
    std::cin.ignore();
    
    //search using dealer number and display cars
    for (int i = 0; i < dealer.size(); i++)
    {
        if (dealerNum == dealer[i].getNumber())
        {
            dealerIndex = i;
            found = true;
            
        }//if
        
    }//for
    
    if (!found)
    {
        std::cout << "Record not found\n";
    }
    //display cars and all of its info
    else {
        
        vehicleArrayPtr = dealer[dealerIndex].getVehicleArrayPtr();
        for (int i = 0; i < dealer[dealerIndex].getNumOfCars(); i++)
        {
            std::cout << vehicleArrayPtr[i];
        }
        
    }
}

//option 4
void searchDealerAdd(std::vector<Dealer> &dealer)
{
    //vars
    int dealerNum, dealerIndex = 0, tempYear;
    bool found = false;
    Vehicle tempVehicle, *vehicleArrayPtr;
    std::string tempVin, tempMake, tempModel;
    double tempPrice;
    Dealer tempDealer;
    
    //asks for dealer number
    std::cout << "What is the dealer number?" << std::endl;
    std::cin >> dealerNum;
    std::cin.ignore();
    
    //checks if the intput number matches with the data
    for (int i = 0; i < dealer.size(); i++)
    {
        if (dealerNum == dealer[i].getNumber())
        {
            dealerIndex = i;
            found = true;
            
        }//if
        
    }//for
    
    if (!found)
    {
        std::cout << "Record not found\n";
    }
    //ask for car info
    else {
        
        std::cout << "Enter vehicle vin:" << std::endl;
        getline(std::cin, tempVin);
        std::cout << "Enter vehicle make:" << std::endl;
        getline(std::cin, tempMake);
        std::cout << "Enter vehicle model:" << std::endl;
        getline(std::cin, tempModel);
        std::cout << "Enter vehicle year:" << std::endl;
        std::cin >> tempYear;
        std::cout << "Enter vehicle price:" << std::endl;
        std::cin >> tempPrice;
        std::cin.ignore();
        
        //put it in tempcar
        tempVehicle.setVIN(tempVin);
        tempVehicle.setMake(tempMake);
        tempVehicle.setModel(tempModel);
        tempVehicle.setYear(tempYear);
        tempVehicle.setPrice(tempPrice);
        
        //get new array and flag
        int setFlag = (dealer[dealerIndex].getNumOfCars() + 1);
        vehicleArrayPtr = new Vehicle[setFlag];
        
        //add car info to car
        for (int i = 0; i < dealer[dealerIndex].getNumOfCars(); i++)
        {
            vehicleArrayPtr[i] = dealer[dealerIndex].getVehicleArrayPtr()[i];
        }
        
        vehicleArrayPtr[setFlag - 1] = tempVehicle;
        
        //set cars to correct dealer
        dealer[dealerIndex].setVehicleArrayPtr(vehicleArrayPtr);
        
        //adding 1 to numberOfCars
        int newNumCars = (dealer[dealerIndex].getNumOfCars() + 1);
        dealer[dealerIndex].setNumOfCars(newNumCars);
        
        std::cout << "Record added!" << std::endl;
        
    }
    
}


//option 5
void sortCarByVin(std::vector<Dealer> &dealer)
{
    
    //vars
    int dealerNum, dealerIndex = 0;
    Vehicle *vehicleArrayPtr = nullptr;
    bool found = false;
    
    //asks for dealer number
    std::cout << "What is the dealer number?" << std::endl;
    std::cin >> dealerNum;
    std::cin.ignore();
    
    //checks for the correct dealer number
    for (int i = 0; i < dealer.size(); i++)
    {
        if (dealerNum == dealer[i].getNumber())
        {
            dealerIndex = i;
            found = true;
            
        }//if
        
    }//for
    if (!found)
    {
        std::cout << "Record not found\n";
    }
    else {
        
        //make new d array
        vehicleArrayPtr = new Vehicle[dealer[dealerIndex].getNumOfCars()];
        
        //setting all cars into the array
        for (int i = 0; i < dealer[dealerIndex].getNumOfCars(); i++)
        {
            vehicleArrayPtr[i] = dealer[dealerIndex].getVehicleArrayPtr()[i];
        }
        
        //sort data based on vin number
        for (int j = 0; j < dealer[dealerIndex].getNumOfCars(); j++)
        {
            for (int flag = 0; flag < j; flag++)
            {
                //sort by vin number
               if (vehicleArrayPtr[flag].getVIN() > vehicleArrayPtr[flag + 1].getVIN()) {

                   std::swap(vehicleArrayPtr[flag], vehicleArrayPtr[flag + 1]);

               }//if
            }//for

        }//for
        
    }//else
    
    //set everything back to the vector
    dealer[dealerIndex].setVehicleArrayPtr(vehicleArrayPtr);
    
}//func

//swap function
void swap(Vehicle &a, Vehicle &b)
{
    Vehicle temp = a;
    a = b;
    b = temp;
}

//option 6
void writeToFile()
{
    //create outfile
    std::ofstream outfile;
    
    //temp var
    Dealer tempDealer;
    Vehicle tempVehicle;
    
    //make temp vars
    std::string tempDName, tempVVIN, tempVMake, tempVModel;
    int tempDNumber, tempDNumOfCars, tempVYear;
    double tempVPrice;
    
    char moreDealer = 'y';
    
    //ask for dealer info
    while (moreDealer == 'y')
        
    {
        //open file
        outfile.open("/Users/itzpr1nn/Desktop/PA3File.txt", std::fstream::app);
        
        //ask for inputs
        std::cout << "Enter dealer name: " << std::endl;
        std::cin.ignore();
        getline(std::cin, tempDName);
        std::cout << "Enter dealer number: " << std::endl;
        std::cin >> tempDNumber;
        std::cout << "Enter number of cars: " << std::endl;
        std::cin >> tempDNumOfCars;
        
        //put into temp
        tempDealer.setName(tempDName);
        tempDealer.setNumber(tempDNumber);
        tempDealer.setNumOfCars(tempDNumOfCars);
        
        //write to file
        outfile << std::endl << tempDealer.getName() << std::endl;
        outfile << tempDealer.getNumber() << std::endl;
        outfile << tempDealer.getNumOfCars() << std::endl;
        
        //close file
        outfile.close();
        
        char moreCar = 'y';

        //ask for car info
        while (moreCar == 'y')
        {
            
            //open file
            outfile.open("/Users/itzpr1nn/Desktop/PA3File.txt", std::fstream::app);
            
            //ask for info
            std::cout << "Enter car vin: " << std::endl;
            std::cin.ignore();
            getline(std::cin, tempVVIN);
            std::cout << "Enter car make: " << std::endl;
            getline(std::cin, tempVMake);
            std::cout << "Enter car model: " << std::endl;
            getline(std::cin, tempVModel);
            std::cout << "Enter car year: " << std::endl;
            std::cin >> tempVYear;
            std::cout << "Enter car price: " << std::endl;
            std::cin >> tempVPrice;

            //put into temp
            tempVehicle.setVIN(tempVVIN);
            tempVehicle.setMake(tempVMake);
            tempVehicle.setModel(tempVModel);
            tempVehicle.setYear(tempVYear);
            tempVehicle.setPrice(tempVPrice);
            
            //print to file
            outfile << tempVehicle.getVIN() << std::endl;
            outfile << tempVehicle.getMake() << std::endl;
            outfile << tempVehicle.getModel() << std::endl;
            outfile << tempVehicle.getYear() << std::endl;
            outfile << tempVehicle.getPrice() << std::endl;
            
            //close file
            outfile.close();
            
            //ask if there is more car
            std::cout << "Want to add more car? (y or n)" << std::endl;
            std::cin >> moreCar;

            
        }//car loop
        
        //ask if there is more dealer
        std::cout << "Want to add more dealer? (y or n)" << std::endl;
        std::cin >> moreDealer;
        
    }//dealer loop
    
    
}
    


#endif /* functions_h */

