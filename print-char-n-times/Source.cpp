#include<iostream>
using namespace std;

void printCharacterNtimes(char, int);
int main() {
	
	int n;
	char letter;
	cout << "How many characters are printed?";
	cin >> n;
	cout << "What character is printed?";
	cin >> letter;
	printCharacterNtimes(letter, n);
	return 0;
}

void printCharacterNtimes(char forPrint, int num) {
	cout << "Character " << forPrint << " printed " << num << " times." << endl;
	for (int i = 1; i <= num; i++) {
		cout << forPrint;
	}
}
