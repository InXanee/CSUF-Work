//Author: Ismael Barajas
//CPSC 121 Lab 2
//2/1/2016
#include <iostream>
using namespace std;
int main() {
//Initalizes the constant valuse in the loop
	char repeat,operater;
	int lefthandoperand, righthandoperand;
	cout << "Please enter a left hand operand: ";
	cin >> lefthandoperand;
	do {
		int result;

		cout << endl << "Now, please choose a operator you would like to use: + - / * % \n";
		cin >> operater;

		cout << endl << "Please enter a right hand operand: ";
		cin >> righthandoperand;
//Switch operand uses user input to calculate their result.
		switch (operater) {
		case '+':
			result = lefthandoperand + righthandoperand;
			break;
		case '-':	
			result = lefthandoperand - righthandoperand;
			break;
		case '/':	
			if (righthandoperand == 0) {
				cout << "Undefinded";
				result = 0;
			}
			else
				result = lefthandoperand / righthandoperand;
			break;
		case '*':	
			result = lefthandoperand * righthandoperand;
			break;
		case '%':	
			result = lefthandoperand % righthandoperand;
			break;
		default:
			cout << "You must enter a valid operand.";
			break;
		}
//Makes lefthandoperand == result 
		lefthandoperand = result;
		cout << endl << "Answer: " << lefthandoperand << endl
			<< "Would you like to continue? [Y/N]\n";
		cin >> repeat;
//Repeats the loop with previous answer as the lefthandoperand
	} while (repeat=='Y');
	
	system("PAUSE");
	return 0;
}