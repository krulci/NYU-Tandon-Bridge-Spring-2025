#include <iostream>

using namespace std;

int minInArray1(int arr[], int arrSize);

int minInArray2(int arr[], int low, int high);

int main() {
	int arr[10] = { 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
	int res1, res2, res3, res4;

	res1 = minInArray1(arr, 10);
	res2 = minInArray2(arr, 0, 9);
	cout << res1 << " " << res2 << endl; //should both be -9

	res3 = minInArray2(arr, 2, 5);
	res4 = minInArray1(arr + 2, 4); //arr+2 is equivalent to &(arr[2])
	cout << res3 << " " << res4 << endl; //should both be 3
	 
	return 0;
}

// The ternary operator a < b ? a : b means :
//	If a is less than b, return a.
//	Otherwise, return b.
// When a == b, the condition a < b is false.
// Therefore, the expression returns b.

int minInArray1(int arr[], int arrSize)
{
	if (arrSize == 1)
		return arr[0];

	int minResult = minInArray1(arr, arrSize - 1);

	return 
		arr[arrSize - 1] < minInArray1(arr, arrSize - 1) 
		? arr[arrSize - 1] 
		: minResult;
}

// Be careful of the numbers of recursive calls made.
// k = number of recursive calls per step
// n = number of steps / levels / problem size
// The total number of calls grows exponentially as O(kⁿ).

int minInArray2(int arr[], int low, int high)
{
	if (low == high)
		return arr[high];

	int minResult = minInArray2(arr, low, high - 1);

	return 
		minResult < arr[high]
		? minResult
		: arr[high];
}
