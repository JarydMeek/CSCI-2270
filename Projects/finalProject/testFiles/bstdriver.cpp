#include "BST.hpp"
#include <iostream>

using namespace std;

int main()
{
    BST b;
    b.insert(2);
    b.insert(5);
    b.insert(6);
    b.insert(4);
    b.insert(0);
    b.insert(1);

    b.display(b.getRoot(), 1);

    Node* Temp = b.search(0);
    cout << "Found: " << Temp->key << endl;
    Temp = b.search(10);
    //cout << "Found: " << Temp->key << endl;
    return 0;
}