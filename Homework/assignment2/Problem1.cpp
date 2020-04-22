#include <iostream>
#include <fstream>
#include <iomanip>


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
    //be a good egg and clear the memory∂
	delete[] array;
    //update the size
	size = newSize;
    //return the new array
	return newArray;

}

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]){
    //Reads ignored words
    ifstream inStream;      // stream for reading in file
    inStream.open(ignoreWordFileName); // open the file
    string ignoreWord;
    int commonWordNumber = 0;
    if (inStream.is_open()) {
        while (inStream >> ignoreWord ){

            ignoreWords[commonWordNumber] = ignoreWord;
            commonWordNumber++;
        }
    } else {
        cout << "Failed to open " << ignoreWordFileName << endl;
    }
    inStream.close(); // close the file
}

bool isStopWord(string word, string ignoreWords[]) {
        bool wordMatched = false;
        for (int i = 0; i < 50; i++) {
            if (word == ignoreWords[i])
                wordMatched = true;
        }
        return wordMatched;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length) {
    int total = 0;
    for (int i = 0; i < length; i++) {
        total = total+ uniqueWords[i].count;
    }
    return total;
}

void arraySort(wordItem uniqueWords[], int length) {
    for (int j = 0; j < length; j++) {
        for (int i = 0; i < length-1; i++) {
            if (uniqueWords[i].count < uniqueWords[i+1].count) {
                wordItem temp = uniqueWords[i];
                uniqueWords[i] = uniqueWords[i+1];
                uniqueWords[i+1] = temp;
            }
        }
    }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords) {
    for (int i = N; i < (N+10); i++) {
        float temp =  (float)uniqueWords[i].count/totalNumWords;
        cout << fixed << setprecision(4) << temp << " - " << uniqueWords[i].word << endl;
    }
}

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
    } else {
        //Read Arguments to variables
        int number = stoi(argv[1]);
        string toRead = argv[2];
        const char *toIgnore = argv[3];

        //Storage variables for Doubling and other functions
        int capacity = 100;
        string ignoreWords[50];

        //Storage variables for data for output
        int numArrayDoubled = 0;
        int numUniqueWords = 0;
        wordItem *wordStorage;
        wordStorage = new wordItem[100];

        //Read stop words
        getStopWords(toIgnore, ignoreWords);

        //Reads actual words
        ifstream streamToRead;      // stream for reading in file
        streamToRead.open(toRead); // open the file
        string word;
        bool wordMatched;
        while (streamToRead >> word){
            if (numUniqueWords == capacity) {
                wordStorage = resizeArray(wordStorage, capacity);
                numArrayDoubled++;
            }
            bool wordMatched = isStopWord(word, ignoreWords);
            if (wordMatched == false) {
                bool newWord = true;
                int wordIndex = -1;
                for (int i = 0; i < numUniqueWords; i++) {
                    if (word == wordStorage[i].word) {
                        newWord = false;
                        wordIndex = i;
                    }
                }
                if (newWord == true) {
                    wordStorage[numUniqueWords].word = word;
                    wordStorage[numUniqueWords].count = 1;
                    numUniqueWords++;
                } else {
                    wordStorage[wordIndex].count++;
                }
            }
        }
        streamToRead.close(); // close the file


        int totalWords = getTotalNumberNonStopWords(wordStorage, numUniqueWords);

        arraySort(wordStorage, numUniqueWords);
        
        //Begin Output
        cout << "Array doubled: " << numArrayDoubled << endl;
        cout << "#" << endl;
        cout << "Unique non-common words: " << numUniqueWords << endl;
        cout << "#" << endl;
        cout << "Total non-common words: " << totalWords << endl;
        cout << "#" << endl;
        cout << "Probability of next 10 words from rank " << number << endl;
        cout << "---------------------------------------" << endl;
        printNext10(wordStorage, number, totalWords);
    }
}