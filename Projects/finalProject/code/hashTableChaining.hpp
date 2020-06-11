#ifndef HASHCHAIN_HPP
#define HASHCHAIN_HPP

#include <string>

//Jaryd Meek
//Created this header and implementation for the Hash Tables

using namespace std;

struct node
{
    int key;
    struct node* next;
};

class HashTableChain
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numOfcolision = 0;
    int numOfcolisionSearch = 0;
public:
    HashTableChain(int bsize);  // Constructor
    bool insertItem(int key);
    unsigned int hashFunction(int key);
    void printTable();
    int getNumOfCollisionInsert();
    int getNumOfCollisionSearch();
    node* searchItem(int key);
};

#endif
