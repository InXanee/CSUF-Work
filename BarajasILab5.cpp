//Author: Ismael Barajas
//CPSC 121 Lab 5
//2/29/2016

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Struct for Students 
struct Students {
	string firstName;
	string lastName;
	double assignments[10];
};

//Global variables
const int NUM_STUDENTS = 10; //Secures struct array
Students studList[NUM_STUDENTS]; //Initializes struct Students name with array size  
int studentCounter = 0; //Tracks total students 
int assignmentCounter = 0; //Tracks total assignments
int main();
void gradesForNewAssign();

//Checks if student already exists in the Gradebook
bool studentExists(string firstName) {

	bool found = false;

	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (studList[i].firstName == firstName)
			found = true;
	}

	return found;
}

//When assignments already exist 
void assignmentsNew(int studentNum) {

	cout << "Enter assignment/s score. \n";

	//Loops through assignment scores 
	for (int i = 0; i < assignmentCounter; i++)
	{

		cout << "\tAssignment #" << i << ": ";
		cin >> studList[studentNum].assignments[i];
	}
	system("pause");

}

//Assigns scores to each student for new assignment in the gradebook
void gradesForNewAssign()
{
	system("cls");

	//Checks if assignment cap has been reached 
	if (assignmentCounter > 9)
	{
		cout << "\n\tERROR: Assignment size has been reached.\n\n";
		system("pause");
		return;
	}

	if (studentCounter != 0)
	{
		for (int i = 0; i < studentCounter; i++)
		{
			cout << "Enter new assignment/s score for: " << studList[i].firstName << " " << studList[i].lastName << endl << endl;
			cout << "Score: ";
			cin >> studList[i].assignments[assignmentCounter];
			cout << "\n";
		}
		assignmentCounter++;
	}
	else
	{
		cout << "There are no students in the Gradebook, first add a new student please.\n";
	}
	system("pause");
}

//Function adds new student to the gradebook
void addNewStudent() {

	system("cls");

	//Checks if student cap has been reached 
	if (studentCounter>9) {
		cout << "\n\tERROR: Class size has reached its limit.\n\n";
		system("pause");
		return;
	}

	string firstNameCheck, lastName; 

	cout << "Adding new student in class:\n\n";
	cout << "First name: ";
	cin >> firstNameCheck;
	cout << "\nLast name: ";
	cin >> lastName;
	cout << "\n";

	//Checks if student already exists
	if (studentExists(firstNameCheck)) {
		cout << "Student already exists in database." << endl << endl;
	}
	else {
		//New student's name is saved
		studList[studentCounter].firstName = firstNameCheck;
		studList[studentCounter].lastName = lastName;

		cout << studList[studentCounter].firstName << " " << studList[studentCounter].lastName << " has been added to the Gradebook.\n\n";

		studentCounter++;

	}

	//If assignments already exist, user is prompt for new student's scores 
	if (assignmentCounter != 0) {
		cout << "Assignments already exists, please enter scores for the new student. \n";
		assignmentsNew(studentCounter);
	}

	system("pause");
}

//Function dispays one students grades and course average
void studGrCrseAvrg() {

	system("cls");

	string  f_Name;
	int z = 45, x = 99; //Throw away values, just used for name search verification
	double average = 0;

	//Searches for student's name through the struct
	if (studentCounter != 0)
	{
		cout << "Enter the student's first name: ";
		cin >> f_Name;

		//Makes z == x, if name is found
		for (int i = 0; i <= studentCounter; i++)
		{
			if (studList[i].firstName == f_Name)
			{
				z = i; 
				x = i;
				break;
			}
		}

		if (z == x) //Here it is in action (Makes z == x, if name is found).
		{
			if (assignmentCounter != 0)
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
				cout << "\nThere are no assignments in the Gradebook for " << f_Name << ", first add a new assignment please.\n\n";
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

//Function lists all scores for an assignment and its class average
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

//Function displays the whole gradebook
void displayGradebook()
{
	system("cls");

	if (studentCounter != 0)
	{
		cout << "Students---------Assignment Scores-----------\n\n";
		for (int i = 0; i < studentCounter; i++)
		{
			cout << studList[i].firstName << " " << studList[i].lastName << " ";
			for (int z = 0; z < assignmentCounter; z++)
			{
				cout << studList[i].assignments[z] << " ";
			}
			cout << "\n\n";
		}
		system("pause");

	}
	else
	{
		cout << "There are no students in the Gradebook, please enter a new student first.\n\n";
		system("pause");
	}
}

//Function saves new data into scores.txt 
void save()
{

	ofstream scores("scores.txt");

	//Checks if file was able to be created
	if (!scores)
	{
		cout << "ERROR: Failed to create file." << endl;
		cout << endl;
		system("pause");
		return;
	}

	//Inputs all data into scores.txt
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
	cout << "\n\tData has been saved.\n\n";
	system("pause");
}

//Function loads data from past scores.txt
void load()
{
	string option;

	//Gives user option to load in past data
	cout << "Would you like to load from \"scores.txt\"? [y/n] ";
	cin >> option;

	//Checks for valid input
	if (cin.fail()) 
	{
		cin.clear();
		cin.ignore(999, '\n');
		system("cls");
		cout << "ERROR: Invalid input.\n\n";
		system("pause");
		main();
	}

	//Proceeds to load in data if argument is satisfied 
	if (option=="y") 
	{

		ifstream inFile;
		inFile.open("scores.txt");

		if (!inFile)
		{
			cout << "ERROR: Failed to open File." << endl;
			cout << endl;
			system("pause");
			return;
		}

		inFile >> studentCounter >> assignmentCounter; //First two values frome file are used as parameters

		//Loads in data to Student struct
		for (int z = 0; z < studentCounter; z++)
		{
			inFile >> studList[z].firstName >> studList[z].lastName;
			for (int i = 0; i < assignmentCounter; i++)
			{
				inFile >> studList[z].assignments[i];
			}
		}

		cout << "\tFile has been successfully loaded!" << endl << endl;
		system("pause");
	}
}

//Main Function
int main() {

	int choice;
	load(); //Calls load() function

	//Menu loop
	do {

		system("cls");
		//Menu interface 
		cout << "Please choose one of the following: " << endl;
		cout << "------------------------------------------------------------------" << endl << endl;
		cout << " |\t1. Add a new student to the Gradebook.\n";
		cout << " |\t2. Assign grades for new assignment.\n";
		cout << " |\t3. Display one student's grades and course average.\n";
		cout << " |\t4. List all scores for an assignment and its class average.\n";
		cout << " |\t5. View whole Gradebook.\n";
		cout << " |\t6. Save current Data. \n";
		cout << " |\t7. Exit.\n\n";
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
				addNewStudent();
				break;
			case 2:
				gradesForNewAssign();
				break;
			case 3:
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