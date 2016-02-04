//InXanee
#include <iostream>
using namespace std;
int main() {
	char nChars, nBlanks;
	int counter, width;
	cout << "Enter a positive odd integer, no larger than 127: ";
	cin >> width;
	//Checks if input is within parameters
	if (width < 0 || width>127) {
		cout << "Invalid integer." << endl;
	}
	else {
		//Loop thats creates a diamond shape
		for (counter = 1; counter <= width; counter += 2) {
			for (nBlanks = width; nBlanks > counter; nBlanks -= 2)
				cout << " ";
			for (nChars = 0; nChars < counter; nChars++)
				cout << "+";
			cout << endl;
		}
		for (counter = width - 2; counter >= 0; counter -= 2) {
			for (nBlanks = width; nBlanks > counter; nBlanks -= 2)
				cout << " ";
			for (nChars = 0; nChars < counter; nChars++)
				cout << "+";
			cout << endl;
		}
	}
	system("pause");
	return 0;
}
