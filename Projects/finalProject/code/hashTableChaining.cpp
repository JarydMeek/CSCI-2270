#include "hashTableChaining.hpp"
#include<iostream>

using namespace std;
    // Constructor
    // Sets table size, and creates correct size table, as well as wiping all the nodes in the table.
    HashTableChain::HashTableChain(int bsize) {
        tableSize = bsize;
        table = new node*[bsize];
        for (int i = 0; i < bsize; i++){
            table[i] = nullptr;
        }
    }


    // inserts a key into hash table
    // Hashes the value passed, creates a new node and adds value, then adds node either at a index, or at the bottom of a list at an index to create chaining
    bool HashTableChain::insertItem(int key) {
        //Hash value
        int hashResult = hashFunction(key);
        //create node with new value
        node * newNode = new node;
        newNode -> key = key;
        newNode -> next = nullptr;
        //check to see where to add node
        //there is no node already at head of LL at index, add new node to index
        if (table[hashResult] == nullptr){
            table[hashResult] = newNode;
            return true;

        //there already is a node at head of ll, add new node to bottom of linked list
        } else if (table[hashResult] != nullptr){
            numOfcolision++;//track collisions
            node * current = table[hashResult];
            while(current ->next != nullptr){
                current = current -> next;
            }
            current -> next = newNode;
            return true;
        //Something broke. D:
        } else {
            return false;
        }
    }

    // hash function to map values to key
    unsigned int HashTableChain::hashFunction(int key) {
        return (key % tableSize);
    }

    // Prints hash table (for debug purposes mainly)
    //prints each index, then the LL that pertains to that index
    void HashTableChain::printTable() {
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

    //Just a getter for number of collisions on insert
    int HashTableChain::getNumOfCollisionInsert(){
        return numOfcolision;
    }
    //Just a getter for number of collisions on search
    int HashTableChain::getNumOfCollisionSearch(){
        return numOfcolisionSearch;
    }

    //Search function for node that matches key
    //first, runs hash function again, then checks the LL at that index for node that matches the key passed to function
    node* HashTableChain::searchItem(int key){
        //hash the key
       int hashResult = hashFunction(key);
        //work through LL at index to find matching node
        node * current = table[hashResult];
        while (current ->key != key) {
            numOfcolisionSearch++;
            current = current -> next;

            //reached end of list and didn't find matching node
            if (current == nullptr) {
                cout << "Couldn't Find Node" << endl;
                return nullptr;
            }
        }
        //return the proper node
        return current;
    }