#include <iostream>;

using namespace std;

void printShiftedTriangle(int n, int m, char symbol);

void printPineTree(int n, char symbol);

int main()
{
	int n;
	char symbol;

	cout << "Input the number of triangles in the tree: ";
	cin >> n;
	cout << "Input the character filling the tree: ";
	cin >> symbol;

	printPineTree(n, symbol);

	return 0;
}

void printShiftedTriangle(int n, int m, char symbol)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << ' ';
		for (int j = 0; j < (n - i) - 1; j++)
			cout << ' ';
		for (int j = 0; j < (2 * i + 1); j++)
			cout << symbol;
		cout << endl;
	}
}

void printPineTree(int n, char symbol)
{
	for (int i = 0; i < n; i++)
		printShiftedTriangle(i + 2, (n - i) - 1, symbol);
}