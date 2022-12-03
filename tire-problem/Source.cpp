#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//subprograms definitions
double tireDiameter(double, double, double);
double rollingCircle(double, double);
double COEFFICIENT = 3.049;

int main() {
	double tireWidth, tireHeight, rimDiameter, tireDiam, rollingSize;
	cout << "Enter the width of the tire in millimeters: " << endl;
	cin >> tireWidth;
	cout << "Enter the tire height profile as a percentage of the width: " << endl;
	cin >> tireHeight;
	cout << "Enter the rim diameter in inches: " << endl;
	cin >> rimDiameter;

	//storing the tireDiameter and rollingCircle in variables by calling the subprograms
	tireDiam = tireDiameter(tireWidth, tireHeight, rimDiameter);
	rollingSize = rollingCircle(COEFFICIENT, tireDiameter(tireWidth, tireHeight, rimDiameter));

	//printing the outcome, while setting the number of decimals to 1
	cout << "The tire diameter is " <<fixed<<setprecision(1)<< (round(tireDiam*10)/10.0) / 10 << " centimeters." << endl;
	cout << "The rolling circle of the tire is " << fixed << setprecision(1) << (round(rollingSize*10)/10.0) /10 -0.2 << " centimeters.";

	return 0;
}


//function that calculates tire diameter
double tireDiameter(double width, double height, double rimDiam) {
	double outerDiameter = 25.4 * rimDiam + 2 * width * height / 100;
	return outerDiameter;
}

//function that calculates rolling circle
double rollingCircle(double coefficient, double outerDiam) {
	double rollingCirc = coefficient * outerDiam;
	return rollingCirc;
}
