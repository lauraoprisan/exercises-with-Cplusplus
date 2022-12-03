#include<iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int SIZEBONUS = 3;
const int SIZEMAIN = 7;

void displayMenu();
void showPrices();
void showNumbers(int[], int);
void machineDrawn(int[], int[], int, int);
int winCheckAndPrint(int[], int[], int[], int[], int size1, int size2);


int main() {

	int mainLottery[SIZEMAIN], bonusLottery[SIZEBONUS], winningMainNumbers[SIZEMAIN], winningBonusNumbers[SIZEBONUS];
	int choice;
	cout << "Welcome to the easy lottery, winning is easy!" << endl;

	start:

	displayMenu();
	cin >> choice;
	switch (choice) {
	case 1:
	{
		showPrices();
		break;
	}
	case 2:
	{
		machineDrawn(mainLottery, bonusLottery, SIZEMAIN, SIZEBONUS);
		winCheckAndPrint(mainLottery, bonusLottery, winningMainNumbers, winningBonusNumbers, SIZEMAIN, SIZEBONUS);
		goto start;
		break;

	}
	case 4:
	{
		return 0;
	}

	}
	return 0;
}

void displayMenu() {
	cout << "What would you like to do? (Enter numbers 1-4)" << endl;
	cout << "1: See prize amounts" << endl;
	cout << "2: Play on the line drawn by the machine" << endl;
	cout << "3: Play with your own numbers" << endl;
	cout << "4: Stop playing" << endl;

}

void showPrices() {
	cout << "Numbers + additional numbers correctly Winning amount" << endl;
	cout << "7 10 000 000 e" << endl;
	cout << "6+1 1,000,000 e" << endl;
	cout << "6,100,000 e" << endl;
	cout << "5 2000 e" << endl;
	cout << "4 50 e" << endl;
	cout << "3+1 10 e" << endl;
	cout << "2 2 e" << endl;
	cout << "1 1 e" << endl;
	cout << "-------------------------------------------------- ------------------------------" << endl;
}


void showNumbers(int numArray[], int size) {
	for (int i = 0; i < size; i++) {
		if (i < (size - 1)) {
			cout << numArray[i] << ", ";
		}
		else {
			cout << numArray[i];
		}

	}
}

void machineDrawn(int mainArr[], int bonusArr[], int size1, int size2) {
	for (int i = 0; i < size1; i++) {
		mainArr[i] = rand() % 49 + 1;
	};
	for (int i = 0; i < size2; i++) {
		bonusArr[i] = rand() % 49 + 1;
	};
	//cout << "Your lottery numbers are: " << showNumbers(mainArr, size1) << ", " << "and extra numbers are: " << showNumbers(bonusArr, size2) << "." << endl;
	cout << "Your lottery numbers are: " << mainArr[0] << ", " << mainArr[1] << ", " << mainArr[2] << ", " << mainArr[3] << ", " << mainArr[4] << ", " << mainArr[5] << ", " << mainArr[6] << ", and bonus points are: " << bonusArr[0]<<", " << bonusArr[1] << ", " << bonusArr[2] << "." <<endl;
}

int winCheckAndPrint(int mainArrayToCheck[], int bonusArrayToCheck[], int winningMainNumbers[], int winningBonusNumers[], int size1, int size2) {
	int matchesMain = 0, matchesBonus = 0;

	for (int i = 0; i < size1; i++) {
		winningMainNumbers[i] = rand() % 49 + 1;
	}
	for (int i = 0; i < size2; i++) {
		winningBonusNumers[i] = rand() % 49 + 1;
	}
	//displaying the winning numbers
	//cout << "Your lottery numbers are: " << showNumbers(winningMainNumbers, size1) << ", " << "and extra numbers are: " << showNumbers(winningBonusNumers, size2) << "." << endl;
	cout << "The winning  numbers are: " << winningMainNumbers[0] << ", " << winningMainNumbers[1] << ", " << winningMainNumbers[2] << ", " << winningMainNumbers[3] << ", " << winningMainNumbers[4] << ", " << winningMainNumbers[5] << ", " << winningMainNumbers[6] << ", and bonus points are: " << winningBonusNumers[0] << ", " << winningBonusNumers[1] << ", " << winningBonusNumers[2] << "." << endl;

	//comparing the main numbers

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++) {
			if (mainArrayToCheck[i] == winningMainNumbers[j]) {
				matchesMain++;
			}
		}
	}
	for (int i = 0; i < size2; i++) {
		for (int j = 0; j < size2; j++) {
			if (bonusArrayToCheck[i] == winningBonusNumers[j]) {
				matchesBonus++;
			}
		}
	}

	if (matchesBonus == 0) {
		cout << "You got " << matchesMain << " right!" << endl;
	}
	else {
		cout << "You got " << matchesMain << "+" << matchesBonus << " right!" << endl;
	}


	if (matchesBonus == 0 && matchesMain > 0) {
		switch (matchesMain) {
		case 1: {
			cout << "You won 1 euro!";
			break;
		}
		case 2: {
			cout << "You won 2 euros!";
			break;
		}
		case 4: {
			cout << "You won 50 euros!";
			break;
		}
		case 5: {
			cout << "You won 2000 euros!";
			break;
		}
		case 6: {
			if (matchesBonus == 0) {
				cout << "You won 100,000 euros!";
				break;
			}
		}
		case 7: {
			cout << "You won 10 000 000 euros!";
			break;
		}
		}
	}
	else if (matchesBonus > 0 && matchesMain > 0) {
		if (matchesBonus == 3) {
			cout << "You won 10 euros!";
		}
		else if (matchesBonus == 6) {
			cout << "You won 1,000,000 euros!";
		}
	}
	return 0;
}

