#ifndef HASHLINEAR_HPP
#define HASHLINEAR_HPP

#include <string>
#include "hashTableChaining.hpp"//ONLY INCLUDED FOR NODE DEFINITION

using namespace std;

//Jaryd Meek
//Created this header and implementation for the Hash Tables

class HashTableLinear
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numOfcolision = 0;
public:
    HashTableLinear(int bsize);  // Constructor
    bool insertItem(int key);
    unsigned int hashFunction(int key);
    void printTable();
    int getNumOfCollision();
    node* searchItem(int key);
};

#endif
