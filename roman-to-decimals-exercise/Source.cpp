#include <iostream>
using namespace std;

//Defining subprograms
int valueConverter(char);		//function that changes each roman character in decimals
int romanToDecimal(string);		//function that takes the whole roman number and converts it in decimals

//main function
int main() {
	string romanNum;   //defining string value
	cout << "The Roman numeral whose decimal value you want to know? ";   
	cin >> romanNum;    //user inputs the roman number
	cout<<"Roman numeral in decimal form "<<romanNum<<" is "<<romanToDecimal(romanNum)<<endl;      //printing the decimal number while calling the romanToDecimal function; 

	return 0;

}


//converting each roman character to its decimal correspondent
int valueConverter(char l) {
	if (l == 'I')
		return 1;
	if (l == 'V')
		return 5;
	if (l == 'X')
		return 10;
	if (l == 'L')
		return 50;
	if (l == 'C')
		return 100;
	if (l == 'D')
		return 500;
	if (l == 'M')
		return 1000;

	return 0;
}

//transforming the whole roman number into decimal number
int romanToDecimal(string romanNum) {
	int decimalNum = 0;    //initiating a variable for decimal number and assigning its value to 0
	for (int i = 0; i < romanNum.length(); i++) {        //iterating through the romanNum
		int char1 = valueConverter(romanNum[i]);			//storing the decimal number corresponding to a character in the string
		int char2 = valueConverter(romanNum[i + 1]);		//storing the decimal number corresponding to the next character in the string

		//this part of the program that runs for all the characters except the last one
		if ((i + 1) < romanNum.length()) {					
			if (char1 < char2) {									//if the decimal correspondent for the a character is smaller than the next one, the substraction between those two is added to decimalNum
				decimalNum = decimalNum + char2 - char1;
				i++;
			}
			else {
				decimalNum = decimalNum + char1;					//else, it adds the decimal correspondent for the that character
			}
		}

		//this part of the program runs for the last character (it will run if the decimal correspondent for the character before it is bigger than the decimal correspondent of the last character)
		else {
			decimalNum = decimalNum + char1;
		}
		
		//if first is lower then the second. substract the first from the second
	}
	return decimalNum;
}