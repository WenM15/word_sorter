#include <iostream>

using namespace std;

int main() {
	// Create a pointer to point to an array of pointers
	char** listPointer = nullptr;
	char input;

	bool redo = true;
	while (redo) {
		// Input
		cout << "Input: " << endl;

		// Define starting memory size for list
		int listSize = 10;
		// Define starting memory size for words
		int wordSize = 10;

		// Preallocate memory for 10 words
		listPointer = (char**)::operator new(listSize * sizeof(char*));//
		
		// Set a starting wordIndex for list
		int wordIndex = 0;
		// Set a starting charIndex for each word
		int charIndex = 0;

		bool isSpace = false;
		bool extractionDone = false;
		while (!extractionDone) {

			// Extraction
			cin.get(input);

			// Filtering before storage
			if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
				if (isSpace) {
					//Reset wordSize to 10;
					wordSize = 10;
					//Increment wordIndex to store new word
					++wordIndex;

					if (wordIndex == listSize) {
						// Allocate more memory for list
						
						// Create temporary array to store list's contents
						char** temp = (char**)::operator new(listSize * sizeof(char*));
						for (int wordI = 0; wordI < listSize; ++wordI) {
							// Copy characters to the temporary array
							int str_length = 0;
							for (int charI = 0; listPointer[wordI][charI] != '\0'; ++charI) {
								++str_length;
							}
							temp[wordI] = (char*)::operator new((str_length + 1) * sizeof(char));
							int charI = 0;
							while(listPointer[wordI][charI] != '\0'){
								temp[wordI][charI] = listPointer[wordI][charI];
								++charI;
							}
							temp[wordI][charI] = '\0';

							// Deallocate memory for listPointer
							::operator delete(listPointer[wordI]);
						}

						// Double the memory size for list
						listSize *= 2;
						listPointer = (char**)::operator new(listSize * sizeof(char*));

						// Copy the list's contents in temporary array back to the list
						// Similar to how the list was originally copied to temporary array
						for (int wordI = 0; wordI < listSize/2; ++wordI) {
							// Copying back
							int str_length = 0;
							for (int charI = 0; temp[wordI][charI] != '\0'; ++charI) {
								++str_length;
							}
							listPointer[wordI] = (char*)::operator new((str_length + 1) * sizeof(char));
							int charI = 0;
							while (temp[wordI][charI] != '\0') {
								listPointer[wordI][charI] = temp[wordI][charI];
								++charI;
							}
							listPointer[wordI][charI] = '\0';

							// Deallocate memory for temp array
							::operator delete(temp[wordI]);
						}
					}
					charIndex = 0;

				}// if(!isSpace)

				// Preallocate memory for 10 characters
				if (charIndex == 0) {
					listPointer[wordIndex] = (char*)::operator new(wordSize * sizeof(char));//
				}

				listPointer[wordIndex][charIndex] = input;
	
				++charIndex;
				if (charIndex == wordSize) {
					// Allocate more memory for word
					// Copy word's content to a temporary array
					char* temp = (char*)::operator new(wordSize * sizeof(char));
					for (int charI = 0; charI < wordSize; charI++) {
						temp[charI] = listPointer[wordIndex][charI];
					}
					::operator delete(listPointer[wordIndex]);
					
					// Double the memory size for the word
					wordSize *= 2;
					listPointer[wordIndex] = (char*)::operator new(wordSize * sizeof(char));

					// Copy the word's contents in temporary array back to the word
					for (int charI = 0; charI < wordSize/2; charI++) {
						listPointer[wordIndex][charI] = temp[charI];
					}
					
					::operator delete(temp);
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
				
				++wordIndex;
				if (wordIndex == listSize) {
					// Allocate more memory for list (Repeated in alphabet, consider writing a function)
					char** temp = (char**)::operator new(listSize * sizeof(char*));
					for (int wordI = 0; wordI < listSize; ++wordI) {
						// Copy characters to the temporary array
						int str_length = 0;
						for (int charI = 0; listPointer[wordI][charI] != '\0'; ++charI) {
							++str_length;
						}
						temp[wordI] = (char*)::operator new((str_length + 1) * sizeof(char));
						int charI = 0;
						while (listPointer[wordI][charI] != '\0') {
							temp[wordI][charI] = listPointer[wordI][charI];
							++charI;
						}
						temp[wordI][charI] = '\0';

						// Deallocate memory for listPointer
						::operator delete(listPointer[wordI]);
					}

					// Double the memory size for list
					listSize *= 2;
					listPointer = (char**)::operator new(listSize * sizeof(char*));

					// Copy the list's contents in temporary array back to the list
					// Similar to how the list was originally copied to temporary array
					for (int wordI = 0; wordI < listSize / 2; ++wordI) {
						// Copying back
						int str_length = 0;
						for (int charI = 0; temp[wordI][charI] != '\0'; ++charI) {
							++str_length;
						}
						listPointer[wordI] = (char*)::operator new((str_length + 1) * sizeof(char));
						int charI = 0;
						while (temp[wordI][charI] != '\0') {
							listPointer[wordI][charI] = temp[wordI][charI];
							++charI;
						}
						listPointer[wordI][charI] = '\0';

						// Deallocate memory for temp array
						::operator delete(temp[wordI]);
					}
				}

				// Preallocate memory for 10 characters
				listPointer[wordIndex] = (char*)::operator new(wordSize * sizeof(char));

				// Creating a word that only has '\0', this word will denote the end of the list
				listPointer[wordIndex][0] = '\0';
				
				extractionDone = true;
				redo = false;
			}
			else {
				cout << "One or more of your input words are not all alphabets. Please try again.\n\n";
				// Clear the buffer
				bool newlineFound = false;
				while (!newlineFound) {
					cin.get(input);
					if (input == '\n') {
						newlineFound = true;
					}
				}

				// Clear storage here
				if (charIndex != 0) {
					for (int wordI = 0; wordI < wordIndex; ++wordI) {
						::operator delete(listPointer[wordI]);
					}
				}
				::operator delete(listPointer);
				
				extractionDone = true;
			}

		}//while(!extractionDone)
	}//while(redo)

	cout << endl << "Listing out words in the storage before sorting: " << endl;
	for (int wordIndex = 0; listPointer[wordIndex][0] != '\0'; ++wordIndex) {
		for (int charIndex = 0; listPointer[wordIndex][charIndex] != '\0'; ++charIndex) {
			cout << listPointer[wordIndex][charIndex];
		}
		cout << " ";
	}
	cout << endl;

	int numString = 0;
	int wordI = 0;
	while (listPointer[wordI][0] != '\0') {
		++numString;
		++wordI;
	}
	cout << endl << "Number of words: " << numString << endl;

	// Bubble sort
	for (int endIndex = numString - 1; endIndex > 0; --endIndex) {

		char* temp;

		for (int curIndex = 0; curIndex < endIndex; ++curIndex) {

			int charI = 0;
			bool compareDone = false;
			while (!compareDone) {
				// Since we cannot compare lowercase and uppercase letters using the inequality operator,
				// we have to change the letters to a standard, either lowercase or uppercase.
				// The uppercase standard will be used.
				// The values are copied for comparison because I want to preserve the original values.
				char curChar, bubbleChar;

				if (listPointer[curIndex][charI] >= 97) {
					curChar = listPointer[curIndex][charI] - 32;
				}
				else {
					curChar = listPointer[curIndex][charI];
				}

				if (listPointer[curIndex + 1][charI] >= 97) {
					bubbleChar = listPointer[curIndex + 1][charI] - 32;
				}
				else {
					bubbleChar = listPointer[curIndex + 1][charI];
				}

				// Compare
				// Case 1: equal
				if (curChar == bubbleChar) {
					if (curChar == '\0') {
						compareDone = true;
					}
					else {
						++charI;
					}
				}// Case 2: not equal
				else {
					if (curChar > bubbleChar) {
						temp = listPointer[curIndex + 1];
						listPointer[curIndex + 1] = listPointer[curIndex];
						listPointer[curIndex] = temp;
						compareDone = true;
					}
					else if (curChar == '\0') {
						compareDone = true;
					}
					else if (bubbleChar == '\0') {
						temp = listPointer[curIndex + 1];
						listPointer[curIndex + 1] = listPointer[curIndex];
						listPointer[curIndex] = temp;
						compareDone = true;
					}
					else {
						compareDone = true;
					}
				}
			}
		}
	}
	
	cout << endl << "Sorted words in ascending order: " << endl;
	for (int wordIndex = 0; listPointer[wordIndex][0] != '\0'; ++wordIndex) {
		for (int charIndex = 0; listPointer[wordIndex][charIndex] != '\0'; ++charIndex) {
			cout << listPointer[wordIndex][charIndex];
		}
		cout << " ";
	}
	cout << endl;
}//main()