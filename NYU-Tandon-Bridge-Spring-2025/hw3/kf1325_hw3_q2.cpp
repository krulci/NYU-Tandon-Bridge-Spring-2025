#include <iostream>;

using namespace std;

int main()
{
	string name, status;
	int graduationYear, currentYear, yearToGraduate;

	cout << "Please enter your name: ";
	cin >> name;

	cout << "Please enter your graduation year: ";
	cin >> graduationYear;

	cout << "Please enter current year: ";
	cin >> currentYear;

	yearToGraduate = graduationYear - currentYear;

	if (yearToGraduate == 0)
		status = " Graduated";
	else if (yearToGraduate == 4)
		status = " a Freshman";
	else if (yearToGraduate == 3)
		status = " a Sophomore";
	else if (yearToGraduate == 2)
		status = " a Junior";
	else if (yearToGraduate == 1)
		status = " a Senior";
	else
		status = " not in college yet";

	cout << name << ", you are" << status << endl;
	return 0;
}