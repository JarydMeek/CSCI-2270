#include "BST.hpp"
#include <iostream>


/* Purpose: Create the Linked List object
 * Parameters: None
 * Output: None
 * Return: None
 */ 
BST::BST()
{
    root = nullptr;
}

/* Purpose: Acts as the recursive piece of the insert function
 * Parameters: key (int), temp (node*)
 * Output: None
 * Return: None
 */ 
void insertHelper(NodeBST* temp, int key)
{
    if(temp->key > key && temp->left == nullptr) //if the key is less than the current node (temp), and it's left child is nullptr, insert the new node as the left child.
    {
        //creating the new node
        NodeBST *temp2 = new NodeBST();
        temp2->key = key;
        temp2->left = nullptr;
        temp2->right = nullptr;

        temp->left = temp2;
        return;
    }
    if(temp->key < key && temp->right == nullptr) //if the key is greater than the current node (temp), and it's right child is nullptr, insert the new node as the right child.
    {
        //creating the new node
        NodeBST *temp2 = new NodeBST();
        temp2->key = key;
        temp2->left = nullptr;
        temp2->right = nullptr;

        temp->right = temp2;
        return;
    }
    if(temp->key > key)
        insertHelper(temp->left, key);
    if(temp->key < key)
        insertHelper(temp->right, key);
}

/* Purpose: Inserts a new node
 * Parameters: key (int)
 * Output: None
 * Return: None
 */ 
void BST::insert(int key)
{
    //if the tree is empty
    if(root == nullptr)
    {
        //creating the new node
        NodeBST *temp2 = new NodeBST();
        temp2->key = key;
        temp2->left = nullptr;
        temp2->right = nullptr;
        root = temp2;
    }
    else
    {
        insertHelper(root, key);
    }
} 

/* Purpose: search for a node and return it
 * Parameters: key (int)
 * Output: None
 * Return: the pointer to the node with the desired key
 */ 
NodeBST* BST::search(int key)
{
    NodeBST* temp = root;
    while(true)
    {
        if(temp->key == key) //if the current node has the correct key
        {
            return temp;
        }
        else if(temp->key > key) //if the current node's key is greater than the correct key
        {
            if(temp->left != nullptr) //if it has a left child
            {
                temp = temp->left;
            }
            else //if it doesn't have a left child
            {
                cout << "Error: key not found." << endl;
                return nullptr;
            }
        }
        else
        {
            if(temp->right != nullptr) //if it has a right child
            {
                temp = temp->right;
            }
            else //if it doesn't have a right child
            {
                cout << "Error: key not found." << endl;
                return nullptr;
            }
        }
    }
}

/* Purpose: Printing a 2d visualization of the BST
 * Parameters: currentNode (node*), spacing (int)
 * Output: A 2d tree
 * Return: None
 */ 
void BST::display(NodeBST *currentNode, int spacing)
{
    //base case
    if (currentNode == nullptr)
        return;

    //increasing distance between levels
    spacing += 10;

    //right child
    display(currentNode->right, spacing);

    //print current node after spacing
    // count
    printf("\n");
    for (int i = 10; i < spacing; i++)
        printf(" ");
    printf("%d\n", currentNode->key);

    //left child
    display(currentNode->left, spacing);
}

/* Purpose: returns the root of the BST
 * Parameters: None
 * Output: None
 * Return: Pointer to the root
 */ 
NodeBST* BST::getRoot()
{
    return root;
}