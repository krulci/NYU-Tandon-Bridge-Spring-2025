#include <iostream>

using namespace std;

void printTriangle(int n);

void printOppositeTriangles(int n);

void printRuler(int n);

int main()
{
	int n = 4;

	cout
		<< "void printTriangle(int n);"
		<< endl;

	printTriangle(n);

	cout
		<< endl;

	cout
		<< "void printOppositeTriangles(int n);"
		<< endl;

	printOppositeTriangles(n);

	cout
		<< endl;

	cout
		<< "void printRuler(int n);"
		<< endl;

	printRuler(n);

	cout
		<< endl;

	return 0;
}

void printTriangle(int n)
{
	if (n == 0)
		return;
	else
	{
		printTriangle(n - 1);

		for (int i = 0; i < n; i++)
			cout
			<< "*";

		cout
			<< endl;
	}
}

void printOppositeTriangles(int n)
{
	if (n != 0)
	{
		for (int i = 0; i < n; i++)
			cout
			<< "*";

		cout
			<< endl;

		printOppositeTriangles(n - 1);

		for (int i = 0; i < n; i++)
			cout
			<< "*";

		cout
			<< endl;
	}
}

void printRuler(int n)
{
	if (n == 0)
		return;

	printRuler(n - 1);

	for (int i = 0; i < n; i++)
		cout
		<< "-";
	cout
		<< endl;

	printRuler(n - 1);
}
