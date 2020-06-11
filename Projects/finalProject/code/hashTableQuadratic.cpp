#include "hashTableQuadratic.hpp"
#include "hashTableChaining.hpp"//ONLY INCLUDED FOR NODE DEFINITION
#include<iostream>

using namespace std;
    // Constructor
    // Sets table size, and creates correct size table, as well as wiping all the nodes in the table.

    HashTableQuadratic::HashTableQuadratic(int bsize) {
        tableSize = bsize;
        table = new node*[bsize];
        for (int i = 0; i < bsize; i++){
            table[i] = nullptr;
        }
    }

    // inserts a key into hash table
    // first, hashes given value, then creates new node with matching value, then loops through indices to find the first available index USING QUADRATIC PROBING, and adds the new node.
    bool HashTableQuadratic::insertItem(int key) {
        //Hash the key
        int hashResult = hashFunction(key);
        //Create new node with key
        node * newNode = new node;
        newNode -> key = key;
        newNode -> next = nullptr;
        //storage for repetition, current index, and counter for quadratic operation
        bool added = false;
        int insertIndex = hashResult;
        int counter = 1;
        //loop to continue until the new node gets added.
        while(!added){
            //the current index is empty, add the new node there, and break loop
            if (table[insertIndex] == nullptr){
                table[insertIndex] = newNode;
                added = true;
                return true;
            //current index is full, add a collision, and set next index according to quadratic probing
            } else if (table[insertIndex] != nullptr){
                //add a collision
                numOfcolision++;
                //set new index according to quadratic probing
                insertIndex = hashResult + (counter*counter); 
                //add to the counter in case we need to check another index
                counter++;
                //if the index would go to the end of the table, go to the beginning
                //NOTE - Chose to start from the remainder when it reaches the end, not from index 0
                if (insertIndex >= tableSize) {
                    insertIndex = insertIndex-tableSize;
                }
            //Something somewhere broke bad. Uh oh D:
            } else {
                return false;
            }
        }
        //Statement to make compiler happy :)
        return false;
    }

    // hash function to map values to key
    unsigned int HashTableQuadratic::hashFunction(int key) {
        return (key % tableSize);
    }


    // Prints hash table (for debug purposes mainly)
    // prints each index, then the LL that pertains to that index
    void HashTableQuadratic::printTable() {
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
    int HashTableQuadratic::getNumOfCollisionInsert(){
        return numOfcolision;
    }
    //Just a getter for number of collisions on search
    int HashTableQuadratic::getNumOfCollisionSearch(){
        return numOfcolisionSearch;
    }

    //Search function for node that matches key
    //First, hashes key, then checks each node starting at the hash result until it either finds the correct node, or reachings starting point again
    //utilizes quadratic probing while check indices
    node* HashTableQuadratic::searchItem(int key){
        //hash the given key
       int index = hashFunction(key);
       //track original hash so we know when we've looped through all indices
       int originalHash = index;
        //loop through all indices (According to quadratic probing) starting at the original hash, and track counter to allow quadratic probing.
       node * current = table[index];
       int counter = 1;
       while (current ->key != key) {
           //we couldn't find the correct value, setup new index
            index = originalHash + (counter*counter);
            numOfcolisionSearch++;
            //index would go over the size of the array, move to beginning of array
            //NOTE - chose to move to remainder at beginning of array, not 0
            if (index >= tableSize) {
                index = index-tableSize;
            }
            //update current node
            current = table[index];
            //you made it through either every possible index, or you went through the order of indices and couldn't find the node, give message
            if (originalHash == index || current == nullptr) {
                cout << "Couldn't Find Node" << endl;
                return nullptr;
            }
            //incriment the counter
            counter++;
        }
    //return the found node
    return current;
    }