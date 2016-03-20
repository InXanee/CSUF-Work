//Author: Ismael Barajas
//CPSC 121 Lab 6
//3/19/2016

#include <iostream>
#include <algorithm>

using namespace std;
bool arrayHasValues = false; //A check for values in the array

//Function fills array with 10 intengers
void fillArray(int *arry) {
	cout << "Please enter 10 integer values:" << endl;
	for (int i = 0;i < 10;i++)
	{
		cout << "Value #" << i << " : ";
		cin >> arry[i];
	}
	arrayHasValues = true; //When true, functions are unlocked and allowed to work.
	cout << endl;
}

//Displays what is currently in the array
void displayArray(int *arry) {
	if (arrayHasValues == true) { //Checks for values in array
		cout << endl << "Current values within the array:" << endl;
		for (int i = 0; i < 10; i++) //Loop displays what is inside the array
		{
			cout << "Value #" << i << " : " << arry[i] << endl;
		}
		cout << endl;
	}
	else //Output if there are no values in the array
	{
		cout << endl << "There are currently no values in the array, please enter values into the array." << endl;
	}
}

//Function uses Bubble sorting to sort array
void bubbleSort(int *arry) {
	int temp = 0;
	bool swap = true; //Bool that checks if swaps occured
	if (arrayHasValues == true) {
		do {
			for (int i = 0; i < 9; i++) {
				swap = false; //Defaults to false then loops again, if no change exits if its the last iteration of the loop 
				for (int z = 0; z < 9; z++) {
					if (arry[z] > arry[z + 1]) // Checks if value arry[z] is greater than value arry[z+1], if so values are swtiched
					{
						temp = arry[z];
						arry[z] = arry[z + 1];
						arry[z + 1] = temp;
						swap = true; //A swap has occured loop may continue 
					}
				}
			}
		} while (swap == true); //Loop that continues if swaps have occured in the last iteration of the for loop
	}
	else
	{
		cout << endl << "There are currently no values in the array, please enter values into the array." << endl;
	}
}

//Funtion uses Selective sorting to sort the array
void selectSort(int *arry) {
	int min, temp; 
	if (arrayHasValues == true) {
		for (int i = 0; i < 9; i++) 
		{
			min = i; //Sets min value to the first value of the array of i
			for (int z = i + 1; z < 10; z++)
			{
				if (arry[z] < arry[min]) //Checks if arry[z] is less than arry[min] which is i
				{
					min = z; //If so min is set to z, the new lowest value
				}
			}
			if (min != i) //If min was changed to z at any point, then the values are switched
			{
				temp = arry[i];
				arry[i] = arry[min];
				arry[min] = temp;
			}
		}
	}
	else
	{
		cout << endl << "There are currently no values in the array, please enter values into the array." << endl;
	}
}

int main() {

	int choice;
	int mainArry[10];

	//Menu loop
	do {
		//Menu interface 
		cout << "Please choose one of the following: " << endl;
		cout << "------------------------------------------------------------------" << endl << endl;
		cout << " |\t1. Fill array with user input.\n";
		cout << " |\t2. Display array.\n";
		cout << " |\t3. Shuffle elements in your array randomly.\n";
		cout << " |\t4. Sort array using Bubble sort.\n";
		cout << " |\t5. Sort array using Selection sort.\n";
		cout << " |\t6. Exit. \n\n";
		cout << "---------------> ";
		cin >> choice;

		//Checks if 'choice' is a valid input
		if (cin.fail()) {
			cin.clear();
			cin.ignore(999, '\n');
			system("cls");
			cout << "ERROR: Invalid input.\n\n";
			system("pause");
		}
		//Switch statement for menu
		else {
			switch (choice) {
			case 1:
				fillArray(mainArry);
				break;
			case 2:
				displayArray(mainArry);
				break;
			case 3:
				if (arrayHasValues == true) 
				{
					random_shuffle(begin(mainArry), end(mainArry)); //Shuffles values in the array 
				}
				else
				{
					cout << endl << "There are currently no values in the array, please enter values into the array." << endl;
				}
				break;
			case 4:
				bubbleSort(mainArry);
				break;
			case 5:
				selectSort(mainArry);
				break;
			case 6:
				return 0;
				break;
			default:
				system("cls");
				cout << "Please enter a valid integer thats within the scope." << endl;
				choice = 8; //Makes sure 'choice' value isn't 9, which would force program to exit prematurely
				system("pause");
			}
		}
	} while (choice != 9);
	system("pause");
	return 0;
}