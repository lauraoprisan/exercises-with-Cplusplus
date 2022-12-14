#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;


//struct declaration
struct RoomInfo {
	int number;
	bool availability;
	int price;
	int customPrice;
	string roomType;
	int bookingNum;
	string name;
	int nights;
};

//Function prototypes
int checkAvailabilityRoomType(int, string&, RoomInfo[], int, bool&);
int askAndCheckRoomNumInput(string, int&, int);
void CheckAvailabilityAndChooseRoom(int&, RoomInfo[]);
int machineChoose(string, int&, RoomInfo[], int);
int calculateAndShowPrice(int, string);
void showPreliminaryBookingDetails(int, string, int, int, string);
void bookingConfirmation(int, int, string, int&, RoomInfo[], int);
void showFinalBookingDetailsByName(string, RoomInfo[], int, bool&, bool&, int&);
void showFinalBookingDetailsById(int, RoomInfo[], int, bool&, int&);
void inputCheck(int&);


int main() {



	const int NUM_ROOMS = 40;   //constant for array size
	RoomInfo rooms[NUM_ROOMS];  //an array of structures
	int index, menuChoice, roomNum = 0, nightsNum, price, bookingId, found;
	bool proceedBooking = true, nameDuplicity, roomsAvailable, modifyByName, modifyById;
	string roomBed, name;


	//assigning numbers, prices, roomTypes for single rooms; setting all single rooms' availability to true and booking Id to 0
	for (index = 0; index < NUM_ROOMS / 2; index++) {
		rooms[index].number = index + 1;
		rooms[index].price = 100;
		rooms[index].roomType = "single";
		rooms[index].availability = true;
		rooms[index].bookingNum = 0;

	}

	//assigning numbers, prices, roomTypes for double rooms; setting all double rooms' availability to true and booking Id to 0
	for (index = (NUM_ROOMS / 2); index < NUM_ROOMS; index++) {
		rooms[index].number = index + 1;
		rooms[index].price = 150;
		rooms[index].roomType = "double";
		rooms[index].availability = true;
		rooms[index].bookingNum = 0;
	}


	//welcoming message
	cout << endl << endl;
	cout << "Welcome to our hotel!" << endl << endl;
	cout << "Navigate the menu by choosing numbers of the option!" << endl << endl;



start:			//returning point after navigating the menu options


	//resetting roomNum, modifyByName and modifyById each time after returning to start
	roomNum = 0;
	modifyByName = false;
	modifyById = false;

	//main menu options

	cout << "1. Make a reservation" << endl;
	cout << "2. Show prices" << endl;
	cout << "3. Check your reservation" << endl;
	cout << "4. Exit" << endl;


	cin >> menuChoice;

	//input check. it needs to be an integer, between 1 and 4
	while (cin.fail() || menuChoice < 1 || menuChoice>4) {
		cout << "You can select either 1, 2, 3 or 4. Please, try again!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> menuChoice;
	}
	cout << endl;

	//navigating the menu options
	switch (menuChoice) {

		//Make a reservation option
	case 1:
	{
		//Checking if there is at least one room available
		for (int i = 0; i < NUM_ROOMS; i++) {
			if (rooms[i].availability == true) {
				roomsAvailable = true;

			}
			else {
				roomsAvailable = false;
			}
		}

		//There are no rooms left - case
		if (roomsAvailable == false) {
			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			cout << "We are all booked, but you are very welcome to come in the near future and check again!" << endl;
			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			goto start;
		}

		//There is at least one more room available - case
		else {
			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			cout << "Choose the room type:" << endl;
			cout << "1. single room" << endl;
			cout << "2. double room" << endl;
			cin >> menuChoice;

			//input check. it needs to be an integer (1 or 2)
			inputCheck(menuChoice);


			//Checking room type availability
			checkAvailabilityRoomType(menuChoice, roomBed, rooms, NUM_ROOMS, proceedBooking);
			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			/*Program to execute if the room type chosen by user is available
			or
			if the user agrees to book another available room type (in case there are no more rooms available with chosen room type)
			*/

			if (proceedBooking) {

				cout << "How do you want to choose your room?" << endl;
				cout << "1. On my own" << endl;
				cout << "2. Random room number" << endl;
				cin >> menuChoice;
				//input check. it needs to be an integer (1 or 2)
				inputCheck(menuChoice);

				//Manually chosen room number
				if (menuChoice == 1) {

					/*
						asking the room number and checking if the input is valid
						(For n rooms it has to be between 1 and n / 2 for single rooms and between n / 2 + 1 and n for double rooms)
					*/
					cout << endl << endl << "------------------------------------------------------------" << endl << endl;
					askAndCheckRoomNumInput(roomBed, roomNum, NUM_ROOMS);
					cout << endl << endl << "------------------------------------------------------------" << endl << endl;

					//checking if the room number is available; in case it is not, the program asks for another room numbers until the user choose an available number
					CheckAvailabilityAndChooseRoom(roomNum, rooms);
					cout << endl << endl << "------------------------------------------------------------" << endl << endl;
				}

				//Automatically chosen room number
				else {
					cout << endl << endl << "------------------------------------------------------------" << endl << endl;
					machineChoose(roomBed, roomNum, rooms, NUM_ROOMS);					//choosing an available room number
					cout << endl << endl << "------------------------------------------------------------" << endl << endl;
				}
			}

			/*
				Program to execute if the room type chosen by user is unavailable
				and
				the user does not agree to book another available room type
			*/

			else {
				goto start;						//returning at the beginning of the main menu, at the returning point
			}

			//continuing with the booking (the agreed booking)

			cout << "How many nights do you want to stay?" << endl;
			cin >> nightsNum;
			//input check. it needs to be an integer
			while (cin.fail()) {
				cout << "Please, use an integer!" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> menuChoice;
			}


			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			price = calculateAndShowPrice(nightsNum, roomBed);       //calculating the final price (with random discount added) and displaying it
			rooms[roomNum - 1].customPrice = price;							//storing the final price

			cout << "To continue the booking, write your name, please: ";
			cin.ignore();
			getline(cin, name);


			//input check. it checks if name is empty
			while (name.empty()) {
				cout << "Write your name, please!"<<endl;
				getline(cin, name);
			}



			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			showPreliminaryBookingDetails(roomNum, roomBed, nightsNum, price, name);           //showing preliminary booking details
			cout << endl << endl << "------------------------------------------------------------" << endl << endl;


			cout << "Do you confirm the booking?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
			cin >> menuChoice;

			//input check. it needs to be an integer (1 or 2)
			inputCheck(menuChoice);

			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			//booking confirmed
			if (menuChoice == 1) {
				rooms[roomNum - 1].name = name;							//storing the name for the booking
				bookingConfirmation(roomNum, nightsNum, name, bookingId, rooms, NUM_ROOMS);        //generating unique random booking ID, storing booking information and displaying a confimation text
				cout << endl << endl << "------------------------------------------------------------" << endl << endl;
				goto start;											//returning at the beginning of the main menu, at the returning point
			}

			//the user didn't confirm the booking
			else {
				goto start;											//returning at the beginning of the main menu, at the returning point
			}
		}

	}

	//Show prices option
	case 2: {
		cout << endl << endl << "------------------------------------------------------------" << endl << endl;
		cout << "Prices list" << endl << endl;
		cout << "Single room / night: 100 euros" << endl;
		cout << "Double room / night: 150 euros" << endl << endl;
		cout << "We offer random discounts up to 20%!" << endl;
		cout << "May the luck be with you!" << endl;
		cout << endl << endl << "------------------------------------------------------------" << endl << endl;
		goto start;											//returning at the beginning of the main menu, at the returning point

	}

		  //Check your reservation option
	case 3: {
		cout << endl << endl << "------------------------------------------------------------" << endl << endl;
		cout << "Access your reservation: " << endl;
		cout << "1. By name" << endl;
		cout << "2. By booking number" << endl;
		cin >> menuChoice;

		//input check. it needs to be an integer (1 or 2)
		inputCheck(menuChoice);

		cout << endl << endl << "------------------------------------------------------------" << endl << endl;
		//Accessing reservation by name
		if (menuChoice == 1) {
			cout << "Write your name: ";
			cin.ignore();
			getline(cin, name);

			//input check. it checks if name is empty
			while (name.empty()) {
				cout << "Write your name, please!"<<endl;
				getline(cin, name);
			}

			/*
				in case the name only occurs once in the booking records, the program displays all the booking information attached to the name
				or
				in case there is no reservation made with that name, the program displays a text informing the user about it
				or
				in case there are multiply reservation with the same name, the variable "nameDuplicity" is assigned the boolean value "true"
			*/
			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			showFinalBookingDetailsByName(name, rooms, NUM_ROOMS, nameDuplicity, modifyByName, found);
			//if there are multiply reservation with the same name, the user is asked to check his reservation via booking ID
			if (nameDuplicity) {
				cin >> bookingId;


				/*
					in case the booking ID exists, the program displays all the booking information attached to the booking ID
					or
					in case there is no reservation made with that booking ID, the program displays a text informing the user about it
				*/
				cout << endl << endl << "------------------------------------------------------------" << endl << endl;
				showFinalBookingDetailsById(bookingId, rooms, NUM_ROOMS, modifyById, found);
				cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			}

		}

		//Accessing reservation by booking ID
		else {
			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			cout << "Write your booking number: ";
			cin >> bookingId;


			/*
				in case the booking ID exists, the program displays all the booking information attached to the booking ID
				or
				in case there is no reservation made with that booking ID, the program displays a text informing the user about it
			*/
			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			showFinalBookingDetailsById(bookingId, rooms, NUM_ROOMS, modifyById, found);
			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
		}

		//this programs runs if the user found his reservation
		if (modifyByName || modifyById) {
			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			cout << "1. Everything looks great!" << endl;
			cout << "2. I want to delete my reservation!" << endl;
			cin >> menuChoice;

			//input check. it needs to be an integer (1 or 2)
			inputCheck(menuChoice);

			cout << endl << endl << "------------------------------------------------------------" << endl << endl;
			//All is good -case
			if (menuChoice == 1) {
				goto start;
			}

			//Delete reservation -case
			else {

				//Confirmation of deleting the booking
				cout << "Are you sure?" << endl;
				cout << "1. No, I want to keep it!" << endl;
				cout << "2. Yes!" << endl;
				cin >> menuChoice;

				//input check. it needs to be an integer (1 or 2)
				inputCheck(menuChoice);

				cout << endl << endl << "------------------------------------------------------------" << endl << endl;

				//deleting the booking important details and setting the room available again
				if (menuChoice == 2) {
					rooms[found].availability = true;
					rooms[found].bookingNum = 0;
					rooms[found].name = "";
					cout << "You reservation has been deleted!" << endl;
					cout << endl << endl << "------------------------------------------------------------" << endl << endl;
				}

				//User didn't confirm the deleting process
				else {
					goto start;										//returning at the beginning of the main menu, at the returning point
				}

			}
		}

		goto start;				//returning at the beginning of the main menu, at the returning point

	}

		  //Exit option
	case 4: {
		cout << endl << endl << "------------------------------------------------------------" << endl << endl;
		cout << "Thank you for your visit!" << endl;
	}
	}



	return 0;
}






/*
	program that checks the room type availability;
	in case the chosen room type it is not available and there is at least an available room with the other room type, it informs the user and let's him choose if he wants this option
*/
int checkAvailabilityRoomType(int menuChoice, string& roomBed, RoomInfo rooms[], int size, bool& proceedReservation) {
	bool disponibility = false;
	int choice;

	//user chooses the room type
	if (menuChoice == 1) {
		roomBed = "single";
	}
	else {
		roomBed = "double";
	}

	//checking if there are available rooms of the chosen room type
	for (int i = 0; i < size; i++) {
		if (rooms[i].roomType == roomBed && rooms[i].availability == true) {
			disponibility = true;
		}
	}

	//program that runs if there are no available rooms of the chosen room type
	if (!disponibility) {
		cout << endl << endl << "------------------------------------------------------------" << endl << endl;
		cout << "Unfortunately, we don't have " << roomBed << " rooms available." << endl;



		//changing the value of the chosen room type with the other one
		if (roomBed == "single") {
			roomBed = "double";
		}
		else {
			roomBed = "single";
		}

		//checking if there are available rooms of the other room type
		for (int i = 0; i < size; i++) {
			if (rooms[i].roomType == roomBed && rooms[i].availability == true) {
				disponibility = true;
			}
		}

		//program that runs if there are available rooms of the other room type
		if (disponibility) {
			cout << endl << "However, we have some " << roomBed << " rooms available." << endl;
			cout << "Do you want to book one?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
			cin >> choice;

			//input check. it needs to be an integer (1 or 2)
			while (cin.fail() || choice < 1 || choice>4) {
				cout << "You can select either 1 or 2. Please, try again!" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> choice;
			}

			if (choice == 1) {
				proceedReservation = true;
			}
			else {

				proceedReservation = false;
				cout << "Thank you for your time!" << endl;

			}
		}

	}
	//program that runs if there are available rooms of the chosen room type
	else if (disponibility) {
		proceedReservation = true;
	}
	return 0;
}

//program that checks if the room number is available; in case it is not, the program asks for another room numbers until the user choose an available number
void CheckAvailabilityAndChooseRoom(int& num, RoomInfo rooms[]) {

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

/*
	Program that asks for room number and checks if the input is valid
	(For n rooms it has to be between 1 and n / 2 for single rooms and between n / 2 + 1 and n for double rooms)
*/
int askAndCheckRoomNumInput(string roomType, int& roomNum, int size) {

	//for single rooms
	if (roomType == "single") {
		cout << "Choose a room number between 1 and " << size / 2 << ", please!" << endl;
		cin >> roomNum;

		//input check. it needs to be an integer  between 1 and n / 2
		while (cin.fail() || roomNum < 1 || roomNum>size / 2) {
			cout << "Choose a room number between 1 and " << size / 2 << ", please!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> roomNum;
		}
	}


	//for double rooms
	else if (roomType == "double") {
		cout << "Choose a room number between " << size / 2 + 1 << " and " << size << ", please!" << endl;
		cin >> roomNum;

		//input check. it needs to be an integer between n / 2 + 1 and n for double rooms
		while (cin.fail() || roomNum < size / 2 + 1 || roomNum>size) {
			cout << "Choose a room number between " << size / 2 + 1 << " and " << size << ", please!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> roomNum;
		}
	}

	return 0;
}

//Program that randomly chooses an available room number
int machineChoose(string roomType, int& roomNum, RoomInfo rooms[], int size) {
	int checkNum;

	//for single rooms
	if (roomType == "single") {

		//program that runs until an available room number is found
		while (!roomNum) {
			checkNum = rand() % size / 2 + 1;	  				//random room number between 1 and the total of single rooms (half of the total rooms) generated and temporarly stored for following checks

			//checking if the random room number is available and if it is, the room number is stored
			for (int i = 0; i < size / 2; i++) {
				if (rooms[i].number == checkNum && rooms[i].availability == true) {
					roomNum = checkNum;
				}
			}
		}
	}

	//for double rooms
	else {

		//program that runs until an available room number is found
		while (!roomNum) {
			checkNum = rand() % (size - (size / 2 + 1) + 1) + (size / 2 + 1);  //random room number between total rooms/2 and total rooms generated and temporarly stored for following checks

			//checking if the random room number is available and if it is, the room number is stored
			for (int i = size / 2; i < size; i++) {
				if (rooms[i].number == checkNum && rooms[i].availability == true) {
					roomNum = checkNum;
				}
			}
		}
	}
	cout << "Your chosen room number is: " << roomNum << "." << endl;
	return 0;
}

//Program that calculates the final price (with random discount added) and displaying it
int calculateAndShowPrice(int nights, string roomType) {
	int price, discount[3] = { 0, 10, 20 }, discountOffer = 0;

	discountOffer = rand() % 3;          //randomly choosing a discount

	if (roomType == "single") {
		price = (100 - discount[discountOffer]) * nights * 100 / 100;
	}
	else {
		price = (100 - discount[discountOffer]) * nights * 150 / 100;
	}
	if (discountOffer != 0) {
		cout << "You are lucky! You have a discount of " << discount[discountOffer] << "%!" << endl;
	}
	cout << "The price for the room is: " << price << " euros." << endl;

	return price;
}

//Program that displays the preliminary booking details
void showPreliminaryBookingDetails(int roomNum, string roomBed, int nights, int price, string name) {
	cout << "Booking details: " << endl << endl;
	cout << "Name: " << name << endl;
	cout << "Room number: " << roomNum << endl;
	cout << "Room type: " << roomBed << endl;
	cout << "Number of nights: " << nights << endl;
	cout << "Price: " << price << endl;
}


//Program that generates a unique random booking number, storing all booking information and displaying a confirmation text
void bookingConfirmation(int roomNum, int nights, string name, int& bookingId, RoomInfo rooms[], int size) {

	//choosing a different random booking number
	bool foundIdCopy = false;

	while (rooms[roomNum - 1].bookingNum == 0) {
		bookingId = rand() % 99999 + 10000;                //generating a random number between 10000 and 99999
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


	rooms[roomNum - 1].availability = false;    //setting the room unavailable
	rooms[roomNum - 1].nights = nights;			//storing booking info


	cout << "Thank you, " << name << "!" << endl;
	cout << "Your booking number is: " << bookingId << "." << endl << endl;
}

/*
	Description of the following function:
		in case the name only occurs once in the booking records, the program displays all the booking information attached to the name
		or
		in case there is no reservation made with that name, the program displays a text informing the user about it
		or
		in case there are multiply reservation with the same name, the variable "nameDuplicity" is assigned the boolean value "true"
*/
void showFinalBookingDetailsByName(string name, RoomInfo rooms[], int size, bool& nameDuplicity, bool& modifyByName, int& found) {

	//checking reservation existence and name duplicity
	nameDuplicity = false;
	int nameCopy = 0;

	for (int i = 0; i < size; i++) {
		if (rooms[i].name == name) {
			nameCopy++;
		}

	}

	//program that runs in case there is no reservation with the inserted name
	if (nameCopy == 0) {
		cout << "There is no reservation with this name!" << endl;
		cout << endl << endl << "------------------------------------------------------------" << endl << endl;
	}

	//program that runs if there is one reservation with the inserted name
	else if (nameCopy == 1) {
		found = 0;
		modifyByName = true;										//this variable is used in order to make deleting the booking possible
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

	//program that runs if there are multiple reservations with the same name
	else {
		nameDuplicity = true;
		cout << "It seems there are at least 2 reservations with the same name." << endl;
		cout << "To access your reservation write your booking number: " << endl;
	}


}


/*
	Description of the following program:
		in case the booking ID exists, the program displays all the booking information attached to the booking ID
		or
		in case there is no reservation made with that booking ID, the program displays a text informing the user about it
*/
void showFinalBookingDetailsById(int bookingNum, RoomInfo rooms[], int size, bool& modifyById, int& found) {
	found = -1;

	for (int i = 0; i < size; i++) {
		if (rooms[i].bookingNum == bookingNum) {
			found = i;
		}
	}

	if (found >= 0) {
		modifyById = true;							//this variable is used in order to make deleting the booking possible
		cout << "Name: " << rooms[found].name << endl;
		cout << "Booking number: " << rooms[found].bookingNum << endl;
		cout << "Room number: " << rooms[found].number << endl;
		cout << "Room type: " << rooms[found].roomType << endl;
		cout << "Number of nights: " << rooms[found].nights << endl;
		cout << "Price: " << rooms[found].customPrice << endl;
	}
	else {
		cout << "There is no reservation with this booking number!" << endl;
	}

}

void inputCheck(int& choice) {
	while (cin.fail() || choice < 1 || choice>2) {
		cout << "You can select either 1 or 2. Please, try again!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> choice;
	}
}