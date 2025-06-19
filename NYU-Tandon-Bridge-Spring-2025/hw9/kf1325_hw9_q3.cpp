#include <iostream>

using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

void printArray(int arr[], int arrSize);

int main()
{
	int arr[] = { 3, -1, -3, 0, 6, 4 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	cout
		<< "int main();"
		<< endl;

	printArray(arr, arrSize);

	{
		cout
			<< "int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);"
			<< endl;

		int outPosArrSize;

		int* outPosArr = getPosNums1(arr, arrSize, outPosArrSize);

		printArray(outPosArr, outPosArrSize);

		delete[] outPosArr;
	}

	{
		cout
			<< "int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);"
			<< endl;

		int* outPosArrSizePtr = new int;

		int* outPosArr = getPosNums2(arr, arrSize, outPosArrSizePtr);

		printArray(outPosArr, *outPosArrSizePtr);

		delete outPosArrSizePtr;
		delete[] outPosArr;
	}

	{
		cout
			<< "void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);"
			<< endl;

		int* outPosArr = nullptr;
		int outPosArrSize;

		getPosNums3(arr, arrSize, outPosArr, outPosArrSize);

		printArray(outPosArr, outPosArrSize);

		delete[] outPosArr;
	}

	{
		cout
			<< "void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);"
			<< endl;

		int* outPosArrPtr = nullptr;
		int* outPosArrSizePtr = new int;

		getPosNums4(arr, arrSize, &outPosArrPtr, outPosArrSizePtr);

		printArray(outPosArrPtr, *outPosArrSizePtr);

		delete outPosArrSizePtr;
		delete[] outPosArrPtr;
	}
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
{
	outPosArrSize = 0;

	for (int i = 0; i < arrSize; i++)
		if (arr[i] > 0)
			outPosArrSize++;

	int* outPosArr = new int[outPosArrSize];
	int posIndex = 0;

	for (int i = 0; i < arrSize; i++)
		if (arr[i] > 0)
			outPosArr[posIndex++] = arr[i];

	return outPosArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
{
	*outPosArrSizePtr = 0;

	for (int i = 0; i < arrSize; i++)
		if (arr[i] > 0)
			(*outPosArrSizePtr)++;

	int* outPosArr = new int[*outPosArrSizePtr];
	int posIndex = 0;

	for (int i = 0; i < arrSize; i++)
		if (arr[i] > 0)
			outPosArr[posIndex++] = arr[i];

	return outPosArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
{
	outPosArrSize = 0;

	for (int i = 0; i < arrSize; i++)
		if (arr[i] > 0)
			outPosArrSize++;

	outPosArr = new int[outPosArrSize];

	int posIndex = 0;

	for (int i = 0; i < arrSize; i++)
		if (arr[i] > 0)
			outPosArr[posIndex++] = arr[i];
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
{
	*outPosArrSizePtr = 0;

	for (int i = 0; i < arrSize; i++)
		if (arr[i] > 0)
			(*outPosArrSizePtr)++;

	*outPosArrPtr = new int[*outPosArrSizePtr];

	int posIndex = 0;

	for (int i = 0; i < arrSize; i++)
		if (arr[i] > 0)
			(*outPosArrPtr)[posIndex++] = arr[i];
}

void printArray(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}