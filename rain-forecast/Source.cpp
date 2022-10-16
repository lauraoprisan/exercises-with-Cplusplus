#include <iostream>
#include<string>
using namespace std;

void printStar(int[], int);

int main() {
	const int SIZE = 12;
	int monthlyRain[SIZE], i;
	for (i = 0; i < SIZE; i++) {
		cout << "input amount of rain: ";
		cin >> monthlyRain[i];
	}
	printStar(monthlyRain, SIZE);
	return 0;
}
void printStar(int amount[], int size) {
	int val, n;
	string stars;
	for (int index = 0; index < size; index++) {

		val = amount[index];
		stars = "";
		for (n = 1; n <= val; n++) {
			stars += "*";
		}
		cout << stars << endl;
	}
}


