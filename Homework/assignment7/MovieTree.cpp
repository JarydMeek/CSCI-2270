#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

/* ------------------------------------------------------ */
MovieTree::MovieTree()
{
	root = NULL;
}
void destroyAllTheThings(TreeNode * current) {
  if (current != NULL) {
    destroyAllTheThings(current -> leftChild);
    destroyAllTheThings(current -> rightChild);
    while (current ->head != NULL) {
        LLMovieNode * temp = current -> head;
        current -> head = temp -> next;
        delete temp;
    }
    delete current;
  }
}
MovieTree::~MovieTree()
{
  destroyAllTheThings(root);
    root = NULL;
}

void printMovies(TreeNode * current) {
    if (current == NULL) {
        return;
    }
    printMovies(current -> leftChild);
    cout << "Movies starting with letter: " << current -> titleChar << endl;
    LLMovieNode * currentMovie = current -> head;
    while (currentMovie != NULL) {
        cout << " >> " << currentMovie -> title << " " << currentMovie -> rating << endl;
        currentMovie = currentMovie -> next;
    }
    printMovies(current -> rightChild);
}

void MovieTree::printMovieInventory()
{
    printMovies(root);
}

TreeNode * findLetter(TreeNode * &root, char letter) {
    TreeNode * current = root;
    TreeNode * previous;
    bool foundNode = false;

    while (!foundNode) {
        previous = current;
        if (root == NULL) {
            TreeNode * temp = new TreeNode;
            temp -> titleChar = letter;
            root = temp;
            return temp;
        }else if (current -> titleChar == letter) {
            return current;
        } else if (current -> titleChar > letter) {
            if (current -> leftChild == NULL) {
                TreeNode * temp = new TreeNode;
                temp -> titleChar = letter;
                current -> leftChild = temp;
                temp -> parent = current;
                return current -> leftChild;
            } else {
                current = current -> leftChild;
            }
        } else if (current -> titleChar < letter) {
            if (current -> rightChild == NULL) {
                TreeNode * temp = new TreeNode;
                temp -> titleChar = letter;
                temp -> parent = current;
                current -> rightChild = temp;
                return current -> rightChild;
            } else {
                current = current -> rightChild;
            }
        }
    }
}

void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
    //First, Create a new node with the movie info
    LLMovieNode * newNode = new LLMovieNode(ranking, title, year, rating);

    //Next, let us see if we can find a linked list with the letter corresponding to the title
    TreeNode * foundTreeNode = findLetter(root, title[0]);


    //We now have a linked list, so find the place to add the element
    if (foundTreeNode -> head == NULL){
        foundTreeNode -> head = newNode;
        return;
    } else {
        LLMovieNode * current = foundTreeNode -> head;
        LLMovieNode * previous = NULL;
        bool repeat = true;
        while (repeat){
            if (current -> next == NULL) {
                if (current -> title < newNode -> title) {
                    current -> next = newNode;
                    return;
                } else {
                    if (previous == NULL) {
                        foundTreeNode -> head = newNode;
                        newNode -> next = current;
                    } else {
                        newNode -> next = foundTreeNode -> head;
                        foundTreeNode -> head = newNode;

                    }
                    return;
                }
            } else if (current -> title < title && current -> next -> title > title) {
                newNode -> next = current -> next;
                current -> next = newNode;
                return;
            }
            previous = current;
            current = current -> next;
        }
    }
}

TreeNode * searchLetter(TreeNode * root, char letter) {
    TreeNode * current = root;
    bool foundNode = false;
    while (!foundNode) {
        if (current -> titleChar == letter) {
            return current;
        } else if (current -> titleChar > letter) {
            if (current -> leftChild == NULL) {
                return NULL;
            } else {
            current = current -> leftChild;
            }
        } else if (current -> titleChar < letter) {
            if (current -> rightChild == NULL) {
                return NULL;
            } else {
            current = current -> rightChild;
            }
        }
    }
}
LLMovieNode * searchTitle(TreeNode * foundMovieNode, LLMovieNode * &previous, string title) {
    LLMovieNode * current = foundMovieNode -> head;
    bool foundNode = false;
    while (!foundNode) {
        if (current -> title == title) {
            return current;
        } else {
            if (current -> next != NULL) {
                previous = current;
                current = current -> next;
            } else {
                return NULL;
            }
        }
    }
}

TreeNode * findMin(TreeNode * startingPoint) 
{ 
    TreeNode * current = startingPoint; 
    while (current && current->leftChild != NULL) 
        current = current->leftChild; 
  
    return current; 
} 

void deleteTreeNode(TreeNode * foundTreeNode, TreeNode * &root) {
    //Find out if tree node is right child or left child of parent
    bool isRightNode;
    if (foundTreeNode == root) {

    }else if (foundTreeNode -> parent -> rightChild == foundTreeNode) {
        isRightNode = true;
    } else {
        isRightNode = false;
    }
    //If foundTreeNode is a leaf node, just delete it and reset parent
    if (foundTreeNode -> rightChild == NULL && foundTreeNode -> leftChild == NULL) {
        if (foundTreeNode == root) {
            root = NULL;
            delete foundTreeNode;
            return;
        }
        if (isRightNode) {
            foundTreeNode -> parent -> rightChild = NULL;
        } else {
            foundTreeNode -> parent -> leftChild = NULL;
        }
        delete foundTreeNode;
        return;
    //If foundTreeNode has one child on the left, just delete it, and set the child to be the parent
    }else if (foundTreeNode -> rightChild == NULL && foundTreeNode -> leftChild != NULL) {
        if (isRightNode) {
            foundTreeNode -> parent -> rightChild = foundTreeNode -> leftChild;
            foundTreeNode -> leftChild -> parent = foundTreeNode -> parent;
        } else {
            foundTreeNode -> parent -> leftChild = foundTreeNode -> leftChild;
            foundTreeNode -> leftChild -> parent = foundTreeNode -> parent;
        }
        delete foundTreeNode;
        return;
    //If foundTreeNode has one child on the right, just delete it, and set the child to be the parent
    }else if (foundTreeNode -> rightChild != NULL && foundTreeNode -> leftChild == NULL) {
        if (foundTreeNode == root) {
            root = foundTreeNode -> rightChild;
            root -> parent = NULL;
            delete foundTreeNode;
            return;
        } else {
            if (isRightNode) {
                foundTreeNode -> parent -> rightChild = foundTreeNode -> rightChild;
                foundTreeNode -> rightChild -> parent = foundTreeNode -> parent;
            } else {
                foundTreeNode -> parent -> leftChild = foundTreeNode -> rightChild;
                foundTreeNode -> rightChild -> parent = foundTreeNode -> parent;
            }
            delete foundTreeNode;
            return;
        }

    //The node has two children, things just got more complicated.
    } else {
        TreeNode * minNode = findMin(foundTreeNode -> rightChild);

        if (minNode -> rightChild != NULL) {
            minNode -> parent -> leftChild = minNode -> rightChild;
        } 

        if (root == foundTreeNode) {
            root = minNode;
            minNode -> parent = NULL;
        } else {
             minNode -> parent = foundTreeNode -> parent;
            if (isRightNode) {
                foundTreeNode -> parent -> rightChild = minNode;
            } else {
                foundTreeNode -> parent -> leftChild = minNode;
            }
        }
        minNode -> leftChild = foundTreeNode -> leftChild;
        foundTreeNode -> leftChild -> parent = minNode;
        minNode -> rightChild = foundTreeNode -> rightChild;
        foundTreeNode -> rightChild -> parent = minNode;
        delete foundTreeNode;
        return;
    }
}

void MovieTree::deleteMovie(std::string title) {

    if (root == nullptr) {
        cout << "Movie: " << title << " not found, cannot delete." << endl;
        return;
    }

    char firstLetter = title[0];

    TreeNode * foundTreeNode = searchLetter(root, firstLetter);

    if (foundTreeNode == NULL) {
        cout << "Movie: " << title << " not found, cannot delete." << endl;
        return;
    }

    LLMovieNode * previous = NULL;
    LLMovieNode * foundMovieNode = searchTitle(foundTreeNode, previous, title);

    if (foundMovieNode == NULL) {
        cout << "Movie: " << title << " not found, cannot delete." << endl;
        return;
    }
    //We have found the movie title, we can go about deleting the movie now.
    if (previous == NULL) {
        foundTreeNode -> head = foundMovieNode -> next;
    } else {
        previous -> next = foundMovieNode -> next;
    }

    delete foundMovieNode;


    //Finally see if the node is now empty, if it is, get rid of it.

    if (foundTreeNode -> head == NULL) {
        deleteTreeNode(foundTreeNode, root);
    }
}





void MovieTree::leftRotation(TreeNode* curr)
{

    TreeNode * newTop = curr -> rightChild;
    if (root == curr) {
        root = newTop;
        newTop -> parent = NULL;
    } else {
        TreeNode * previous = curr -> parent;
        bool rightChildPrev;
        if (previous -> rightChild == curr) {
            rightChildPrev = true;
        } else if (previous -> leftChild == curr) {
            rightChildPrev = false;
        }
        if (rightChildPrev) {
            previous -> rightChild = newTop;
        } else {
            previous -> leftChild = newTop;
        }
        newTop -> parent = previous;
    }
    if (newTop -> leftChild != NULL) {
        curr -> rightChild = newTop -> leftChild;
        newTop -> leftChild -> parent = curr;
    } else {
        curr -> rightChild = NULL;
    }

    curr -> parent = newTop;
    newTop -> leftChild = curr;

}

//------ Given Methods--------//
void _grader_inorderTraversal(TreeNode * root)
{
	if (root == NULL) {
		return;
	}

	_grader_inorderTraversal(root->leftChild);
	cout << root->titleChar << " ";
	_grader_inorderTraversal(root->rightChild);
}


void MovieTree::inorderTraversal() {
	_grader_inorderTraversal(root);
	cout << endl;
}



TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchChar(char key)
{
    return searchCharHelper(root, key);
}
