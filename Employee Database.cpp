#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

int main();

void input()
{
	system("cls");
	string fname;
	string mname;
	string lname;
	string filename;
	double salary;
	int emid, age;
	cout << endl << "Input first name: ";
	cin >> fname;
	cout << "Input middle name or leave blnk if none: ";
	cin >> mname;
	cout << "Input last name: ";
	cin >> lname;
	cout << "Input employee age: ";
	cin >> age;
	cout << "Input employee salary: ";
	cin >> salary;
	cout << "Employee I.D. number: ";
	cin >> emid;
	string emid2 = to_string(emid);
	emid2.append(".txt");

	ofstream newemployee(emid2);
	newemployee << fname << ' ' << mname << ' ' << lname << ' ' << age << ' ' << emid << ' ' << salary << endl;
	newemployee.close();
}

void search()
{
	system("cls");
	string fname;
	string mname;
	string lname;
	string filename;
	double salary;
	int emid, age, thrw;
	cout << "Enter employee ID number: ";
	cin >> emid;
	string emid2 = to_string(emid);
	emid2.append(".txt");

	ifstream employee(emid2);

	while (employee >> fname >> mname >> lname >> age >> thrw >> salary)
	{
		int mnamelength = mname.size();
		int lnamelength = lname.size();
		int fnamelength = fname.size();
		int lengthtotal = mnamelength + lnamelength + fnamelength;

		string answer;
		cout << "Is this the correct employee? [y/n]" << endl;
		cout << fname << ' ' << mname << ' ' << lname << endl;
		cin >> answer;

		if(answer=="y"){
			system("cls");
			cout << "Name";
			for (int y = 1; y < lengthtotal; y++) {
				cout << " ";
			}
			cout << "Age";
			for (int z = 1; z < 2; z++) {
				cout << " ";
			}
			cout << "Salary ";
			cout << "ID#" << endl;
			for (int s = 1; s < lengthtotal + 27; s++) {
				cout << "-";
			}
			cout << ' ' << endl;
			cout << fname << ' ' << mname << ' ' << lname << ' ' << age << ' ' << "$" << salary<<' ' << emid << endl;
		
		}
	}
	system("PAUSE");
	main();
}

void edit()
{

	system("cls");




}

void displayAll()
{

	system("cls");



}


int main() 
{
	system("cls");
	system("title InXanee database");
	cout << "Please enter choice: " << endl;
	cout << "1. Enter new emplooyee." << endl;
	cout << "2. Search for employee by I.D. Number." << endl;
	cout << "3. Edit an existing employee's info." << endl;
	cout << "4. Display all employees." << endl;
	cout << "5. Exit." << endl;

	int choice;
	cin >> choice;

	switch(choice){
	case 1:
		input();
		break;
	case 2:
		search();
		break;
	case 3:
		edit();
		break;
	case 4:
		displayAll();
		break;
	}

	system("PAUSE");
	return 0;
}

