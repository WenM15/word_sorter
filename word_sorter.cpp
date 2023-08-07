#include <iostream>

using namespace std;

int main() {
	// Create a pointer to point to an array of pointers
	char** listPointer = nullptr;

	bool redo = true;
	while (redo) {
		// Input
		cout << "Input: " << endl;

		// Define starting memory size for list
		size_t listSize = 10;
		
		// Preallocate memory for 10 words
		listPointer = (char**)::operator new(listSize * sizeof(char*));//
		
		// Set a starting wordIndex for list
		int wordIndex = 0;
		//Set a starting charIndex for each word
		int charIndex = 0;

		// Define starting memory size for words
		size_t wordSize = 10;
		
		bool isSpace = false;
		bool extractionDone = false;
		while (!extractionDone) {

			// Extraction
			char input;
			cin.get(input);

			// Filtering before storage
			if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
				if (isSpace) {
					++wordIndex;
					if (wordIndex == listSize) {
						// Allocate more memory for list
					}
					charIndex = 0;

				}
				// Preallocate memory for 10 characters
				if (charIndex == 0) {
					listPointer[wordIndex] = (char*)::operator new(wordSize * sizeof(char));//
				}

				listPointer[wordIndex][charIndex] = input;
				cout << wordIndex << " " << charIndex << " " << listPointer[wordIndex][charIndex] << endl;
				++charIndex;
				if (charIndex == wordSize) {
					// Allocate more memory for word
				}

				isSpace = false;
			}
			else if (input == ' ' || input == '\t') {
				// End of word, add \0 to the character array
				if (!isSpace) {
					listPointer[wordIndex][charIndex] = '\0';
				}
				isSpace = true;
			}
			else if (input == '\n') {
				// End of word, add \0 to the character array
				if (!isSpace) {
					listPointer[wordIndex][charIndex] = '\0';
				}
				// Add a '\0' to first character of a new c-string to indicate the end of the list
				++wordIndex;
				if (wordIndex == listSize) {
					// Allocate more memory for list
				}
				// Preallocate memory for 10 characters
				listPointer[wordIndex] = (char*)malloc(wordSize * sizeof(char));//

				// Creating a word that only has '\0', this word will denote the end of the list
				listPointer[wordIndex][0] = '\0';
				
				extractionDone = true;
				redo = false;
			}
			else {
				// Clear the buffer
				bool newlineFound = false;
				while (!newlineFound) {
					cin.get(input);
					if (input == '\n') {
						newlineFound = true;
					}
				}

				// Clear storage here
				extractionDone = true;
			}

		}//while(!extractionDone)
	}//while(redo)

	for (int wordIndex = 0; listPointer[wordIndex][0] != '\0'; ++wordIndex) {
		for (int charIndex = 0; listPointer[wordIndex][charIndex] != '\0'; ++charIndex) {
			cout << "listPointer[" << wordIndex << "][" << charIndex << "]: " << listPointer[wordIndex][charIndex] << ", ";
		}
		cout << endl;
	}
	
}//main()