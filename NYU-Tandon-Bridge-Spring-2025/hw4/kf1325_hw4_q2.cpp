#include <iostream>

using namespace std;

int main()
{
	int decimal, numOfM, numOfD, numOfC, numOfL, numOfX, numOfV, numOfI;
	string roman;

	cout << "Enter decimal number: " << endl;
	cin >> decimal;

	numOfM = decimal / 1000;
	numOfD = (decimal % 1000) / 500;
	numOfC = (decimal % 500) / 100;
	numOfL = (decimal % 100) / 50;
	numOfX = (decimal % 50) / 10;
	numOfV = (decimal % 10) / 5;
	numOfI = (decimal % 5);

	for (; numOfM > 0; numOfM--)
		roman += "M";
	for (; numOfD > 0; numOfD--)
		roman += "D";
	for (; numOfC > 0; numOfC--)
		roman += "C";
	for (; numOfL > 0; numOfL--)
		roman += "L";
	for (; numOfX > 0; numOfX--)
		roman += "X";
	for (; numOfV > 0; numOfV--)
		roman += "V";
	for (; numOfI > 0; numOfI--)
		roman += "I";

	cout << decimal << " is " << roman;

	return 0;
}