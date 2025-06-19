#include <iostream>

using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

void printArray(int arr[], int arrSize);

int main()
{
	int arr[] = { 5, 2, 11, 7, 6, 4 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	cout
		<< "int main();"
		<< endl;

	printArray(arr, arrSize);

	oddsKeepEvensFlip(arr, arrSize);

	cout
		<< "oddsKeepEvensFlip(arr, arrSize);"
		<< endl;

	printArray(arr, arrSize);
}

void oddsKeepEvensFlip(int arr[], int arrSize)
{
	int* outArr = new int[arrSize];

	int oddIndex = 0;
	int evenIndex = arrSize - 1;

	for (int i = 0; i < arrSize; i++)
		if (arr[i] % 2 == 0)
			outArr[evenIndex--] = arr[i];
		else
			outArr[oddIndex++] = arr[i];

	for (int i = 0; i < arrSize; i++)
		arr[i] = outArr[i];

	delete[] outArr;
}

void printArray(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}