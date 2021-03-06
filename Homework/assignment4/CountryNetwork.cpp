/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represent communication paths between nations             */
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
/* finished. do not touch. */
    head = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName) {
    
    // if we are passed an empty list, just create a new head node, and return
    if (head == NULL)
    {
        cout << "adding: " << countryName << " (HEAD)" << endl;
        head = new Country;
        head->name = countryName;
        head->numberMessages = 0;
        head->next = NULL;
    }
    // if it's not empty, we need to search for previous and append our node there.
    else if(previous == NULL )
    {
        //case where it's a new head Country
        cout << "adding: " << countryName << " (HEAD)" << endl;
        Country *c = new Country;
        c->name = countryName;
        c->numberMessages = 0;
        c->next = head;
        head = c;
    }else{
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
        Country *newCountry = new Country;
        newCountry->name = countryName;
        newCountry->numberMessages = 0;
        newCountry->next = previous->next;
        previous->next = newCountry;
    }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) {
    //TODONE :)
    Country *prev;
    Country *current = head;
        while (current->name != countryName && current->next != nullptr) {
            prev = current;
            current = current -> next;
        }
    if (current->next == nullptr && current->name != countryName) {
        cout << "Country does not exist." << endl;
    } else {
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    int num_countries = 6;
    string countries[] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
    // deleteEntireNetwork();
    Country* prev = NULL;
    for(int i = 0; i < num_countries; i++)
    {
        insertCountry(prev, countries[i]);
        prev = searchNetwork(countries[i]);
    }
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
// Search until the head is NULL, or we find the country
    Country* ptr = head;
    while (ptr != NULL && ptr->name != countryName)
    {
        ptr = ptr->next;
    }
    // Return the node, or NULL
    return ptr;
}

/*
* Purpose: Creates a loop from last node to the country specified.
* @param countryName name of the country to loop back
* returns pointer to last node before loop creation (to break the loop)
*/
Country* CountryNetwork::createLoop(string countryName)
{
    //TODO: Complete this function
    Country *loopPoint = searchNetwork(countryName);
    Country *current = head;
    while (current ->next != nullptr) {
        current = current->next;
    }
    current->next = loopPoint;
    return current;
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
    //TODO: Complete this function
    Country *prev;
    Country *current = head;
    if (head == nullptr) {
        return;
    } else {
        while (current->next != nullptr) {
            prev = current;
            current = current -> next;
            cout << "deleting: " << prev->name << endl;
            delete prev;
        }
        cout << "deleting: " << current->name << endl;
        delete current;
        cout << "Deleted network" << endl;
        head = nullptr;
    }
}

/*
*Purpose: to detect loop in the linkedlist
* @param
* returns true if loop is detected. Otherwise return false.
*/
bool CountryNetwork::detectLoop() {
    //TODO: Complete this function
    Country *slow = head;
    Country *fast = head;
    bool secondRun = false;
    while (slow->next != nullptr) {
        if (slow->next ==nullptr || fast ->next -> next == nullptr) {
            return false;
        } else if (slow == fast && secondRun == true) {
            return true;
        }
        secondRun = true;
        slow = slow -> next;
        fast = fast->next->next;
    }
    return true;
}

/*
* Purpose: Take the chunk of nodes from start index to end index
*          Move that chunk at the end of the List
*@param: start index
*@param: end index
* return none
*/
void CountryNetwork:: readjustNetwork(int start_index, int end_index)
{
    int numInList = 0;
    if (head != nullptr) {
        Country *counter = head;
        while (counter->next != nullptr) {
            numInList++;
            counter = counter -> next;
        }
    }
    //TODO: Complete this function
    if (head == nullptr) {
        cout << "Linked List is Empty" << endl;
    }else if (end_index > numInList || end_index < 0) {
        cout << "Invalid end index" << endl;
    } else if (start_index > numInList || start_index < 0) {
        cout << "Invalid start index" << endl;
    } else if (start_index > end_index) {
        cout << "Invalid indices" << endl;
    }  else if (start_index == end_index) {
        Country *endOfList = head;
        while (endOfList->next != nullptr) {
            endOfList = endOfList ->next;
        }
        Country *beforeSelection = nullptr;
        Country *moveToEnd = head;
        Country *afterSelection = nullptr;
        for (int i = 0; i < start_index; i++) {
            beforeSelection = moveToEnd;
            moveToEnd = moveToEnd->next;
            afterSelection = moveToEnd -> next;
        }
        beforeSelection ->next = afterSelection;
        endOfList->next = moveToEnd;
        moveToEnd-> next = nullptr;
    } else {
        Country *endOfList = head;
        while (endOfList->next != nullptr) {
            endOfList = endOfList ->next;
        }
        Country *beforeStart = nullptr;
        Country *start = head;
        for (int i = 0; i < start_index; i++) {
            beforeStart = start;
            start = start->next;
        }
        Country *end = start;
        Country *afterEnd;
        for (int i = 0; i < (end_index-start_index); i++) {
            end = end->next;
            afterEnd = end->next;
        }
        if (beforeStart == nullptr) {
            head = afterEnd;
        } else {
            beforeStart -> next = afterEnd;
        }
        endOfList->next = start;
        end -> next = nullptr;
    
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    Country* ptr = head;
    if (ptr == NULL)
        cout << "nothing in path" << endl;

    // Otherwise print each node, and then a NULL
    else
    {
        while (ptr->next != NULL)
        {
            cout << ptr->name << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->name << " -> ";
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
