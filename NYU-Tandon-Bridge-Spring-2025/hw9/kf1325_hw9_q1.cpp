#include <iostream>
#include <string>

using namespace std;

int analyzeSentence(string sentence, int statsArr[]);

auto isDelimiter = [](char c) -> bool { return c == ' ' || c == '.' || c == ','; };

auto isLowerCase = [](char c) -> bool { return c >= 'a' && c <= 'z'; };

auto isUpperCase = [](char c) -> bool { return c >= 'A' && c <= 'Z'; };

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

int analyzeSentence(string sentence, int statsArr[])
{
	int wordCounts = 0;
	int i = 0;

	for (char c : sentence)
	{
		if (isDelimiter(c) || i == (sentence.length() - 1))
			wordCounts++;
		if (isLowerCase(c))
			statsArr[c - 'a']++;
		if (isUpperCase(c))
			statsArr[c - 'A']++;
		i++;
	}

	return wordCounts;
}