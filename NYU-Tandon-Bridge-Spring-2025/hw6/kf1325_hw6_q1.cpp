#include <iostream>

using namespace std;

int fib(int range);

int main()
{
	int range;
	cout << "Please enter a positive integer: ";
	cin >> range;
	cout << fib(range) << endl;

	return 0;
}

int fib(int range)
{
	/*cout << 1 << endl;*/
	if (range > 1)
	{
		int num1 = 0, num2 = 1, numF = 0;
		for (int i = 1; i < range; i++)
		{
			numF = num1 + num2;
			num1 = num2;
			num2 = numF;
			/*cout << numF << endl;*/
		}
		return numF;
	}
	else
		return 1;
}