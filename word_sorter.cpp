#include <iostream>

using namespace std;

int main() {

	bool redo = true;
	while (redo) {
		// Input
		cout << "Input: " << endl;

		bool extractionDone = false;
		while (!extractionDone) {
			// Extraction
			char input;
			cin.get(input);

			// Filtering before storage
			if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
				cout << input;
			}
			else if (input == ' ' || input == '\t') {
				cout << endl;
			}
			else if (input == '\n') {
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

				cout << endl << endl;
			}
		}//while(!extractionDone)
	}//while(redo)

}//main()