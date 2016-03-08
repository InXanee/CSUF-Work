//Author: Ismael Barajas
//CPSC 121 Lab 5
//2/29/2016


//still need to find out the assignment counter situation


#include <iostream>
#include <string>
<<<<<<< HEAD
#include <fstream>
=======
>>>>>>> origin/master
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

<<<<<<< HEAD

=======
>>>>>>> origin/master
void assignmentsNew(int studentNum) {

	cout << "Enter assignment/s score. \n";

<<<<<<< HEAD
	for (int i = 0; i < assignmentCounter; i++) 
	{
=======
	for (int i = 0; i < assignmentCounter; i++) {
>>>>>>> origin/master

		cout << "\tAssignment #" << i << ": ";
		cin >> studList[studentNum].assignments[i];
	}
	system("pause");

}

<<<<<<< HEAD

=======
>>>>>>> origin/master
void gradesForNewAssign()
{
	system("cls");

	if (studentCounter != 0)
	{
<<<<<<< HEAD
		for (int i = 0; i < studentCounter; i++)
		{
			cout << "Enter new assignment/s score for: " << studList[i].firstName << " " << studList[i].lastName << endl << endl;
			cout << "Score: ";
			cin >> studList[i].assignments[assignmentCounter];
			cout << "\n";
=======
		for (int i = 0; i <= studentCounter; i++)
		{
			cout << "Enter new assignment/s score for: " << studList[i].firstName << " " << studList[i].lastName << endl << endl;
			cout << "\Score: ";
			cin >> studList[i].assignments[assignmentCounter];
>>>>>>> origin/master
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
<<<<<<< HEAD

			studList[studentCounter].firstName = firstNameCheck;
			studList[studentCounter].lastName = lastNameCheck;

			cout << studList[studentCounter].firstName << " " << studList[studentCounter].lastName << " has been added to the Gradebook.\n\n";

			studentCounter++;

	}

=======
		studList[studentCounter].firstName = firstNameCheck;
		studList[studentCounter].lastName = lastNameCheck;

		cout << studList[studentCounter].firstName << " " << studList[studentCounter].lastName << " has been added to the Gradebook.\n\n";

		studentCounter++;

	}


>>>>>>> origin/master
	if (assignmentCounter != 0) {

		cout << "Assignments already exists, please enter scores for the new student. \n";
		assignmentsNew(studentCounter);
	}

	system("pause");
}

<<<<<<< HEAD
void studGrCrseAvrg() {

	system("cls");

	string  f_Name;
	int z = 45, x = 99;
	double average = 0;

	if (studentCounter != 0)
	{
		cout << "Enter the student's first name: ";
		cin >> f_Name;

		for (int i = 0; i <= studentCounter; i++)
		{
			if (studList[i].firstName == f_Name)
			{
				z = i;
				x = i;
				break;
			}
		}
		if (z == x)
		{
			if (assignmentCounter!=0)
			{
				cout << "Assignment scores & Course average for: " << studList[z].firstName << " " << studList[z].lastName << endl << endl;
				for (int i = 0; i < assignmentCounter; i++)
				{
					cout << "\tAssignment #" << i << ": " << studList[z].assignments[i] << endl;
					average += studList[z].assignments[i];
				}

				cout << "\nCourse average: " << average / assignmentCounter << endl << endl;
			}
			else
			{
				cout << "There are no assignments in the Gradebook for " << f_Name<< ", first add a new assignment please.\n\n";
			}
		}
		else
		{
			cout << "\"" << f_Name << "\"" << " was unable to be found.\n";
		}
	}
	else
	{
		cout << "There are no students in the Gradebook, first add a new student please.\n\n";
	}

	system("pause");
}

void scoresAndClasAvg()
{
	system("cls");
	int assignNum;
	double avrgAndTotal = 0;
	if (studentCounter != 0)
	{
		if (assignmentCounter != 0)
		{
			cout << "Please choose assignment you would like to list [# 1-10]: ";
			cin >> assignNum;

			if (assignNum < 1 || assignNum > 10 || cin.fail())
			{
				cin.clear();
				cin.ignore(999, '\n');
				system("cls");
				cout << "ERROR: Invalid input.\n\n";
				system("pause");
			}
			else
			{
				cout << "\nScores for assingment #" << assignNum << ": \n\n";
				assignNum -= 1;
				for (int i = 0; i < studentCounter; i++)
				{
					cout << "\t" << studList[i].assignments[assignNum] << endl;
					avrgAndTotal += studList[i].assignments[assignNum];
				}
				assignNum += 1;
				cout << "\nClass average for assignment #" << assignNum << ": " << avrgAndTotal / studentCounter << "\n\n";
				system("pause");
			}
		}
		else
		{
			cout << "There are no assignments in the Gradebook, please enter a new assignment first.\n\n";
			system("pause");
		}
	}
	else
	{
		cout << "There are no students in the Gradebook, please enter a new student first.\n\n";
		system("pause");
	}

}

//This is next to work on
void displayGradebook()
{




}


void save()
{
	ofstream scores("scores.txt");
	scores << studentCounter << "\n" << assignmentCounter << "\n";

	for (int i = 0; i < studentCounter; i++) 
	{
		scores << studList[i].firstName << " " << studList[i].lastName << " ";
		for (int z = 0; z < assignmentCounter; z++)
		{
			scores << studList[i].assignments[z] << " ";
		}
		scores << "\n";
	}
	system("cls");
	cout << "\n\n\tData has been saved.\n\n";
	system("pause");
}

void load() 
{









}


=======
>>>>>>> origin/master


int main() {

	system("cls");

	int choice;

	do {

		system("cls");

		cout << "Please choose one of the following: " << endl;
		cout << "--------------------------------------" << endl << endl;
		cout << "\t1. Add a new student to the Gradebook.\n";
		cout << "\t2. Assign grades for new assignment.\n";
<<<<<<< HEAD
		cout << "\t3. Display all of a student's grades and course average.\n";
		cout << "\t4. List all scores for an assignment.\n";
		cout << "\t5. View whole Gradebook.\n";//
		cout << "\t6. Save current Data. \n";
		cout << "\t7. Load past Data.\n";//
		cout << "\t8. Exit.\n\n";
=======
		cout << "\t3. Display all of the student's grades and course average.\n";
		cout << "\t4. List all scores for an assignment.\n";
		cout << "\t5. Gradebook.\n";
		cout << "\t6. Exit.\n\n";
>>>>>>> origin/master
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
<<<<<<< HEAD
				studGrCrseAvrg();
				break;
			case 4:
				scoresAndClasAvg();
				break;
			case 5:
				displayGradebook();
				break;
			case 6:
				save();
				break;
			case 7:
				load();
				break;
			case 8:
=======

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:
>>>>>>> origin/master
				return 0;
				break;
			default:
				system("cls");
				cout << "Please enter a valid integer thats within the scope." << endl;
				system("pause");
			}
		}
<<<<<<< HEAD
	} while (choice != 9);
=======
	} while (choice != 7);
>>>>>>> origin/master

	system("pause");
	return 0;
}