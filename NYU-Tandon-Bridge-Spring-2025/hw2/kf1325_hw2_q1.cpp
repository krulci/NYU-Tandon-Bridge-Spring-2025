#include <iostream>

using namespace std;

void main()
{
	int numOfQuarters, numOfDimes, numOfNickels, numOfPennies, dollar, cent;

	cout << "Please enter number of coins:\n";
	cout << "# of quarters : ";
	cin >> numOfQuarters;

	cout << "# of dimes : ";
	cin >> numOfDimes;

	cout << "# of nickels : ";
	cin >> numOfNickels;

	cout << "# of pennies : ";
	cin >> numOfPennies;

	dollar = (25 * numOfQuarters + 10 * numOfDimes + 5 * numOfNickels + 1 * numOfPennies) / 100;
	cent = (25 * numOfQuarters + 10 * numOfDimes + 5 * numOfNickels + 1 * numOfPennies) % 100;

	cout << "The total is " << dollar << " dollars and " << cent << " cents";

	return;
}