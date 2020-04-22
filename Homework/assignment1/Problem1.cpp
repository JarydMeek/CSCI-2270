//Jaryd Meek
//CSCI 2270
//Homework 1
//Problem 1

#include <iostream>
#include <fstream>

using namespace std;


//Function - Insert Into Sorted Array
//Takes the input value and inserts it in the correct place in the array (Array sorted in decending order)
//Returns the number of elements in the array.
int insertIntoSortedArray(float myArray[], int numEntries, float newValue) {
    int originalEntries = numEntries; //stored for check at end
    //Array is empty
    if (numEntries == 0) {
        myArray[0] = newValue;
        numEntries++;
    //Array has data, insert in the correct place
    } else {
        for (int i = 0; i < numEntries+1; i++) {
            if (myArray[i] < newValue) {
                //Moves all data after the position to insert back one spot
                for (int j = numEntries; j >= i; j--) {
                    myArray[j+1] = myArray[j];
                }
                //inserts the new value
                myArray[i] = newValue;
                numEntries++;
                break;
            }
        }
    }
    //Nothing has been added to the array, meaning the number goes on the end of the array.
    if (numEntries == originalEntries) {
        myArray[numEntries] = newValue;
        numEntries++;
    }
    //returns the number of items in the array
    return numEntries;
}

int main(int argc, char const *argv[]) {
    //checks for the correct number of arguments
    if (argc != 2) {
        cout << "Invalid Arguments" << endl;
    } else {
        //Storage Variables 
        string tempLine;
        float toSort;
        float myArray[100];
        int numEntries = 0;

        //Open the file
        ifstream inputFile;
        inputFile.open(argv[1]);

        //If the file could open successfully 
        if (inputFile.is_open()) {
            while(getline(inputFile,tempLine)){
                toSort = stof(tempLine);
                numEntries = insertIntoSortedArray(myArray, numEntries, toSort);

                //Outputs Array each time the code is run
                for (int i = 0; i < numEntries-1; i++) {
                    cout << myArray[i]<< ",";
                }
                cout << myArray[numEntries-1] << endl;
            }
            
        
        //File could not be opened successfully
        } else {
            cout << "Failed to open the file." << endl;
        }
        
    }
}
