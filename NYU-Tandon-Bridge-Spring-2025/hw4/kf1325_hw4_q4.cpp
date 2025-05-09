#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "section a" << endl;

	{

		int length, geometricProduct = 1, input;

		cout << "Please enter the length of the sequence: ";
		cin >> length;
		cout << "Please enter your sequence: " << endl;

		for (int i = 0; i < length; i++)
		{
			cin >> input;
			geometricProduct *= input;
		}

		cout.setf(ios::showpoint);
		cout.precision(5);

		cout << "The geometric mean is: " << pow(geometricProduct, 1 / (float)length) << endl;
	}

	cout << "section b" << endl;

	{

		int length = 0, geometricProduct = 1, input = 0;

		cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing - 1: " << endl;
		cin >> input;

		for (; input > 0; length++)
		{
			geometricProduct *= input;
			cin >> input;
		}

		cout.setf(ios::showpoint);
		cout.precision(5);

		cout << "The geometric mean is: " << pow(geometricProduct, 1 / (float)length) << endl;
	}
}