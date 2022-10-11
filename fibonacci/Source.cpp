#include<iostream>
using namespace std;

int fibonacci(int num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {
	int num;
	cout << "Enter the number of elements 2-100: ";
	cin >> num;
	if (num > 0) {
		cout << "Fibonacci Series: ";
		for (int i = 0; i < num; i++) {
			cout << fibonacci(i) << " ";
		}
	}
	else if (num == 0) {
		cout << "Fibonacci Series: ";
		cout << fibonacci(0);
	}
	else {
		cout << "The number has to be positive!";
	}
	return 0;
}
