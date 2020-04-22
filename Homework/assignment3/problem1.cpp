#include <iostream>

using namespace std;

bool append(string* &str_arr, string s, int &numEntries, int &arraySize) {
	bool returnValue = false;
    
    if (numEntries == arraySize) {
        //double the size of the new array
        int newSize = arraySize *2;
        //create new doubled array
        string *newArray = new string[newSize];
        //transfer Contents
        for (int i = 0; i < arraySize; i++) {
            newArray[i] = str_arr[i];
        }
        //be a good egg and clear the memory∂
        delete[] str_arr;
        //update the size
        arraySize = newSize;
        //return the new array
        str_arr = newArray;
        returnValue = true;
    }
    str_arr[numEntries] = s;
    numEntries++;
    return returnValue;

}


int main() {
    int size = 10;
    int numEntries = 0;
    string *test = new string[10];

    for (int i = 0; i < 100; i++) {
        append(test,to_string(i) ,numEntries,size);
    }
    for (int i = 0; i < numEntries; i++) {
        cout << test[i] << " " << i<< endl;
    }
}