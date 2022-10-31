#include <iostream>
using namespace std;



//declaring of structure
struct State {
	string name;
	int population;
	int area;
	string leader;
};
int main() {
	//initiliazing a structure within an array
	const int numOfStates = 5;
	State state[numOfStates];
	int i;
	//assigning values
	for (i = 0; i < numOfStates; i++) {
		cout << "Insert the name of the " << i + 1 << ". state: ";
		getline(cin, state[i].name);
		cout << "Insert the population: ";
		cin >> state[i].population;
		cout << "Insert the area: ";
		cin >> state[i].area;
		cout << "Insert the leader's name: ";
		cin.ignore();
		getline(cin, state[i].leader);
	}
	//print information
	for (i = 0; i < numOfStates; i++) {
		cout << "State " << i + 1 << " Information" << endl;
		cout << "State name: " << state[i].name << endl;
		cout << "Population: " << state[i].population << endl;
		cout << "Area:" << state[i].area << endl;
		cout << "Leader Name: " << state[i].leader << endl;
	}
	return 0;
}
