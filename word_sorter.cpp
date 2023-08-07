#include <iostream>

using namespace std;

int main() {

	bool extractionDone = false;
	while (!extractionDone) {
		// Extraction
		char input;
		cin.get(input);

		// Filtering before storage
		if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
			cout << "Input is alphabet" << endl;
		}
		else if (input == ' ' || input == '\t') {
			cout << "Input is space or tab" << endl;
		}
		else if (input == '\n') {
			extractionDone = true;
			cout << "Input is newline" << endl;
		}
		else {
			cout << "Input is not alphabet or space or newline" << endl;
		}
	}
}