#ifndef LINKEDLIST_H
#define LINKEDLIST_H


//Collin Graham
//Created this header and implementation for the Linked List

//Node Struct that will be stored in the linked list object 
struct Node
{
    int key;
    Node *next;
};

//Linked List class
class LinkedList
{
    private:
        Node *head; //Pointer to the first created node
        Node *tail; //Pointer to the last created node

    public:
        LinkedList(); //Constructor
        void insert(int key); 
        Node* search(int key);
        void display();
};

#endif