#include <iostream>
#include <string>

using namespace std;

int analyzeSentence(const string& sentence, int statsArr[]);

int main()
{
	const int ALPHA_SIZE = 26;
	int statsArr[ALPHA_SIZE] = {};
	string input;

	cout
		<< "Please enter a line of text:"
		<< endl;

	getline(cin, input);

	cout
		<< analyzeSentence(input, statsArr)
		<< "\t"
		<< "words"
		<< endl;

	for (int i = 0; i < ALPHA_SIZE; i++)
	{
		if (statsArr[i] != 0)
		{
			cout
				<< statsArr[i]
				<< "\t"
				<< (char)(i + 97)
				<< endl;
		}
	}

}

// Words are defined as any string of letters
int analyzeSentence(const string& sentence, int statsArr[])
{
	int wordCounts = 0;
	bool wasAlpha = false;

	for (char c : sentence)
	{
		if (isalpha(c))
		{
			statsArr[toupper(c) - 'A']++;
			if (!wasAlpha)
			{
				wasAlpha = true;
				++wordCounts;
			}
		}
		else
			wasAlpha = false;
	}

	return wordCounts;
}