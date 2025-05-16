#include <iostream>

using namespace std;

int main()
{
	int num;

	cout << "Please enter a positive integer: ";
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			cout << (i + 1) * (j + 1) << "\t";
		cout << endl;
	}

	return 0;
}