#include <iostream>

using namespace std;

int main() {
    char input;
    cout << "Enter some text: ";

    while (true) {
        cin.get(input);
        if (cin.eof()) {
            cout << "End of input reached." << endl;
            break;
        }
        else if (cin.fail()) {
            cout << "Input failed for some other reason." << endl;
            break;
        }
        else {
            cout << "You entered: " << input << endl;
        }
    }

    return 0;
}