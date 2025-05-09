#include <iostream>

using namespace std;

int main()
{
	{
		cout << "section a" << endl;
		int n;

		cout << "Please enter a positive integer: ";
		cin >> n;

		int i = 0;
		while (i < n)
		{
			cout << 2 * (i + 1)	<< endl;
			i++;
		}
	}

	{
		cout << "section b" << endl;
		int n;

		cout << "Please enter a positive integer: ";
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cout << 2 * (i + 1) << endl;
		}
	}

	return 0;
}