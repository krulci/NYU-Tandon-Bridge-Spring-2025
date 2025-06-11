#include <iostream>;

using namespace std;

bool isPalindrome(string str);

int main()
{
#ifdef _DEBUG
debugFlag:
#endif

	string str;

	cout
		<< "Please enter a word: ";

	cin >> str;

	cout
		<< str
		<< " is";

	(isPalindrome(str))
		? cout << " "
		: cout << " not ";

	cout
		<< "a palindrome"
		<< endl;

#ifdef _DEBUG
	goto debugFlag;
#endif

	return 0;
}

bool isPalindrome(string str)
{
	return str.length() < 2
		? true
		: (str[0] == str[str.length() - 1]) && isPalindrome(str.substr(1, str.length() - 2));
}
