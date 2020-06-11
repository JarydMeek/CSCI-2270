#ifndef HASHQUAD_HPP
#define HASHQUAD_HPP

#include <string>
#include "hashTableChaining.hpp"//ONLY INCLUDED FOR NODE DEFINITION

using namespace std;

//Jaryd Meek
//Created this header and implementation for the Hash Tables

class HashTableQuadratic
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numOfcolision = 0;
    int numOfcolisionSearch = 0;
public:
    HashTableQuadratic(int bsize);  // Constructor
    bool insertItem(int key);
    unsigned int hashFunction(int key);
    void printTable();
    int getNumOfCollisionInsert();
    int getNumOfCollisionSearch();
    node* searchItem(int key);
};

#endif
