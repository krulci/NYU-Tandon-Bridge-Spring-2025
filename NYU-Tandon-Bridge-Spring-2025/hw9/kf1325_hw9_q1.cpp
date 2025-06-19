#include <iostream>
#include <string>

using namespace std;

int analyzeSentence(string sentence, int statsArr[]);

auto isLowerCase = [](char c) -> bool { return c >= 'a' && c <= 'z'; };

auto isUpperCase = [](char c) -> bool { return c >= 'A' && c <= 'Z'; };

auto isLetterChr = [](char c) -> bool { return isLowerCase(c) || isUpperCase(c); };

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
int analyzeSentence(string sentence, int statsArr[])
{
	int wordCounts = 0;
	int i = 0;
	bool wasLetter = false;

	for (char c : sentence)
	{
		if (isLetterChr(c))
		{
			statsArr[toupper(c) - 'A']++;
			if (!wasLetter)
			{
				wasLetter = true;
				wordCounts++;
			}
		}
		else
			wasLetter = false;
		i++;
	}

	return wordCounts;
}