#include <iostream>

using namespace std;

int lowestCost(int arr[], int pos, int arrSize);

int main()
{
	int arr[] = { 0, 3, 80, 6, 57, 10 };
	int n = 6;

	int value = lowestCost(arr, 0, n);

	cout
		<< value
		<< endl;
}

int lowestCost(int arr[], int pos, int arrSize)
{
    if (pos >= arrSize - 1)
        return arr[arrSize - 1];

    if (pos == arrSize - 2)
        return arr[pos] + arr[pos + 1];

    int moveOne = lowestCost(arr, pos + 1, arrSize);
    int moveTwo = lowestCost(arr, pos + 2, arrSize);

    return arr[pos] + (moveOne < moveTwo ? moveOne : moveTwo);
}
