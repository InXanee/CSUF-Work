#include <iostream>
using namespace std;
int main() {

	char op;
	double num1, num2, answer;
	cout << "Please enter a operator [+, -, *, / , s (s is for swap)] : ";
	cin >> op;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number:";
	cin >> num2;
	cout << endl << endl;

	//Switch statement for the operator, also does the calculation.
	switch (op) {

	    case '+':
			answer = num1 + num2;
			cout << num1 << " + " << num2 << " = " << answer << endl;
			break;

		case '-': 
			answer = num1 - num2;
			cout << num1 << " - " << num2 << " = " << answer << endl;
			break;

		case '*':
			answer = num1 * num2;
			cout << num1 << " * " << num2 << " = " << answer << endl;
			break;

		case '/':
			//Checks if user is dividing by 0.
			if (num2==0) {
				cout << "Can't divide by 0, idiot." << endl;
					break;
			}
			else {
				answer = num1 / num2;
				cout << num1 << " / " << num2 << " = " << answer << endl;
				break;
			}
		
		case's':
		//Swaps the position of both values, using swap() function.
			cout << "Swapping numbers (" << num1 << "," << num2 << "):"<<endl;
			swap(num1, num2);
			cout << "The 1st number is = " << num1 << endl << "The 2nd number is = " << num2 << endl << endl;
			break;

		default:
			cout << "Unknown operator.";
			break;
	}
	system("pause");
	return 0;
}
