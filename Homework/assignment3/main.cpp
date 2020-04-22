/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
#include <fstream>

void displayMenu();  // declaration for main's helper-function

int main(int argc, char* argv[])
{
    CountryNetwork CountryNet;
    bool repeat = true;
    int selection;
    while (repeat == true) {
        displayMenu();
        selection = 0;
        cin >> selection;
        cin.ignore();
        switch (selection){
            case 1: {
                CountryNet.loadDefaultSetup();
                CountryNet.printPath();
                break;
            } case 2: {
                CountryNet.printPath();
                break;
            } case 3: {
                cout << "Enter name of the country to receive the message:" << endl;
                string countryName;
                getline(cin, countryName);
                cout << "Enter the message to send:\n" << endl;
                string message;
                getline(cin,message);
                CountryNet.transmitMsg(countryName,message);
                break;
            } case 4: {
                cout << "Enter a new country name:" << endl;
                string newCountry;
                getline(cin,newCountry);
                bool repeatCase4 = true;
                cout << "Enter the previous country name (or First):" << endl;
                while (repeatCase4 == true) {
                    string prevCountry;
                    getline(cin,prevCountry);
                    
                    if (prevCountry == "First") {
                        CountryNet.insertCountry(nullptr,newCountry);
                        repeatCase4 = false;
                        CountryNet.printPath();
                    } else if (CountryNet.searchNetwork(prevCountry) == nullptr) {
                        cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                    } else {
                        CountryNet.insertCountry(CountryNet.searchNetwork(prevCountry), newCountry);
                        repeatCase4 = false;
                        CountryNet.printPath();
                    }
                }
                break;
            } case 5: {
                cout << "Quitting...\nGoodbye!" << endl;
                repeat = false;
                break;
            }
        }
    }
    return 0;
}


/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
