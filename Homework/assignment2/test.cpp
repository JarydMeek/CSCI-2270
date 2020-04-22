#include <iostream>

using namespace std;

struct wordItem {
    string word;
    int count;
};

wordItem* resizeArray(wordItem* array, int &size) {
	//double the size of the new array
    int newSize = size *2;
    //create new doubled array
	wordItem *newArray = new wordItem[newSize];
    //transfer Contents
	for (int i = 0; i < size; i++) {
		newArray[i] = array[i];
	}
    //be a good egg and clear the memory
	delete[] array;
    //update the size
	size = newSize;
    //return the new array
	return newArray;

}



int main() {
    string stringArray[3] = {"a", "b", "c"};
    int countArray[3] = {10,11,12};
    int numberOfUniqueWords=3;
    wordItem *tests = new wordItem[3];
    for (int i = 0; i < numberOfUniqueWords; i++) {
        tests[i].count = countArray[i];
        tests[i].word = stringArray[i];
    }

    tests = resizeArray(tests, numberOfUniqueWords);

    for (int i = 0; i < 6; i++) {
        cout << tests[i].word << " - " << tests[i].count << endl;
    }
}