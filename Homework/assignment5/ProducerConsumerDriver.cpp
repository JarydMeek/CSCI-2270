/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
	ProducerConsumer list;
	bool repeat = true;
	while (repeat) {
		menu();
		int selection = 0;
		cin >> selection;

		if (selection == 1) {
			int numItems;
			cout << "Enter the number of items to be produced:" << endl;
			cin >> numItems;
			cin.ignore();
			for (int i = 1; i < numItems + 1; i++) {
				string itemName;
				cout << "Item" << i << ":" << endl;
				getline(cin,itemName);
				list.enqueue(itemName);
			}
		} else if (selection == 2) {
			cout << "Enter the number of items to be consumed:" << endl;
			int numRuns = 0;
			cin >> numRuns;
			for (int i = 0; i < numRuns; i++) {
				if (list.isEmpty()) {
					cout << "No more items to consume from queue" << endl;
				} else {
					cout << "Consumed: " << list.peek() << endl;
					list.dequeue();
				}
			}
		} else if (selection == 3) {
			int counter = 0;
			while (list.isEmpty() == false) {
				list.dequeue();
				counter++;
			}
			repeat = false;
			cout << "Number of items in the queue:" << counter << endl;
		}
	}
}
