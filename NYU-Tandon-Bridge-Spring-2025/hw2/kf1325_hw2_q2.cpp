#include <iostream>

using namespace std;

void main()
{
	int numOfQuarters, numOfDimes, numOfNickels, numOfPennies, dollar, cent;

	cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
	cin >> dollar >> cent;

	cout << dollar << " dollars and " << cent << " cents are:" << endl;

	numOfQuarters = (100 * dollar + 1 * cent) / 25;
	numOfDimes = (100 * dollar + 1 * cent - 25 * numOfQuarters) / 10;
	numOfNickels = (100 * dollar + 1 * cent - 25 * numOfQuarters - 10 * numOfDimes) / 5;
	numOfPennies = (100 * dollar + 1 * cent - 25 * numOfQuarters - 10 * numOfDimes - 5 * numOfNickels) / 1;


	cout << numOfQuarters << " quarters, " 
		<< numOfDimes << " dimes, " 
		<< numOfNickels << " nickels, "
		<< numOfPennies << " and pennies, ";

	return;
}