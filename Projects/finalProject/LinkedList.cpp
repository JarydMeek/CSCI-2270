#include "LinkedList.hpp"
#include <iostream>

using namespace std;

/* Purpose: Create the Linked List object
 * Parameters: None
 * Output: None
 * Return: None
 */ 
LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

/* Purpose: Insert a node at the end (tail) of the linked list object
 * Parameters: key (int)
 * Output: None
 * Return: None
 */
void LinkedList::insert(int key)
{
    if(head == nullptr) //If list is empty
    {
        Node *newNode = new Node();
        newNode->key = key;
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node();
        newNode->key = key;
        tail->next = newNode;
        newNode->next = nullptr;
        tail = newNode; 
    }
}

/* Purpose: Search for the node with the given int in the Linked List object
 * Parameters: key (int)
 * Output: If the node could not be found, output "Could not find"
 * Return: The desired node or an unconnected node with key -1
 */
Node* LinkedList::search(int key)
{
    Node *temp = new Node();
    temp = head;

    //Traversing the list
    while(temp != nullptr) 
    {
        if(temp->key == key) //If it is found
            return temp;
        else
            temp = temp->next;
    }

    //if the node is not found
    cout << "Could not find " << key << endl;
    temp = new Node();
    temp->key = -1;
    temp->next = nullptr;
    return temp;
}

/* Purpose: Display the whole Linked List
 * Parameters: None
 * Output: The Linked List in order
 * Return: None
 */
void LinkedList::display()
{
    Node *temp = new Node();
    temp = head;
    //for each node in the list
    while(temp != nullptr)
    {
        cout << temp->key << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
