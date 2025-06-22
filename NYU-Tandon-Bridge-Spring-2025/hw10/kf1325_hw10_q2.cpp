#include <iostream>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main()
{
	int arr[] = {3, 1, 3, 0, 6, 4};
	int n = 6;
	int resArrSize;

	int* resArr = findMissing(arr, n, resArrSize);

	cout
		<< "\[";

	for (int i = 0; i < resArrSize; i++)
	{
		cout
			<< resArr[i];
		if (i != (resArrSize - 1))
			cout
			<< ", ";
	}

	cout
		<< "\]";
}

// cannot do (sizeof(arr) / sizeof(arr[0])
// objects decay to pointer when it is passed to a function without special signature
// when objects decay into pointers, size infomation is lost
// int arr[5] = {1, 2, 3, 4, 5};
// int* ptr = arr;
// int value = *ptr; // value == 1
// int value_n = *(ptr + n);

int* findMissing(int arr[], int n, int& resArrSize)
{
	bool* valArr = new bool[n + 1]();

	for (int i = 0; i < n; i++)
		valArr[arr[i]] = true;

	int* resArr = new int[n + 1];
	resArrSize = 0;

	for (int i = 0; i < (n + 1); i++)
		if (!valArr[i])
			resArr[resArrSize++] = i;

	delete[] valArr;
	return resArr;
}
