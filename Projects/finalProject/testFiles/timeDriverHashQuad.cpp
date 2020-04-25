#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include "../hashTableQuadratic.hpp"


using namespace std;

//Function - Takes string for file name and integer array for storage
//Reads the file, and splits the numbers by comma and saves them to the storage array
//Jaryd
bool readFile(string fileName, int storageArray[]) {
    ifstream iFileA(fileName); //open file
    string dataSetRaw; //create storage

    if (!iFileA.is_open()) {
        cout << fileName << " can't be read" << endl;
        return false;
    }

    getline(iFileA, dataSetRaw); //Turn the file stream into a string
    stringstream splitString(dataSetRaw); //Create stringStream of input
    string singleNumber; //String to store the individual numbers to.

    int counter = 0;
    while(getline(splitString, singleNumber, ',')) { //splits the string by comma
        storageArray[counter] = stoi(singleNumber); //add the current integer to the storage array
        counter++; //count the number of integers read
    }
    if (counter != 0) { //if there was something in the file, give happy message
        cout << endl << fileName << " has been read succesfully" << endl; 
        return true;
    } else { //if there was nothing in the file, give angry message
        cout << fileName << " can't be read" << endl;
        return false;
    }
    iFileA.close(); //Close the file like a good person.
}

int main(int argc, char const *argv[]) {

    //Storage Arrays
    int dataSet[400000];
    double insertTime[400];
    double searchTime[400];


    readFile("../dataSets/dataSetA.csv", dataSet);



    //**PUT CONSTRUCTOR HERE**//
    
    HashTableQuadratic h(40009);


    int position = 0;
    while (position <400){

        /*INSERT TIMER*/
        double insertTemp[100];
        double insertSum = 0;
        for (int i = position*100; i < (position+1)*100; i++) {
            std::chrono::high_resolution_clock::time_point startInsert = std::chrono::high_resolution_clock::now(); //start timer
            
            //**PUT INSERT FUNCTION HERE**
            h.insertItem(dataSet[i]);
            
            std::chrono::high_resolution_clock::time_point endInsert = std::chrono::high_resolution_clock::now(); //stop timer
            std::chrono::duration<double, std::milli> timeTakenInsert = endInsert - startInsert;//Timery Maths stuff
            insertTemp[i%100] = timeTakenInsert.count();
            insertSum = insertSum + timeTakenInsert.count();
        }
        insertTime[position] = insertSum/100;

        //CONFIRMED GOOD
        /* SEARCH TIMER */
        double searchTemp[100];
        double searchSum = 0;
        int randIndex = 0;
        for (int i = 0; i < 100; i++) {
            randIndex = rand()%((position+1)*100);
            int toSearch = dataSet[randIndex];


            std::chrono::high_resolution_clock::time_point startSearch = std::chrono::high_resolution_clock::now(); //start timer
            //**PUT SEARCH FUNCTION HERE**//
            h.searchItem(toSearch);
            
            std::chrono::high_resolution_clock::time_point endSearch = std::chrono::high_resolution_clock::now(); //stop timer
            std::chrono::duration<double, std::milli> timeTakenSearch = endSearch - startSearch;//Timery Maths stuff
            searchTemp[i] = timeTakenSearch.count();
            searchSum = searchSum + timeTakenSearch.count();
        }
        searchTime[position] = searchSum/100;

        //Increment for Loop
        position++;
    }

    /*WRITE TO FILE*/
    ofstream insertOutput;
    insertOutput.open("insertResults.csv");
    ofstream searchOutput;
    searchOutput.open("searchResults.csv");
    for (int i = 0; i < 400; i++) {
        insertOutput << insertTime[i] << ",";
        searchOutput << searchTime[i] << ",";
    }
    insertOutput.close();
    searchOutput.close();
    cout << "\nInsertion results saved to insertResults.csv" << endl;
    cout << "Search results saved to searchResults.csv" << endl << endl;
}
