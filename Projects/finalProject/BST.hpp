#ifndef BST_H
#define BST_H

using namespace std;


//Collin Graham
//Created this header and implementation for the BST

//Node Struct that will be stored in the linked list object 
        struct NodeBST
            {
                int key;
                NodeBST *left;
                NodeBST *right;
            };

//Linked List class
class BST
{
    private:
        NodeBST *root; //Pointer to the first created node

    public:
        BST(); //Constructor
        void insert(int key); 
        NodeBST* search(int key);
        void display(NodeBST *currNode, int space);
        NodeBST* getRoot();
};

#endif