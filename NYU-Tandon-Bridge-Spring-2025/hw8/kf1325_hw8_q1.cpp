#include <iostream>;

using namespace std;

int minInArray(int arr[], int arrSize);

int main()
{
	int arrSize = 20;
	int arr[20]{};

	cout 
		<< "Please enter 20 integers separated by a space: " 
		<< endl;

	for (int i = 0; i < arrSize; i++)
		cin >> arr[i];

	int minValue = minInArray(arr, arrSize);

	cout 
		<< "The minimum value is " 
		<< minValue 
		<< ", and it is located in the following indices: ";

	for (int i = 0; i < arrSize; i++)
		if (arr[i] == minValue)
			cout << i << ' ';

	return 0;
}

int minInArray(int arr[], int arrSize)
{
	int minValue = arr[0];

	for (int i = 0; i < arrSize; i++)
		if (arr[i] < minValue)
			minValue = arr[i];

	return minValue;
}