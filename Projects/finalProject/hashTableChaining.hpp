#ifndef HASHCHAIN_HPP
#define HASHCHAIN_HPP

#include <string>


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
public:
    HashTableChain(int bsize);  // Constructor
    bool insertItem(int key);
    unsigned int hashFunction(int key);
    void printTable();
    int getNumOfCollision();
    node* searchItem(int key);
};

#endif
