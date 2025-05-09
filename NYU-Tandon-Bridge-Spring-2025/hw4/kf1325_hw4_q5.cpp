#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "Please enter a positive integer: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}

		for (int k = 0; k < ((n - i) - 1) * 2 + 1; k++)
		{
			cout << "*";
		}

		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < ((n - i) - 1); j++)
		{
			cout << " ";
		}

		for (int k = 0; k < i * 2 + 1; k++)
		{
			cout << "*";
		}

		cout << endl;
	}
	return 0;
}