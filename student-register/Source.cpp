#include <iostream>
using namespace std;


//declaring of struct
struct Student {
	string firstName;
	string lastName;
	string studentNumber;
	int credits;
};

int main() {
	//initiliazing a structure, asking the user for struct stud values
	Student stud;
	cout << "Enter first name: ";
	cin >> stud.firstName;
	cout << endl;
	cout << "Enter last name: ";
	cin >> stud.lastName;
	cout << endl;
	cout << "Enter student number: ";
	cin >> stud.studentNumber;
	cout << endl;
	cout << "Enter student's credits: ";
	cin >> stud.credits;
	cout << endl;

	//info output
	cout << "Student's info: \n"<<endl;
	cout << "First Name: " << stud.firstName<<endl;
	cout << "Last Name: " << stud.lastName<<endl;
	cout << "Student Number: " << stud.studentNumber<<endl;
	cout << "Student Credits: " << stud.credits;
	return 0;
}
