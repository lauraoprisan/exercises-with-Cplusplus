#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct RoomInfo {
	int number;
	bool availability = true;
	int price = 100;
};


void CheckAvailabilityAndBook(int, RoomInfo[]);
void welcomeMessage(string);
int askForRoom();

int main() {
	const int NUM_ROOMS = 40;
	RoomInfo rooms[NUM_ROOMS];
	int index;
	int numOfNights;
	string choice;

	for (index = 0; index < NUM_ROOMS; index++) {         //assigning numbers to the rooms
		rooms[index].number = index + 1;
	}

	cout << "Welcome to our hotel!" << endl<<endl;

	start:

	CheckAvailabilityAndBook(askForRoom(), rooms);

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


void CheckAvailabilityAndBook(int num, RoomInfo rooms[]) {
	int newNum;
	if(rooms[num - 1].availability == true) {
		cout << "You have booked room number " << num <<"."<<endl;
		rooms[num - 1].availability = false;
	}
	else if(rooms[num - 1].availability == false) {
		cout << "The room you chose is not available. Please select another room!" << endl;
		cout << "Insert room number: "<<endl;
		cin >> newNum;
		CheckAvailabilityAndBook(newNum,rooms);
	}
}


int askForRoom() {
	int roomNum;
	cout << "Insert a room number between 1 and 40: ";
	cin >> roomNum;
	while (roomNum < 0 || roomNum>40) {
		cout << "Your number room does not exist. Insert a room number between 1 and 40, please! " << endl;
		cin >> roomNum;
	}
	return roomNum;
}