#include<iostream>
using namespace std;

bool isTeenager(int);
int main() {
	int age;
	cout << "Give me a person age? : ";
	cin >> age;
	if (isTeenager(age))
		cout << "A person is a teenager";
	else
		cout << "A person is not a teenager";
	return 0;
}

bool isTeenager(int age) {
	bool status;
	if (age > 13 && age < 19)
		status = true;
	else
		status = false;
	return status;
}

