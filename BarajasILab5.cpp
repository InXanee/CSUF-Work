//Author: Ismael Barajas
//CPSC 121 Lab 5
//2/29/2016
#include <iostream>
#include <string>
using namespace std;


struct Students {
	string firstName;
	string lastName;
	double assignments[10];
};

const int NUM_STUDENTS = 10;
Students studList[NUM_STUDENTS];
int studentCounter = 0;
int assignmentCounter = 0;
int main();

void addNewStudent() {

	cout << "Adding new student in class:\n\n";
	cout << "First name: ";
	cin >> studList[studentCounter].firstName;
	cout << "\n\nLast name: ";
	cin >> studList[studentCounter].lastName;
	cout << "\n\n";
	cout << studList[studentCounter].firstName << " " << studList[studentCounter].lastName << " has been added to the Gradebook.\n";





	studentCounter++;
	system("pause");
	main();
}



int main() {

	system("cls");

	int choice;

	cout << "Please choose one of the following: " << endl;
	cout << "--------------------------------------" << endl << endl;
	cout << "1. Add a new student to the class.\n";
	cout << "2. Assign grades for new assignment.\n";
	cout << "3. Display all of the student's grades and course average.\n";
	cout << "4. List all scores for an assignment.\n";
	cout << "5. Gradebook.\n";
	cout << "6. Exit.\n\n";
	cout << "--------------->";
	cin >> choice;

	switch (choice) {
	case 1:
		addNewStudent();
		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	}

	system("pause");
	return 0;
}