//Author: Ismael Barajas
//CPSC 121 Lab 4
//2/22/2016
#include <iostream>
using namespace std;

int arry[5];
int main();
void menu();
void sum();
void displayAll();
void mean();
void edit();

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

	if (choice < 5)
	{
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
		}
	}
	else 
	{
		system("cls");
		cout << "Please enter a valid option." << endl;
		system("pause");
		menu();
	}
	}




void sum() {
	system("cls");
	int total=0;
	for (int i = 0;i < 5;i++) {
		total += arry[i];
	}

	cout << "Total sum of array: " << total << endl;
	system("pause");
	menu();

}

void arrry() {
	system("cls");
	cout << "Please enter 5 integer values: " << endl;
	for (int i = 0;i < 5;i++) {
		cout << "Value " << i << ":";
		cin >> arry[i];
	}
	cout << endl;
	menu();
}

void displayAll() {
	system("cls");
	cout << "Current values in Array: " << endl << endl;
	for (int i = 0;i < 5;i++) {

		cout << "Value " << i << ":";
		cout << arry[i] << endl;
	}
	system("pause");
	menu();
}

void mean() {
	system("cls");
	int total = 0,mean;
	for (int i = 0;i < 5;i++) {
		total += arry[i];
	}

	mean = total / 5;
	cout << "The mean is: " << mean << endl;
	system("pause");
	menu();

}

void edit() {

	arrry();
}

int main() {

	arrry();

	system("pause");
	return 0;
}