//Author: Ismael Barajas
//CPSC 121 Lab 5
//2/29/2016


//still need to find out the assignment counter situation


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
void gradesForNewAssign();

bool studentExists(string firstName) {
	bool found = false;

	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (studList[i].firstName == firstName)
			found = true;
	}

	return found;
}

void assignmentsNew(int studentNum) {

	cout << "Enter assignment/s score. \n";

	for (int i = 0; i < assignmentCounter; i++) {

		cout << "\tAssignment #" << i << ": ";
		cin >> studList[studentNum].assignments[i];
	}
	system("pause");

}

void gradesForNewAssign()
{
	system("cls");

	if (studentCounter != 0)
	{
		for (int i = 0; i <= studentCounter; i++)
		{
			cout << "Enter new assignment/s score for: " << studList[i].firstName << " " << studList[i].lastName << endl << endl;
			cout << "\Score: ";
			cin >> studList[i].assignments[assignmentCounter];
		}
		assignmentCounter++;
	}
	else
	{
		cout << "There are no students in the Gradebook, first add a new student please.\n";
	}
	system("pause");
}


void addNewStudent() {

	system("cls");

	string firstNameCheck, lastNameCheck;

	cout << "Adding new student in class:\n\n";
	cout << "First name: ";
	cin >> firstNameCheck;
	cout << "\nLast name: ";
	cin >> lastNameCheck;
	cout << "\n";

	if (studentExists(firstNameCheck)) {
		cout << "Student already exists in database." << endl << endl;
	}
	else {
		studList[studentCounter].firstName = firstNameCheck;
		studList[studentCounter].lastName = lastNameCheck;

		cout << studList[studentCounter].firstName << " " << studList[studentCounter].lastName << " has been added to the Gradebook.\n\n";

		studentCounter++;

	}


	if (assignmentCounter != 0) {

		cout << "Assignments already exists, please enter scores for the new student. \n";
		assignmentsNew(studentCounter);
	}

	system("pause");
}



int main() {

	system("cls");

	int choice;

	do {

		system("cls");

		cout << "Please choose one of the following: " << endl;
		cout << "--------------------------------------" << endl << endl;
		cout << "\t1. Add a new student to the Gradebook.\n";
		cout << "\t2. Assign grades for new assignment.\n";
		cout << "\t3. Display all of the student's grades and course average.\n";
		cout << "\t4. List all scores for an assignment.\n";
		cout << "\t5. Gradebook.\n";
		cout << "\t6. Exit.\n\n";
		cout << "---------------> ";
		cin >> choice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(999, '\n');
			system("cls");
			cout << "ERROR: Invalid input.\n\n";
			system("pause");

		}
		else {
			switch (choice) {
			case 1:
				addNewStudent();
				break;
			case 2:
				gradesForNewAssign();
				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:
				return 0;
				break;
			default:
				system("cls");
				cout << "Please enter a valid integer thats within the scope." << endl;
				system("pause");
			}
		}
	} while (choice != 7);

	system("pause");
	return 0;
}