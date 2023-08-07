#include <iostream>

using namespace std;

int main() {

	bool redo = true;
	while (redo) {
		// Input
		cout << "Input: " << endl;

		bool isSpace = false;
		bool extractionDone = false;
		while (!extractionDone) {
			// Extraction
			char input;
			cin.get(input);

			// Filtering before storage
			if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
				if (isSpace) {
					cout << "There's a space before this char" << endl;
					// Add word to list
				}
				else {
					cout << "There's not a space before this char" << endl;
					// Continue adding characters
				}
				isSpace = false;
			}
			else if (input == ' ' || input == '\t') {
				if (isSpace) {
					cout << "There is a space before this space" << endl;
					isSpace = true;
					// Do nothing
				}
				else {
					cout << "There is a letter before this space" << endl;
					isSpace = true;
					// End of word, add \0 to the character array
				}
			}
			else if (input == '\n') {
				extractionDone = true;
				redo = false;
			}
			else  {
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

}//main()