//Author: Ismael Barajas
//CPSC 121 Lab 1
//2/1/2016
#include <iostream>
using namespace std;
int main() {
	char repeat;
	do {
		int cents, quarters, dimes, nickels, pennies;
		cout << "Enter Cents: ";
		cin >> cents;
		cout << endl << endl;
		

		quarters = cents / 25;
		cents -= (quarters * 25);
		dimes = cents / 10;
		cents -= (dimes * 10);
		nickels = cents / 5;
		cents -= (nickels * 5);
		pennies = cents;
		cout << "Quarters: " << quarters << endl;
		cout << "Dimes: " << dimes << endl;
		cout << "Nickels: " << nickels << endl;
		cout << "Pennies: " << pennies << endl;
		cout << "Would you like to enter another value? [Y/N]";
		cin >> repeat;
	} while (repeat=='Y');
	system("PAUSE");
	return 0;
}