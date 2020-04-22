#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10

/*
PUBLIC METHODS:
*/

// Constructor definitions:
// Default:
BST::BST(){
    root = nullptr;
}

void BST::addNode(int data){
    root = addNodeHelper(root, data);
    cout<<data<<" has been added"<<endl;
}

void BST::print2DUtil(int space)
{
    print2DUtilHelper(root, space);
}

/*
PRIVATE METHODS:
*/




//  TODO:
//  Write a function decrementLeaves that goes through a Binary Search Tree 
//  and subtracts 1 from each of the leaf nodes. Feel free to implement an 
//  additional helper function.

//Helper function  - PreOrder Transverses the graph and if the node is a leaf node, subtracts one, then checks if the node needs to be deleted, if it does, delete it.
void subtractOneFromLeaves(Node *node) {
  if (node == NULL) { //is after a leaf node, is NULL node
    return;

  } else if (node -> left == NULL && node -> right == NULL) { //Is a leaf node

    /* DECREMENT THE LEAF NODE */

      node -> key = node -> key - 1; //subtract one
    
    /* CHECK FOR DELETION */
    
    //First, check to see if current leaf is left or right child
    if (node -> parent -> left == node) { //current leaf node is left child
        if (node -> key >= node -> parent -> key) { //If node is greater than or equal to the parent, it needs to be deleted
            node -> parent -> left = NULL; //set the parent's pointer to NULL
            delete node; //delete the leaf node
        }
    } else if (node -> parent -> right == node) { //current leaf node is right child
        if (node -> key < node -> parent -> key) { //If node is less than the parent, it needs to be deleted
            node -> parent -> right = NULL; //set the parent's pointer to NULL
            delete node; //delete the leaf node
        }
    } else {
        cout << "ERROR" << endl; //something broke. Added "Just in Case."
    }
    

  } else { //not a leaf node
    subtractOneFromLeaves(node->left); //recur to the left subtree
    subtractOneFromLeaves(node->right);//recur to the right subtree
  }
}


//The given decrement function.
void BST::decrement(){
    // Write your code here.
    subtractOneFromLeaves(root); //call recursive function
}  


//   This function will add the data in the tree rooted at currNode.
//   Call this function from insert().


Node* BST:: addNodeHelper(Node* currNode, int data){
    if(currNode == nullptr){
       return createNode(data);      
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
        currNode->right->parent = currNode;
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
        currNode->left->parent = currNode;
    }
    return currNode;
}


// Create a new node, setting key value to  input data
// and all pointers to null.
Node* BST:: createNode(int data){
    Node* newNode = new Node;
    newNode->key = data;
    newNode->parent = nullptr;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* BST::getRoot(){
    return root;
}


/*
   Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void BST::print2DUtilHelper(Node *currNode, int space){
    // Base case
    if (currNode == nullptr)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}





