#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "Please enter a positive integer: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int currentNumber = i + 1, oddDigitCounter = 0, evenDigitCounter = 0;

		while (currentNumber > 0)
		{
			if (currentNumber % 2 == 0)
				evenDigitCounter++;
			else
				oddDigitCounter++;
			currentNumber /= 10;
		}

		if (evenDigitCounter > oddDigitCounter)
			cout << i + 1 << endl;
	}
	return 0;
}