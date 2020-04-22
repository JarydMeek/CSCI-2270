//Jaryd Meek
//CSCI 2270
//Homework 1
//Problem 2

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Park {
    string parkname;
    string state;
    int area;
};

//Function - Adds a park to the array of structs
//Creates a temporary park, adds all the given information to that park, then adds that park to the array of parks.
void addPark(Park parks[], string parkname, string state, int area, int length) {
    Park parkToStore;
    parkToStore.parkname = parkname;
    parkToStore.state = state;
    parkToStore.area = area;
    //adds the temporary park to the array
    parks[length] = parkToStore;
}
    
void printList(const Park parks[], int length) {
    for (int i = 0; i < length; i++) {
        cout << parks[i].parkname <<" [" << parks[i].state << "] area: "<< parks[i].area << endl;
    }
}

int main(int argc, char const *argv[]) {
    if (argc != 5) {
        cout << "Invalid Arguments" << endl;
    } else {
        //Store all the Arguments to variables for easier access
        string inFile = argv[1];
        string outFile = argv[2];
        int lowerBound = stoi(argv[3]);
        int upperBound = stoi(argv[4]);

        //Open the file
        ifstream inputFile;
        inputFile.open(inFile);

        //Temporary Variables
        string tempLine;
        string tempName;
        string tempState;
        string tempArea;
        int tempAreaInt;

        //Storage Variables
        Park parks[100];
        int numStored = 0;

        if (inputFile.is_open()) {
            while(getline(inputFile,tempLine)){
                stringstream s(tempLine);
                getline(s,tempName,',');
                getline(s,tempState,',');
                getline(s,tempArea,'\n');
                tempAreaInt = stoi(tempArea);

                //Add the park to the array
                addPark(parks, tempName, tempState, tempAreaInt, numStored);
                numStored++;
            }
        //Print the array
        printList(parks, numStored);

        //Open output file
        ofstream outputFile;
        outputFile.open(outFile);

        //output to file
        for (int i = 0; i < numStored; i++) {
            if (parks[i].area >= lowerBound && parks[i].area <= upperBound) {
                outputFile << parks[i].parkname << "," << parks[i].state << "," << parks[i].area << endl;
            }
        }
        


        } else {
            cout << "File couldn't be opened" << endl;
        }
    }
}