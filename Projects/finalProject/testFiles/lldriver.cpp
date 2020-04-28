#include "LinkedList.hpp"
#include <iostream>

using namespace std;

int main()
{
    LinkedList l;
    l.insert(1);
    l.insert(5);
    l.insert(12);
    l.insert(13);
    l.insert(14);
    l.insert(16);
    l.insert(18);
    l.insert(19);
    l.insert(1000);
    l.display();
    
    Node *temp = new Node();

    temp = l.search(14);
    cout << "Search: 14 || Found: " << temp->key << endl;
    temp = l.search(1000);
    cout << "Search: 1000 || Found: " << temp->key << endl;
    temp = l.search(4);
    cout << "Search: 4 || Found: " << temp->key << endl;
    
    return 0;
}