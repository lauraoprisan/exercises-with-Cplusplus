#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct RoomInfo {
	int number;
	bool availability = true;
	int price = 100;
};


void CheckAvailability(int);
void welcomeMessage();

int main() {
	const int NUM_ROOMS = 40;
	RoomInfo rooms[NUM_ROOMS];
	int index;
	int roomNum, numOfNights;
	string choice;

	for (index = 0; index < NUM_ROOMS; index++) {         //assigning numbers to the rooms
		rooms[index].number = index + 1;
	}

	void welcomeMessage();

	start:

	cout << "Insert room number: "<<endl;
	cin >> roomNum;

	CheckAvailability(roomNum);

	cout << "How many nights do you want to stay?" << endl;
	cin >> numOfNights;
	cout << "The price for the stay is : " << numOfNights * 100 << " Euro"<< endl;
	cout << "Do you want to book another room? yes/no" << endl;
	cin >> choice;
	if (choice == "yes") {
		goto start;
	}
	else return 0;

	return 0;
}

void welcomeMessage() {
	cout << "Welcome to our hotel!" << endl;
}

void CheckAvailability(int num) {

	if(rooms[num - 1].availability == true) {
		cout << "You have booked room number " << num <<endl;
		rooms[num - 1].availability = false;
	}
	else if(rooms[num - 1].availability == false) {
		cout << "The room you chose is not available. Please select another room!" << endl;
		cout << "Insert room number: ";
		cin >> num;
		CheckAvailability(num);
	}
}





/*
#include <iostream>
#include <iomanip>
using namespace std;

struct RoomInfo {
	int number;
	bool availability = true;
	int price = 100;
};

void CheckAvailability(int);

int main() {
	const int NUM_ROOMS = 40;
	RoomInfo rooms[NUM_ROOMS];
	int index;
	int num;

	for (index = 0; index < NUM_ROOMS; index++) {
		rooms[index].number = index + 1;
	}

	cout << "Insert room number: ";
	cin >> num;
	CheckAvailability(num);


	return 0;
}

void CheckAvailability(int num) {
	if(rooms[num - 1].availability == true) {
		cout << "You have booked room number " << num;
		rooms[num - 1].availability = false;
	}
	else if(rooms[num - 1].availability == false) {
		cout << "The room you chose is not available. Please select another room!" << endl;
		cout << "Insert room number: ";
		cin >> num;
		CheckAvailability(num);
	}
}
*/