/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    // TODO

}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    Country *newCountry = new Country;
    newCountry->name = countryName;
    if (previous == nullptr) {
        if (head != nullptr) {
            newCountry->next = head;
        }
        head = newCountry;
        cout << "adding: " << countryName << " (HEAD)" << endl;
    } else {
        if (previous->next != nullptr) {
            newCountry->next = previous->next;
        }
        previous->next = newCountry;
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    insertCountry(nullptr,"United States");
    insertCountry(searchNetwork("United States"),"Canada");
    insertCountry(searchNetwork("Canada"),"Brazil");
    insertCountry(searchNetwork("Brazil"),"India");
    insertCountry(searchNetwork("India"),"China");
    insertCountry(searchNetwork("China"),"Australia");

}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    bool foundCountry = false;
    Country* currentCountry = head;
    while (foundCountry == false && currentCountry != nullptr) {
        if (currentCountry->name == countryName) {
            foundCountry = true;
            return currentCountry;
        } else {
            currentCountry = currentCountry->next;
            
        }
    }
    return nullptr;

}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
    // TODO
    if(head == nullptr) {
        cout << "Empty list" << endl;
    } else if (searchNetwork(receiver) == nullptr) {
        cout << "Country not found" << endl;
    } else {
        Country *current;
        current = head;
        while (current != nullptr) {
            current->message = message;
            current->numberMessages++;
            cout << current->name << " [# messages received: " << current->numberMessages << "] received: " << current->message << endl;
            if (current == searchNetwork(receiver)) {
                current = nullptr;
                break;
            } else {
                current = current->next;
            }
        }
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    // TODO
    Country *current;
    current = head;
    cout << "== CURRENT PATH ==" << endl;
    if (head == nullptr) {
        cout << "nothing in path" << endl;
    } else {
        while(current != nullptr) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
