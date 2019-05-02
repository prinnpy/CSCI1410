/*Name: Prinn Prinyanut
 Class: CSCI 1410
 Description: PA3
 Status: Successfully compiled and run. Using Xcode as IDE.
 */

//includes
#include "functions.h"
#include "Dealer.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//start main
int main(){
    
    //declare all vairables
    
    vector <Dealer> dealerVector;
    
    
    //welcome message
    cout << "Welcome to our Program" << endl;
    
    //init this for the do-while loop
    char done = 'n';
    
    //do-while loop
    do {
        
        //start menu
        cout << "\nPlease enter your option below." << endl;
        cout << "Enter 1 to Read Dealers and Cars from file" << endl;
        cout << "Enter 2 to Display Dealers" << endl;
        cout << "Enter 3 to Choose a Dealer Number, Display Cars" << endl;
        cout << "Enter 4 to Choose a Dealer Number, Add Car" << endl;
        cout << "Enter 5 to Choose a Dealer, Sort cars by VIN" << endl;
        cout << "Enter 6 to Write Dealers and Cars to a file" << endl;
        cout << "Enter 7 to Exit" << endl;
        int menu;
        cin >> menu;
        
        
        //start switch case to call functions menus
        switch (menu) {
                
            case 1:
                //call function Read Dealers and Cars from file
                readFile(dealerVector);
                break;
                
            case 2:
                //call function Display Dealers
                printDealer(dealerVector);
                break;
                
            case 3:
                //call function Choose a Dealer Number, Display Cars
                searchDealerDisplay(dealerVector);
                break;
                
            case 4:
                //call function Choose a Dealer Number, Add Car
                searchDealerAdd(dealerVector);
                break;
                
            case 5:
                //call function Choose a Dealer, Sort cars by VIN
                sortCarByVin(dealerVector);
                break;
                
            case 6:
                //call function Enter 6 to Write Dealers and Cars to a file
                writeToFile();
                break;
                
            case 7:
                //exit program
                done = 'y';
                return 0;
                break;
                
                //validation for the menu
            default:
                cout << "Invalid response. Please enter again" << endl; //make sure user enter the right input
                
        }//switch
        
    }//do
    
    while (done != 'y');
    
    return 0;
    
}//main
