#include "../LinkedList.hpp"
#include <iostream>


using namespace std;


int main() {

    LinkedList list;

    cout << "ADDING 10" << endl;
    list.insert(10);
    cout << "ADDING 20" << endl;
    list.insert(20);
    cout << "ADDING 5" << endl;
    list.insert(5);
    cout << "ADDING 9" << endl;
    list.insert(9);
    cout << "ADDING 19" << endl;
    list.insert(19);

    list.display();

    cout << list.search(19) << endl;
}