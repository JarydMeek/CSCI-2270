#include "../hashTableLinear.hpp"
#include <iostream>


using namespace std;


int main() {

    HashTableLinear hashTable(10);

    cout << "ADDING 10" << endl;
    hashTable.insertItem(10);
    cout << "ADDING 20" << endl;
    hashTable.insertItem(20);
    cout << "ADDING 5" << endl;
    hashTable.insertItem(5);
    cout << "ADDING 9" << endl;
    hashTable.insertItem(9);
    cout << "ADDING 19" << endl;
    hashTable.insertItem(19);

    hashTable.printTable();
    cout << "NUMBER OF COLLISIONS - " << hashTable.getNumOfCollision() << endl;

    cout << hashTable.searchItem(19) << endl;
}