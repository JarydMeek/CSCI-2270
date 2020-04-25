#include "hashTableLinear.hpp"
#include "hashTableChaining.hpp"//ONLY INCLUDED FOR NODE DEFINITION
#include<iostream>

using namespace std;
    // Constructor
    // Sets table size, and creates correct size table, as well as wiping all the nodes in the table.
    HashTableLinear::HashTableLinear(int bsize) {
        tableSize = bsize;
        table = new node*[bsize];
        for (int i = 0; i < bsize; i++){
            table[i] = nullptr;
        }
    }


    // inserts a key into hash table
    // first, hashes given value, then creates new node with matching value, then loops through indices to find the first available index, and adds the new node.
    bool HashTableLinear::insertItem(int key) {
        //Hash the given value
        int hashResult = hashFunction(key);
        //Create new node with new value
        node * newNode = new node;
        newNode -> key = key;
        newNode -> next = nullptr;
        //loop through attempts to add new node until node gets added
        bool added = false;
        while(!added){
            //the current index is empty, add the node
            if (table[hashResult] == nullptr){
                table[hashResult] = newNode;
                added = true;
                return true;
            //the current index is not empty, incriment index and try again
            } else if (table[hashResult] != nullptr){
                numOfcolision++;
                hashResult++; 
                if (hashResult >= tableSize) {
                    hashResult = hashResult-tableSize;
                }
            //Something broke D:
            } else {
                return false;
            }
        }
        //Statement just to make compiler happy :)
        return false;
    }

    // hash function to map values to key
    unsigned int HashTableLinear::hashFunction(int key) {
        return (key % tableSize);
    }

    // Prints hash table (for debug purposes mainly)
    // prints each index, then the LL that pertains to that index
    void HashTableLinear::printTable() {
        cout << "Hash Index -> Keys" << endl;
        for (int i = 0; i < tableSize; i++){
            node * current = table[i];
            cout << i << " -> ";
            while (current != nullptr) {
                cout << current -> key << " ";
                current = current ->next;
            }
            cout << endl;
        }
    }

    //Just a getter for number of collisions
    int HashTableLinear::getNumOfCollision(){
        return numOfcolision;
    }

    //Search function for node that matches key
    //First, hashes key, then checks each node starting at the hash result until it either finds the correct node, or reachings starting point again
    node* HashTableLinear::searchItem(int key){
        //Hash key
       int hashResult = hashFunction(key);
       //track original hash, to allow us to know if we've passed through the entire list without finding node
       int originalHash = hashResult;
       //loop through each node, starting at the hash result as index.
       node * current = table[hashResult];
       while (current ->key != key) {
           //we aren't at the right node, go to next node
            hashResult++;
            //we've gone through the entire array, and can't find the node, output message and return nullptr
            if (originalHash == hashResult) {
                cout << "Couldn't Find Node" << endl;
                return nullptr;
            //the index of the current searching position is greater than the size of the array, move to beginnning of array to continue
            } else if (hashResult >= tableSize) {
                hashResult = hashResult-tableSize;
            }
            //update current
            current = table[hashResult];
            //if the current index is empty, skip it (and any other index that is empty)
            while(current == nullptr){
                hashResult++;
                current = table[hashResult];
            }
        }
    //we found the node, return the node
    return current;
    }