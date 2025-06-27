#include <iostream>

using namespace std;

int sumOfSquares(int arr[], int arrSize);

bool isSorted(int arr[], int arrSize);

int main()
{
	int arrSize = 4;
	int arr[] = { 2, -1, 3, 10 };

	int value = sumOfSquares(arr, arrSize);

	cout
		<< value
		<< endl;

	int arr2[] = { 1, 2, 3, 4 };

	cout
		<< "arr";

	(isSorted(arr, arrSize))
		? cout << " is sorted." << endl
		: cout << " is not sorted." << endl;
	cout
		<< "arr2";

	(isSorted(arr2, arrSize))
		? cout << " is sorted." << endl
		: cout << " is not sorted." << endl;
}

int sumOfSquares(int arr[], int arrSize)
{
	if (arrSize == 0)
		return 0;

	return arr[arrSize - 1] * arr[arrSize - 1] + sumOfSquares(arr, arrSize - 1);
}

bool isSorted(int arr[], int arrSize)
{
	if (arrSize == 1)
		return true;

	return arr[arrSize - 2] < arr[arrSize - 1] && isSorted(arr, arrSize - 1);
}
