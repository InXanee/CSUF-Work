//Author: Ismael Barajas
//CPSC 121 Lab 4
//2/22/2016
#include <iostream>
using namespace std;

//global constants and prototypes
int arry[5];
int main();
void menu();
void sum();
void displayAll();
void mean();
void edit();

//Menu Prompt
void menu() {

	system("cls");

	int choice;

	cout << "Please choose an option: " << endl;
	cout << "---------------------------" << endl << endl;
	cout << "1. Sum" << endl;
	cout << "2. Mean" << endl;
	cout << "3. Display" << endl;
	cout << "4. Edit" << endl;
	cout << "5. Exit" << endl << endl;
	cout << "----------->";
	cin >> choice;
	cout << endl << endl;

	//Switch statement that calls for the Function that is chosen
		switch (choice) {
		case 1:
			sum();
			break;
		case 2:
			mean();
			break;
		case 3:
			displayAll();
			break;
		case 4:
			edit();
			break;
		case 5:
			system("pause");
			break;
		default:
			system("cls");
			cout << "Please enter a valid option." << endl << endl;
			system("pause");
			menu();
		}
	}


//Sums all the values in the array, then out puts the value of the total.
void sum() {
	system("cls");
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += arry[i];
	}

	cout << "Total sum of array: " << total << endl;
	system("pause");
	menu();

}

//Takes new values for the array when called for.
void arrry() {
	system("cls");
	cout << "Please enter 5 integer values: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Value " << i << ":";
		cin >> arry[i];
	}
	cout << endl;
	menu();
}

//Displays all the current values in the array.
void displayAll() {
	system("cls");
	cout << "Current values in Array: " << endl << endl;
	for (int i = 0; i < 5; i++) {

		cout << "Value " << i << ":";
		cout << arry[i] << endl;
	}
	system("pause");
	menu();
}

//Out puts the mean the the values in the array.
void mean() {
	system("cls");
	int total = 0, mean;
	for (int i = 0; i < 5; i++) {
		total += arry[i];
	}

	mean = total / 5;
	cout << "The mean is: " << mean << endl;
	system("pause");
	menu();

}

//Calls for the arrry() function.
void edit() {

	arrry();
}

//Useless main function
int main() {

	arrry();

	return 0;
}
