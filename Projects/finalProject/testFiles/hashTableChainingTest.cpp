#include "../hashTableChaining.hpp"
#include <iostream>


using namespace std;


int main() {

    HashTableChain hashTable(10);

    cout << "ADDING 10" << endl;
    hashTable.insertItem(10);
    cout << "ADDING 20" << endl;
    hashTable.insertItem(20);
    cout << "ADDING 5" << endl;
    hashTable.insertItem(5);

    hashTable.printTable();
    cout << "NUMBER OF COLLISIONS - " << hashTable.getNumOfCollision() << endl;

    cout << hashTable.searchItem(20) << endl;
}