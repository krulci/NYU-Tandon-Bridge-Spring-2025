#include <iostream>
#include <string>

using namespace std;

bool isDigit(const string& s);

void obfuscateString(string& s);

int main()
{
	string input;

	cout
		<< "Please enter a line of text:"
		<< endl;

	getline(cin, input);

	obfuscateString(input);

	cout
		<< input
		<< endl;

	return 0;
}

bool isDigit(const string& s)
{
	for (char c : s)
		if (c < '0' || c > '9')
			return false;

	return true;
}

void obfuscateString(string& s)
{
	for (int i = 0, j = 0; i <= s.size(); i++)
		if ((s[i] == ' ') || i == s.size())
		{
			if (isDigit(s.substr(j, i - j)))
				for (; j < i; j++)
					s[j] = 'x';
			j = i + 1;
		}
}
