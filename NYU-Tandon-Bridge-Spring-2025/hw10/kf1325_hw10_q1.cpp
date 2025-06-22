#include <iostream>
#include <string>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main()
{
	string sentence;

	cout
		<< "Please input a sentence:"
		<< endl;

	getline(cin, sentence);

	int outWordsArrSize;
	auto words = createWordsArray(sentence, outWordsArrSize);

	cout
		<< "[";

	for (int i = 0; i < outWordsArrSize; i++)
	{
		cout
			<< "\""
			<< words[i]
			<< "\"";
		if (i != (outWordsArrSize - 1))
			cout
			<< ", ";
	}

	cout
		<< "]"
		<< endl;

	cout
		<< "outWordsArrSize: "
		<< outWordsArrSize
		<< endl;

	delete[] words;
}

string* createWordsArray(string sentence, int& outWordsArrSize)
{
	outWordsArrSize = 0;
	bool wasAlpha = false;
	string* words = new string[sizeof(sentence) / sizeof(sentence[0])];

	for (char c : sentence)
		if (!isspace(c))
		{
			if (!wasAlpha)
			{
				wasAlpha = true;
				++outWordsArrSize;
			}
			words[outWordsArrSize - 1] += c;
		}
		else
			wasAlpha = false;

	return words;
}
