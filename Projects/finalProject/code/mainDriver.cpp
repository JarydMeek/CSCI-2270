//CSCI 2270 - Final Project
//Collin Graham and Jaryd Meek
//TAs - Saumya Sinha and Himanshu Gupta (respectively)


//Include header files for all data structures and variants
#include "LinkedList.hpp"
#include "BST.hpp"
#include "hashTableChaining.hpp"
#include "hashTableLinear.hpp"
#include "hashTableQuadratic.hpp"

//Include necessary libraries
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

//Helper Function - Takes string for file name and integer array for storage
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

//Timer Function - Completes the timing operation for linked lists
//runs insert 100x, then search 100x, averages those values and saves to array.
//Jaryd
void linkedListTest(int dataSet[], double insertTime[], double searchTime[]) {
    //**PUT CONSTRUCTOR HERE**//
    LinkedList L;

    int position = 0;
    while (position <400){

        /*INSERT TIMER*/
        double insertTemp[100];
        double insertSum = 0;
        for (int i = position*100; i < (position+1)*100; i++) {
            std::chrono::high_resolution_clock::time_point startInsert = std::chrono::high_resolution_clock::now(); //start timer
            
            //**PUT INSERT FUNCTION HERE**
            L.insert(dataSet[i]);
            
            std::chrono::high_resolution_clock::time_point endInsert = std::chrono::high_resolution_clock::now(); //stop timer
            std::chrono::duration<double, std::milli> timeTakenInsert = endInsert - startInsert;//Timery Maths stuff
            insertTemp[i%100] = timeTakenInsert.count();
            insertSum = insertSum + timeTakenInsert.count();
        }
        insertTime[position] = insertSum/100;


        /* SEARCH TIMER */
        double searchTemp[100];
        double searchSum = 0;
        int randIndex = 0;
        for (int i = 0; i < 100; i++) {
            randIndex = rand()%((position+1)*100);
            int toSearch = dataSet[randIndex];


            std::chrono::high_resolution_clock::time_point startSearch = std::chrono::high_resolution_clock::now(); //start timer
            //**PUT SEARCH FUNCTION HERE**//
            L.search(toSearch);
            
            std::chrono::high_resolution_clock::time_point endSearch = std::chrono::high_resolution_clock::now(); //stop timer
            std::chrono::duration<double, std::milli> timeTakenSearch = endSearch - startSearch;//Timery Maths stuff
            searchTemp[i] = timeTakenSearch.count();
            searchSum = searchSum + timeTakenSearch.count();
        }
        searchTime[position] = searchSum/100;


        //Increment for Loop
        position++;
    }
}

//Timer Function - Completes the timing operation for binary search trees
//runs insert 100x, then search 100x, averages those values and saves to array.
//Jaryd
void binarySearchTreeTest(int dataSet[], double insertTime[], double searchTime[]) {
    BST tree;


    int position = 0;
    while (position <400){

        /*INSERT TIMER*/
        double insertTemp[100];
        double insertSum = 0;
        for (int i = position*100; i < (position+1)*100; i++) {
            std::chrono::high_resolution_clock::time_point startInsert = std::chrono::high_resolution_clock::now(); //start timer
            
            //**PUT INSERT FUNCTION HERE**
            tree.insert(dataSet[i]);
            
            std::chrono::high_resolution_clock::time_point endInsert = std::chrono::high_resolution_clock::now(); //stop timer
            std::chrono::duration<double, std::milli> timeTakenInsert = endInsert - startInsert;//Timery Maths stuff
            insertTemp[i%100] = timeTakenInsert.count();
            insertSum = insertSum + timeTakenInsert.count();
        }
        insertTime[position] = insertSum/100;

        /* SEARCH TIMER */
        double searchTemp[100];
        double searchSum = 0;
        int randIndex = 0;
        for (int i = 0; i < 100; i++) {
            randIndex = rand()%((position+1)*100);
            int toSearch = dataSet[randIndex];


            std::chrono::high_resolution_clock::time_point startSearch = std::chrono::high_resolution_clock::now(); //start timer
            //**PUT SEARCH FUNCTION HERE**//
            tree.search(toSearch);
            
            std::chrono::high_resolution_clock::time_point endSearch = std::chrono::high_resolution_clock::now(); //stop timer
            std::chrono::duration<double, std::milli> timeTakenSearch = endSearch - startSearch;//Timery Maths stuff
            searchTemp[i] = timeTakenSearch.count();
            searchSum = searchSum + timeTakenSearch.count();
        }
        searchTime[position] = searchSum/100;

        //Increment for Loop
        position++;
    }
}

//Timer Function - Completes the timing operation for hash tables with chaining collision resolution.
//runs insert 100x, then search 100x, averages those values and saves to array.
//Jaryd
void hashTableChaining(int dataSet[], double insertTime[], double searchTime[], int collisionTrackerInsert[], int collisionTrackerSearch[]) {
    HashTableChain hashTable(40009);


    int position = 0;
    while (position <400){

        /*INSERT TIMER*/
        double insertTemp[100];
        double insertSum = 0;
        for (int i = position*100; i < (position+1)*100; i++) {
            std::chrono::high_resolution_clock::time_point startInsert = std::chrono::high_resolution_clock::now(); //start timer
            
            //**PUT INSERT FUNCTION HERE**
            hashTable.insertItem(dataSet[i]);
            
            std::chrono::high_resolution_clock::time_point endInsert = std::chrono::high_resolution_clock::now(); //stop timer
            std::chrono::duration<double, std::milli> timeTakenInsert = endInsert - startInsert;//Timery Maths stuff
            insertTemp[i%100] = timeTakenInsert.count();
            insertSum = insertSum + timeTakenInsert.count();
        }
        insertTime[position] = insertSum/100;

        /* SEARCH TIMER */
        double searchTemp[100];
        double searchSum = 0;
        int randIndex = 0;
        for (int i = 0; i < 100; i++) {
            randIndex = rand()%((position+1)*100);
            int toSearch = dataSet[randIndex];


            std::chrono::high_resolution_clock::time_point startSearch = std::chrono::high_resolution_clock::now(); //start timer
            //**PUT SEARCH FUNCTION HERE**//
            hashTable.searchItem(toSearch);
            
            std::chrono::high_resolution_clock::time_point endSearch = std::chrono::high_resolution_clock::now(); //stop timer
            std::chrono::duration<double, std::milli> timeTakenSearch = endSearch - startSearch;//Timery Maths stuff
            searchTemp[i] = timeTakenSearch.count();
            searchSum = searchSum + timeTakenSearch.count();
        }
        searchTime[position] = searchSum/100;


        //Tracks the number of collisions per 100 insertions
        if (position > 0){
            collisionTrackerInsert[position] = (hashTable.getNumOfCollisionInsert() - collisionTrackerInsert[position-1]);
            collisionTrackerSearch[position] = (hashTable.getNumOfCollisionSearch() - collisionTrackerSearch[position-1]);
        }

        //Increment for Loop
        position++;
    }
}

//Timer Function - Completes the timing operation for hash tables with linear probing collision resolution
//runs insert 100x, then search 100x, averages those values and saves to array.
//Jaryd
void hashTableLinear(int dataSet[], double insertTime[], double searchTime[], int collisionTrackerInsert[], int collisionTrackerSearch[]) {
    HashTableLinear hashTable(40009);
    
    int position = 0;
    while (position <400){

        /*INSERT TIMER*/
        double insertTemp[100];
        double insertSum = 0;
        for (int i = position*100; i < (position+1)*100; i++) {
            std::chrono::high_resolution_clock::time_point startInsert = std::chrono::high_resolution_clock::now(); //start timer
            
            //**PUT INSERT FUNCTION HERE**
            hashTable.insertItem(dataSet[i]);
            
            std::chrono::high_resolution_clock::time_point endInsert = std::chrono::high_resolution_clock::now(); //stop timer
            std::chrono::duration<double, std::milli> timeTakenInsert = endInsert - startInsert;//Timery Maths stuff
            insertTemp[i%100] = timeTakenInsert.count();
            insertSum = insertSum + timeTakenInsert.count();
        }
        insertTime[position] = insertSum/100;

        /* SEARCH TIMER */
        double searchTemp[100];
        double searchSum = 0;
        int randIndex = 0;
        for (int i = 0; i < 100; i++) {
            randIndex = rand()%((position+1)*100);
            int toSearch = dataSet[randIndex];


            std::chrono::high_resolution_clock::time_point startSearch = std::chrono::high_resolution_clock::now(); //start timer
            //**PUT SEARCH FUNCTION HERE**//
            hashTable.searchItem(toSearch);
            
            std::chrono::high_resolution_clock::time_point endSearch = std::chrono::high_resolution_clock::now(); //stop timer
            std::chrono::duration<double, std::milli> timeTakenSearch = endSearch - startSearch;//Timery Maths stuff
            searchTemp[i] = timeTakenSearch.count();
            searchSum = searchSum + timeTakenSearch.count();
        }
        searchTime[position] = searchSum/100;

        //Tracks the number of collisions per 100 insertions
        if (position > 0){
            collisionTrackerInsert[position] = (hashTable.getNumOfCollisionInsert() - collisionTrackerInsert[position-1]);
            collisionTrackerSearch[position] = (hashTable.getNumOfCollisionSearch() - collisionTrackerSearch[position-1]);
        }

        //Increment for Loop
        position++;
    }

}

//Timer Function - Completes the timing operation for hash tables with quadratic probing collision resolution
//runs insert 100x, then search 100x, averages those values and saves to array.
//Jaryd
void hashTableQuadratic(int dataSet[], double insertTime[], double searchTime[], int collisionTrackerInsert[], int collisionTrackerSearch[]) {
    HashTableQuadratic hashTable(40009);
    
    int position = 0;
    while (position <400){

        /*INSERT TIMER*/
        double insertTemp[100];
        double insertSum = 0;
        for (int i = position*100; i < (position+1)*100; i++) {
            std::chrono::high_resolution_clock::time_point startInsert = std::chrono::high_resolution_clock::now(); //start timer
            
            //**PUT INSERT FUNCTION HERE**
            hashTable.insertItem(dataSet[i]);
            
            std::chrono::high_resolution_clock::time_point endInsert = std::chrono::high_resolution_clock::now(); //stop timer
            std::chrono::duration<double, std::milli> timeTakenInsert = endInsert - startInsert;//Timery Maths stuff
            insertTemp[i%100] = timeTakenInsert.count();
            insertSum = insertSum + timeTakenInsert.count();
        }
        insertTime[position] = insertSum/100;

        /* SEARCH TIMER */
        double searchTemp[100];
        double searchSum = 0;
        int randIndex = 0;
        for (int i = 0; i < 100; i++) {
            randIndex = rand()%((position+1)*100);
            int toSearch = dataSet[randIndex];


            std::chrono::high_resolution_clock::time_point startSearch = std::chrono::high_resolution_clock::now(); //start timer
            //**PUT SEARCH FUNCTION HERE**//
            hashTable.searchItem(toSearch);
            
            std::chrono::high_resolution_clock::time_point endSearch = std::chrono::high_resolution_clock::now(); //stop timer
            std::chrono::duration<double, std::milli> timeTakenSearch = endSearch - startSearch;//Timery Maths stuff
            searchTemp[i] = timeTakenSearch.count();
            searchSum = searchSum + timeTakenSearch.count();
        }
        searchTime[position] = searchSum/100;

        //Tracks the number of collisions per 100 insertions
        if (position > 0){
            collisionTrackerInsert[position] = (hashTable.getNumOfCollisionInsert() - collisionTrackerInsert[position-1]);
            collisionTrackerSearch[position] = (hashTable.getNumOfCollisionSearch() - collisionTrackerSearch[position-1]);
        }

        //Increment for Loop
        position++;
    }
}

//Main function
//Handles menu system and calling the above functions, as well as file output.
//Jaryd
int main() {
    //Initialize storage arrays (sizes given in writup)
    int dataSet[400000];
    double insertTime[400];
    double searchTime[400];
    int collisionTrackerInsert[400];
    int collisionTrackerSearch[400];

    //While loop to allow the user to run other tests
    bool repeat = true;
    while (repeat){
        //Welcome the user and prompt for selection of data set. Save selection
        cout << "Hello! Which dataset would you like to test with?" << endl;
        cout << "1 - Data Set A (Given)\n2 - Data Set B (given)\n3 - Custom Data Set" << endl;
        cout << "Make a selection - ";
        int dataSetSelection;
        cin >> dataSetSelection;

        //String to store the data set run (for output file naming)
        string fileNameOutput = "";

        //load correct data set based on selection
        switch(dataSetSelection) {
            case 1 : readFile("dataSets/dataSetA.csv", dataSet);
                    fileNameOutput = "dataSetA-"; //for output file naming
                    break;
            case 2 : readFile("dataSets/dataSetB.csv", dataSet);
                    fileNameOutput = "dataSetB-";//for output file naming
                    break;
            case 3 : cout << "Please enter the filename you would like to load!" << endl;
                    string customDataSet;
                    cin.ignore();
                    getline(cin, customDataSet);
                    if(!readFile(customDataSet, dataSet)){
                        return -1;
                    }
                    fileNameOutput = "customDataSet-";//for output file naming
                    break;
        }

        //Now Prompt the user to pick a data structure to run.
        cout << "Now that the data set has been loaded successfully, which data structure would you like to test?" << endl;
        cout << "1 - Linked Lists\n2 - Binary Search Tree\n3 - Hash Table - Chaining\n4 - Hash Table - Linear Probing\n5 - Hash Table - Quadratic Probing" << endl;
        cout << "Make a selection - ";
        int dataStructureSelection;
        cin >> dataStructureSelection;
        cout << "Running selected program." << endl;

        //Bool to track if we are running a hash table to allow us to output Collisions
        bool runHashTable = false;

        //Run the test for the selected data structure
        switch(dataStructureSelection) {
            case 1 : linkedListTest(dataSet, insertTime, searchTime);
                    fileNameOutput = fileNameOutput + "linkedList-";//for output file naming
                    break;
            case 2 : binarySearchTreeTest(dataSet, insertTime, searchTime);
                    fileNameOutput = fileNameOutput + "binarySearchTree-";//for output file naming
                    break;
            case 3 : hashTableChaining(dataSet, insertTime, searchTime, collisionTrackerInsert, collisionTrackerSearch);
                    runHashTable = true;
                    fileNameOutput = fileNameOutput + "hashTableChaining-";//for output file naming
                    break;
            case 4 : hashTableLinear(dataSet, insertTime, searchTime, collisionTrackerInsert, collisionTrackerSearch);
                    runHashTable = true;
                    fileNameOutput = fileNameOutput + "hashTableLinear-";//for output file naming
                    break;
            case 5 : hashTableQuadratic(dataSet, insertTime, searchTime, collisionTrackerInsert, collisionTrackerSearch);
                    runHashTable = true;
                    fileNameOutput = fileNameOutput + "hashTableQuadratic-";//for output file naming
                    break;
        }


        //write the results to output files
        ofstream insertOutput;
        insertOutput.open(fileNameOutput+"insertResults.csv");
        ofstream searchOutput;
        searchOutput.open(fileNameOutput+"searchResults.csv");
        for (int i = 0; i < 400; i++) {
            insertOutput << insertTime[i] << ",";
            searchOutput << searchTime[i] << ",";
        }
        insertOutput.close();
        searchOutput.close();
        cout << "\nInsertion results saved to "<< fileNameOutput << "insertResults.csv" << endl;
        cout << "Search results saved to "<< fileNameOutput << "searchResults.csv" << endl;

        //Handles file output of collision tracker (IF APPLICABLE)
        if(runHashTable) {
            ofstream collisionOutputInsert;
            ofstream collisionOutputSearch;
            collisionOutputInsert.open(fileNameOutput+"collisionResultsInsert.csv");
            collisionOutputSearch.open(fileNameOutput+"collisionResultsSearch.csv");
            for (int i = 0; i < 400; i++) {
                collisionOutputInsert << collisionTrackerInsert[i] << ",";
                collisionOutputSearch << collisionTrackerSearch[i] << ",";
            }
            collisionOutputInsert.close();
            collisionOutputSearch.close();
            cout << "Collision on Insert results saved to "<< fileNameOutput << "collisionResultsInsert.csv" << endl;
            cout << "Collision on Search results saved to "<< fileNameOutput << "collisionResultsSearch.csv" << endl;
        }
        
        cout << endl;
    
        //Prompt the user to see if they would like to re-run any tests
        cout << "Would you like to run another test? Enter 'Y' for yes, or 'N' for no\nMake a selection - ";
        char restartSelection;
        cin >> restartSelection;
        switch(restartSelection) {
            case 'y' : repeat = true;
                    cout << "\n\n\n";
                    break;
            case 'Y' : repeat = true;
                    cout << "\n\n\n";
                    break;
            case 'n' : repeat = false;
                    cout << "Exiting..." << endl;
                    break;
            case 'N' : repeat = false;
                    cout << "Exiting..." << endl;
                    break;
        }
    }
}