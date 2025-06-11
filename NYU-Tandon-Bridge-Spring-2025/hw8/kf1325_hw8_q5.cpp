#include <iostream>;

using namespace std;

int main()
{
	string nameArr[3];

	cout 
		<< "Please input your name in the following format: \n"
		<< "first name, then middle name or initial, and then last name."
		<< endl;

	cin >> nameArr[0] >> nameArr[1] >> nameArr[2];

	cout
		<< nameArr[2]
		<< ", "
		<< nameArr[0]
		<< " "
		<< nameArr[1][0]
		<< ". "
		<< endl;

	return 0;
}