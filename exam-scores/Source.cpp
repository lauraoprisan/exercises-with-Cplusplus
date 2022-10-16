#include <iostream>
using namespace std;

int main() {
	const int SIZE = 10;
	float sum = 0, average, scores[SIZE];
	int i;

	cout << "Enter the exam score: \n";  //score input section
	for (i=0;i<SIZE;i++)
		cin >> scores[i];
	cout << "The exam scores are: ";    //printing score section
	for (i = 0; i < SIZE; i++)
		cout << scores[i] << " ";
	for (i = 0; i < SIZE; i++)	// calculating sum
		sum += scores[i];
	cout <<endl<< "The sum of of all scores are: "<<sum<<endl; //printing sum
	average = sum / SIZE; //calculating average
	cout << "The average score is: " << average; //printing average
	return 0;

}

