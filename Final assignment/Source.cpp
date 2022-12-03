#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

struct RoomInfo {
	int number;
	bool availability = true;
	int price;
	string roomType;
	int bookingNum;
	string name;
};



int checkAvailabilityRoomType(string, RoomInfo[], int, bool);
int askAndCheckRoomNumInput(string, int);
void CheckAvailabilityAndChooseRoom(int, RoomInfo[]);
int machineChoose(string, int, RoomInfo[]);
//void welcomeMessage(string);


int main() {
	const int NUM_ROOMS = 40;
	RoomInfo rooms[NUM_ROOMS];
	int index, menuChoice, roomChoice, roomNum=0, methodChoice;
	bool proceedBooking=true;
	//int numOfNights;
	string choice;
	string roomBed;


	for (index = 0; index < NUM_ROOMS / 2; index++) {						//assigning numbers, prices and roomTypes for single rooms
		rooms[index].number = index + 1;
		rooms[index].price = 100;
		rooms[index].roomType = "single";
	}

	for (index = (NUM_ROOMS / 2); index < NUM_ROOMS; index++) {         ///assigning numbers, prices and roomTypes for double rooms
		rooms[index].number = index + 1;
		rooms[index].price = 150;
		rooms[index].roomType = "double";
	}


	cout << "Welcome to our hotel!" << endl << endl;

start:

	cout << "Navigate the menu by choosing numbers of the options!" << endl << endl;
	cout << "1.Make a reservation" << endl;
	cout << "2.Check your reservation" << endl;
	cin >> menuChoice;
	cout << endl;
	switch (menuChoice) {
	case 1:
	{
		cout << "Choose the room type:" << endl;
		cout << "1. single room" << endl;
		cout << "2. double room" << endl;
		cin >> roomChoice;
		if (roomChoice == 1) {
			roomBed = "single";
		}
		else {
			roomBed = "double";
		}

		checkAvailabilityRoomType(roomBed, rooms, NUM_ROOMS, proceedBooking);

		if (proceedBooking) {

			cout << "How do you want to choose your room?" << endl;
			cout << "1. On my own" << endl;
			cout << "2. Random room number" << endl;
			cin >> methodChoice;

			if (methodChoice == 1) {
				askAndCheckRoomNumInput(roomBed, roomNum);
				CheckAvailabilityAndChooseRoom(roomNum, rooms);
			}
			else {
				machineChoose(roomBed, roomNum, rooms);
			}

			//checkAndBookRoomNumber(roomBed, roomNum, rooms);
			//CheckAvailabilityAndChooseRoom(roomNum, rooms);
		}
		else {
			goto start;  //or idk. smth that will get the user back to menu
		}
	}
	}


	/*
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
*/
	return 0;
}


	int checkAvailabilityRoomType(string roomBed, RoomInfo rooms[], int size, bool proceedReservation) {
		bool disponibility=false;
		int choice;


		
		for (int i = 0; i < size; i++) {
			if (rooms[i].roomType == roomBed && rooms[i].availability == true) {
				disponibility = true;
			}
		}
		

		if (!disponibility) {
			cout << "Unfortunately, we don't have " << roomBed << " rooms available." << endl;

			if (roomBed == "single") {
				roomBed = "double";
			}
			else {
				roomBed = "single";
			}

			for (int i = 0; i < size; i++) {
				if (rooms[i].roomType == roomBed && rooms[i].availability == true) {
					disponibility = true;
				}
			}

			if (disponibility) {
				cout << "However, we have some " << roomBed << " rooms available." << endl;
				cout << "Do you want to book one?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				cin >> choice;
				if (choice == 1) {
					proceedReservation = true;

				}
				else {

					proceedReservation = false;
					cout << "Thank you for your time!" << endl;
					return 0;
				}
			}
			else {
				proceedReservation = false;
				cout << "We have no other option for the room at the moment, but you are very welcome to come in the near future and check again!" << endl;
				cout << "Have a great day!";
				return 0;
			}

		}
		else if(disponibility) {
			proceedReservation = true;
		}
		return 0;
	}


	void CheckAvailabilityAndChooseRoom(int num, RoomInfo rooms[]) {
		int newNum;
		if (rooms[num - 1].availability == true) {
			cout << "You have booked room number " << num << "." << endl;
			rooms[num - 1].availability = false;
		}
		else if (rooms[num - 1].availability == false) {
			cout << "The room you chose is not available. Please select another room!" << endl;
			cout << "Insert room number: " << endl;
			cin >> newNum;
			CheckAvailabilityAndChooseRoom(newNum, rooms);
		}
	}


	int askAndCheckRoomNumInput(string roomType, int roomNum) {
		if (roomType == "single") {
			cout << "Write a room number between 1 and 20, please!" << endl;
			cin >> roomNum;
			while (roomNum < 1 || roomNum>20) {
				cout << "Choose a room number between 1 and 20, please!" << endl;
				cin >> roomNum;
			}
		}
		else if(roomType == "double") {
			cout << "Write a room number between 21 and 40, please!" << endl;
			cin >> roomNum;
			while (roomNum < 21 || roomNum>40) {
				cout << "Choose a room number between 21 and 40, please!" << endl;
				cin >> roomNum;
			}
		}

		return roomNum;
	}

	int machineChoose(string roomType, int roomNum, RoomInfo rooms[]) {
		int checkNum;
		if (roomType == "single") {
			while (!roomNum) {
				checkNum = rand() % 20 + 1;
				for (int i = 0; i < 20; i++) {
					if (rooms[i].number == checkNum && rooms[i].availability == true) {
						roomNum = checkNum;
					}
				}
			}
		}
		else {
			while (!roomNum) {
				checkNum = rand() % (40 - 21 + 1) + 21;   //rand()%(max-min + 1) + min
				for (int i = 20; i < 40; i++) {
					if (rooms[i].number == checkNum && rooms[i].availability == true) {
						roomNum = checkNum;
					}
				}
			}
		}
		cout << "Your chosen room number is: " << roomNum << ".";
		return 0;
	}