#include <iostream>;

using namespace std;

const int PIN[5] = { 1, 2, 3, 4, 5 };

const int PIN_DIGIT = 5;

void generatePinObfuscator(int obfuscator[]);

bool validatePin(int obfuscatedInput, int obfuscator[]);

void printArray(int arr[], int arrSize);

int main()
{
	int obfuscatedInput;
	int obfuscator[10];

	generatePinObfuscator(obfuscator);

	cout
		<< "Please enter your PIN according to the following mapping: "
		<< endl
		<< "PIN:\t0 1 2 3 4 5 6 7 8 9"
		<< endl
		<< "NUM:\t";

	printArray(obfuscator, 10);

	cout
		<< endl;

	cin >> obfuscatedInput;

	(validatePin(obfuscatedInput, obfuscator))
		? cout << "Your PIN is correct"
		: cout << "Your PIN is not correct";
}

void generatePinObfuscator(int obfuscator[])
{
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
		obfuscator[i] = rand() % (9 - 0 + 1);
}

bool validatePin(int obfuscatedInput, int obfuscator[])
{
	int obfuscatedPin = 0;

	for (int i = 0; i < PIN_DIGIT; i++)
		obfuscatedPin = 10 * obfuscatedPin + obfuscator[PIN[i]];

	return obfuscatedPin == obfuscatedInput;
}

void printArray(int arr[], int arrSize)
{
	int i;
	for (i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}
