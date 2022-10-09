#include<iostream>
using namespace std;

int calculateRectangularPrismVolume(int, int, int);
int main() {
	int height, width, depth, volume;
	cout << "Give me rectangular prism height, width, and depth? : \n";
	cin >> height >> width >> depth;
	volume = calculateRectangularPrismVolume(height, width, depth);
	cout << "Rectangular prism volume is: " << volume;
	return 0;
}
int calculateRectangularPrismVolume(int h, int w, int d) {
	int volume = h * w * d;
	return volume;
}
