#include <iostream>

using namespace std;

int main()
{
	const int FLOOR_ROUND = 1;
	const int CEILING_ROUND = 2;
	const int ROUND = 3;

	double input;
	int method;

	cout << "Please enter a Real number:" << endl;
	cin >> input;

	cout << "Choose your rounding method:" << endl;
	cout << "1. Floor round" << endl;
	cout << "2. Ceiling round" << endl;
	cout << "3. Round to the nearest whole number" << endl;
	cin >> method;

	if (input == int(input))
		cout << input << endl;
	else
	{
		switch (method)
		{
			case FLOOR_ROUND:
				if (input > 0)
					cout << int(input) << endl;
				else
					cout << int(input - 1) << endl;
				break;
			case CEILING_ROUND:
				if (input > 0)
					cout << int(input + 1) << endl;
				else
					cout << int(input) << endl;
				break;
			case ROUND:
				if (input > 0)
					cout << int(input + 0.5) << endl;
				else
					cout << int(input - 0.5) << endl;
				break;
			default:
				break;
		}
	}

	return 0;
}