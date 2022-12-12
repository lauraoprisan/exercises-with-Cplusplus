#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

struct RoomInfo {
	int number;
	bool availability = true;
	int price;
	int customPrice;
	string roomType;
	int bookingNum=0;
	string name;
	int nights;
};


int checkAvailabilityRoomType(int, string&, RoomInfo[], int, bool&);
int askAndCheckRoomNumInput(string, int&, int);
void CheckAvailabilityAndChooseRoom(int&, RoomInfo[]);
int machineChoose(string, int&, RoomInfo[]);
int calculateAndShowPrice(int, string);
void showPreliminaryBookingDetails(int, string, int, int, string);
void bookingConfirmation(int, int, string, int&, RoomInfo[], int);
void showFinalBookingDetailsByName(string, RoomInfo[], int, bool&, bool&, int&);
void showFinalBookingDetailsById(int, RoomInfo[], int, bool&, int&);



//void welcomeMessage(string);


int main() {
	const int NUM_ROOMS = 40;
	RoomInfo rooms[NUM_ROOMS];
	int index, menuChoice, roomChoice, roomNum = 0, methodChoice, nightsNum, price, bookingConf, bookingId, found;
	bool proceedBooking = true, nameDuplicity, roomsAvailable, modifyByName, modifyById;
	//int numOfNights;
	string choice;
	string roomBed, name;


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
	cout << "Navigate the menu by choosing numbers of the options!" << endl << endl;

start:
	roomNum = 0;
	modifyByName = false;
	modifyById = false;
	cout << "1. Make a reservation" << endl;
	cout << "2. Show prices" << endl;
	cout << "3. Check your reservation" << endl;


	cin >> menuChoice;
	cout << endl;
	switch (menuChoice) {
	case 1:
	{	
		for (int i = 0; i < NUM_ROOMS; i++) {
			if (rooms[i].availability == true) {
				roomsAvailable=true;
				
			}
			else {
				roomsAvailable = false;
			}
		}
	
		if (roomsAvailable==false) {
			cout << "We are all booked, but you are very welcome to come in the near future and check again!" << endl;
			goto start;
		}
		else {

		cout << "Choose the room type:" << endl;
		cout << "1. single room" << endl;
		cout << "2. double room" << endl;
		cin >> roomChoice;

		checkAvailabilityRoomType(roomChoice, roomBed, rooms, NUM_ROOMS, proceedBooking);

		if (proceedBooking) {

			cout << "How do you want to choose your room?" << endl;
			cout << "1. On my own" << endl;
			cout << "2. Random room number" << endl;
			cin >> methodChoice;

			if (methodChoice == 1) {
				askAndCheckRoomNumInput(roomBed, roomNum, NUM_ROOMS);
				CheckAvailabilityAndChooseRoom(roomNum, rooms);
			}
			else {
				machineChoose(roomBed, roomNum, rooms);
			}
		}


		else {
			goto start;  //or idk. smth that will get the user back to menu
		}


		cout << "How many nights do you want to stay?" << endl;
		cin >> nightsNum;

		price = calculateAndShowPrice(nightsNum, roomBed);
		rooms[roomNum - 1].customPrice = price; //storing the final price

		cout << "To continue the booking, write your name, please: ";
		cin.ignore();
		getline(cin, name);
		//cin >> name;
		showPreliminaryBookingDetails(roomNum, roomBed, nightsNum, price, name);
		cout << endl;
		cout << "Do you confirm the booking?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cin >> bookingConf;

		if (bookingConf == 1) {
			rooms[roomNum - 1].name = name;
			bookingConfirmation(roomNum, nightsNum, name, bookingId, rooms, NUM_ROOMS);
			cout << endl << endl;
			goto start;
		}
		else {
			goto start;
		}
		}
		
	}
	case 2: {
		cout << "Prices list" << endl << endl;
		cout << "Single room / night: 100 euros" << endl;
		cout << "Double room / night: 150 euros" << endl<<endl;
		cout << "We offer random discounts up to 20%!" << endl;
		cout << "May the luch be with you!" << endl << endl;

		goto start;

	}
	case 3: {
		cout << "Access your reservation: "<<endl;
		cout << "1. By name" << endl;
		cout << "2. By booking number" << endl;
		cin >> methodChoice;
		if(methodChoice == 1) {
			cout << "Write your name: ";
			cin.ignore();
			getline(cin, name);
			showFinalBookingDetailsByName(name, rooms, NUM_ROOMS, nameDuplicity, modifyByName, found);
			if (nameDuplicity) {
				cin >> bookingId;
				showFinalBookingDetailsById(bookingId, rooms, NUM_ROOMS, modifyById, found);
			}

		}
		else {
			cout << "Write your booking number: ";
			cin >> bookingId;
			showFinalBookingDetailsById(bookingId, rooms, NUM_ROOMS, modifyById, found);
		}


		if (modifyByName || modifyById) {
			cout << "1. Everything looks great!" << endl;
			cout << "2. I want to delete my reservation!" << endl;
			cin >> methodChoice;
			if (methodChoice == 1) {
				goto start;
			}
			else {
				cout << "Are you sure?" << endl;
				cout << "1. No, I want to keep it!" << endl;
				cout << "2. Yes!" << endl;
				cin >> methodChoice;
				if (methodChoice == 2) {
					rooms[found].availability = true;
					rooms[found].bookingNum = 0;
					rooms[found].name = "";
					cout << "You reservation has been deleted!" << endl;
				}
				else {
					goto start;
				}
				
			}
		}
		
		goto start;

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
/*
int checkNumber(int num, int &variableToSet ) {
	int choice;
	bool correct = false;
	while (correct == false) {
		if (isdigit(num) == true) {
			variableToSet = num;
			correct = true;
		}
		else {
			cout << "Write a number, please!" << endl;
			cin >> choice;
		}
	}
	return 0;
}
*/
int checkAvailabilityRoomType(int roomChoice, string& roomBed, RoomInfo rooms[], int size, bool &proceedReservation) {
	bool disponibility = false;
	int choice;

	if (roomChoice == 1) {
		roomBed = "single";
	}
	else {
		roomBed = "double";
	}


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
				
			}
		}
		/*
		else {
			proceedReservation = false;
			cout << "We have no other option for the room at the moment, but you are very welcome to come in the near future and check again!" << endl;
			cout << "Have a great day!";
		}
		*/
	}
	else if (disponibility) {
		proceedReservation = true;
	}
	return 0;
}


void CheckAvailabilityAndChooseRoom(int &num, RoomInfo rooms[]) {
	//int newNum;
	if (rooms[num - 1].availability == true) {
		cout << "You have booked room number " << num << "." << endl;
		rooms[num - 1].availability = false;
	}
	else if (rooms[num - 1].availability == false) {
		cout << "The room you chose is not available. Please select another room!" << endl;
		cout << "Insert room number: " << endl;
		cin >> num;
		CheckAvailabilityAndChooseRoom(num, rooms);
	}

	
}


int askAndCheckRoomNumInput(string roomType, int &roomNum, int size) {
	if (roomType == "single") {
		cout << "Write a room number between 1 and "<<size/2<<", please!" << endl;
		cin >> roomNum;
		while (roomNum < 1 || roomNum>size/2) {
			cout << "Choose a room number between 1 and " << size / 2 << ", please!" << endl;
			cin >> roomNum;
		}
	}
	else if (roomType == "double") {
		cout << "Write a room number between "<<size/2+1<<" and "<<size<<", please!" << endl;
		cin >> roomNum;
		while (roomNum < size / 2 + 1 || roomNum>size) {
			cout << "Choose a room number between " << size / 2 + 1 << " and " << size << ", please!" << endl;
			cin >> roomNum;
		}
	}

	return 0;
}

int machineChoose(string roomType, int &roomNum, RoomInfo rooms[]) {
	int checkNum;
	if (roomType == "single") {
		while (!roomNum) {
			checkNum = rand() % 20 + 1; //the same random num every time
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
	cout << "Your chosen room number is: " << roomNum << "."<<endl;
	return 0;
}

int calculateAndShowPrice(int nights, string roomType) {
	int price, discount[3]={0, 10, 20}, discountOffer=0;

	discountOffer = rand() % 3;
	
	if (roomType == "single") {
		price =  (100 - discount[discountOffer]) * nights * 100 / 100;
	}
	else {
		price = (100 - discount[discountOffer]) * nights * 150 / 100;
	}
	if (discountOffer!=0) {
		cout << "You are lucky! You have a discount of " << discount[discountOffer] << "%!" << endl;
	}
	cout << "The price for the room is: " << price << " euros." << endl;

	return price;
}

void showPreliminaryBookingDetails(int roomNum, string roomBed, int nights, int price, string name) {
	cout << "Name: " << name << endl;
	cout << "Room number: " << roomNum<<endl;
	cout << "Room type: " << roomBed << endl;
	cout << "Number of nights: " << nights << endl;
	cout << "Price: " << price << endl;
}

void bookingConfirmation(int roomNum, int nights, string name, int &bookingId, RoomInfo rooms[], int size) { 
	
	//choosing a different random booking number
	bool foundIdCopy = false;

	while (rooms[roomNum - 1].bookingNum==0) {
		bookingId = rand() % 99999 + 10000;
		for (int i = 0; i < size; i++) {
			if (rooms[i].bookingNum == bookingId) {
				bool foundIdCopy = true;
				break;
			}
		}
		if (foundIdCopy == false) {
			rooms[roomNum - 1].bookingNum = bookingId;
		}
	}

	
	rooms[roomNum - 1].availability = false;
	rooms[roomNum - 1].nights = nights;


	cout << "Thank you, " << name << "!" << endl;
	cout << "Your booking number is: " << bookingId << "." << endl<<endl;
}


void showFinalBookingDetailsByName(string name, RoomInfo rooms[], int size, bool &nameDuplicity, bool &modifyByName, int &found) {

	//checking reservation existence and name duplicity
	nameDuplicity = false;
	int nameCopy = 0;
	for (int i = 0; i < size; i++) {
		if (rooms[i].name == name) {
			nameCopy++;
		}
		
	}
	if (nameCopy == 0) {
		cout << "There is no reservation with this name!"<<endl;
	}
	else if (nameCopy ==1) {
		found = 0;
		modifyByName = true;
		for (int i = 0; i < size; i++) {
			if (rooms[i].name == name) {
				found = i;
			}
		}

		cout << "Name: " << rooms[found].name << endl;
		cout << "Booking number: " << rooms[found].bookingNum << endl;
		cout << "Room number: " << rooms[found].number << endl;
		cout << "Room type: " << rooms[found].roomType << endl;
		cout << "Number of nights: " << rooms[found].nights << endl;
		cout << "Price: " << rooms[found].customPrice << endl;
	}
	else  {
		nameDuplicity = true;
		cout << "It seems there are at least 2 reservations on the same name" << endl;
		cout << "To access your reservation write your booking number: " << endl;
	}

	
}

void showFinalBookingDetailsById(int bookingNum, RoomInfo rooms[], int size, bool &modifyById, int &found) {
	found = 0;

	for (int i = 0; i < size; i++) {
		if (rooms[i].bookingNum == bookingNum) {
			found = i;
		}
	}

	if (found !=0) {
		modifyById = true;
		cout << "Name: " << rooms[found].name << endl;
		cout << "Booking number: " << rooms[found].bookingNum << endl;   //I could delete this line
		cout << "Room number: " << rooms[found].number << endl;
		cout << "Room type: " << rooms[found].roomType << endl;
		cout << "Number of nights: " << rooms[found].nights << endl;
		cout << "Price: " << rooms[found].customPrice << endl;
	}
	else {
		cout << "There is no reservation with this booking number!" << endl;
	}
	
}

void deleteRevervation() {
	//select the booking via name or booking id and then set all the object/s properties to 0,true, empty str etc
	//variables needed: modifyByName, modifyById, 
}