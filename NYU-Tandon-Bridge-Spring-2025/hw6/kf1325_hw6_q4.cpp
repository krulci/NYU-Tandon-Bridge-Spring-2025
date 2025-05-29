#include <iostream>;

using namespace std;

void printDivisors(int num);

int main()
{
	int num = 0;

	while (!(num >= 2))
	{
		cout << "Please enter a poistive integer >= 2: " << endl;
		cin >> num;
	}

	printDivisors(num);
}

void printDivisors(int num)
{
	int i = 0;

	// i * (n / i) = n
	// 1, 100; 2, 50; 4, 25; 5, 20; 10, 20
	// For i > √n, its corresponding pair can be derived by n / i

	for (int i = 1; i < sqrt(num); i++)
	{
		if (num % i == 0)
		{
			cout << i << ' ';
		}
	}

	for (int i = sqrt(num); i >= 1; i--)
	{
		if (num % i == 0)
		{
			cout << num / i << ' ';
		}
	}
}