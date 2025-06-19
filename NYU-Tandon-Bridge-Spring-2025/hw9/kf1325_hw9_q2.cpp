#include <iostream>
#include <string>

using namespace std;

void analyzeSentence(const string& sentence, int statsArr[]);

auto areAnagrams = [](int anagram1[], int anagram2[], int n) -> bool
	{
		for (int i = 0; i < n; i++)
			if (anagram1[i] != anagram2[i])
				return false;
		return true;
	};

int main()
{
	const int ALPHA_SIZE = 26;
	int statsArr1[ALPHA_SIZE] = {};
	int statsArr2[ALPHA_SIZE] = {};
	string anagram1;
	string anagram2;

	cout
		<< "Please enter a line of text:"
		<< endl;

	getline(cin, anagram1);

	cout
		<< "Please enter a line of text:"
		<< endl;

	getline(cin, anagram2);

	analyzeSentence(anagram1, statsArr1);
	analyzeSentence(anagram2, statsArr2);

	(areAnagrams(statsArr1, statsArr2, ALPHA_SIZE))
		? cout
		<< "These two sentences are anagrams."
		: cout
		<< "These two sentences are not anagrams.";
}

void analyzeSentence(const string& sentence, int statsArr[])
{
	for (char c : sentence)
		if (isalpha(c))
			statsArr[toupper(c) - 'A']++;
}