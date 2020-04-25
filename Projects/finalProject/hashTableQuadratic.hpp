#ifndef HASHQUAD_HPP
#define HASHQUAD_HPP

#include <string>
#include "hashTableChaining.hpp"//ONLY INCLUDED FOR NODE DEFINITION

using namespace std;


class HashTableQuadratic
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numOfcolision = 0;
public:
    HashTableQuadratic(int bsize);  // Constructor
    bool insertItem(int key);
    unsigned int hashFunction(int key);
    void printTable();
    int getNumOfCollision();
    node* searchItem(int key);
};

#endif
