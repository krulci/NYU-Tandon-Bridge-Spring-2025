#include <iostream>

using namespace std;

int main()
{
	int decimal, binary = 0, base = 1;
	cout << "Enter decimal number: " << endl;
	cin >> decimal;

	cout << "The binary representation of " << decimal;

	for (; decimal > 0; decimal /= 2)
	{
		binary += (decimal % 2) * base;
		base *= 10;
	}

	cout << " is " << binary << endl;

	return 0;
}