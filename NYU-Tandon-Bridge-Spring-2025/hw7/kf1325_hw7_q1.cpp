#include <iostream>;

using namespace std;

int printMonthCalender(int numOfDays, int startingDay);

void printYearCalender(int year, int startingDay);

bool isLeapYear(int year);

int main()
{
	int year, startingDay;
	cout << "Input a year and a starting day separated by space: ";
	cin >> year >> startingDay;
	printYearCalender(year, startingDay);

	return 0;
}

int printMonthCalender(int numOfDays, int startingDay)
{
	cout << "Mon\tTue\tWed\tThu\tFri\tSat\tSun" << endl;

	for (int i = 0; (i + 1) < startingDay; i++)
		cout << "\t";

	for (int i = 0; i < numOfDays; i++)
		((startingDay + i) % 7 == 0)
		? cout << (i + 1) << endl
		: (((i + 1) == numOfDays)
			? cout << (i + 1) << endl
			: cout << (i + 1) << "\t");

	cout << endl;

	return 
		(((startingDay + numOfDays - 1) % 7) == 0) 
		? 7 
		: ((startingDay + numOfDays - 1) % 7);
}

void printYearCalender(int year, int startingDay)
{
	for (int i = 0; i < 12; i++)
	{
		switch (i + 1)
		{
			case 1:
				cout << "January " << year << endl;
				break;
			case 2:
				cout << "February " << year << endl;
				break;
			case 3:
				cout << "March " << year << endl;
				break;
			case 4:
				cout << "April " << year << endl;
				break;
			case 5:
				cout << "May " << year << endl;
				break;
			case 6:
				cout << "June " << year << endl;
				break;
			case 7:
				cout << "July " << year << endl;
				break;
			case 8:
				cout << "August " << year << endl;
				break;
			case 9:
				cout << "September " << year << endl;
				break;
			case 10:
				cout << "October " << year << endl;
				break;
			case 11:
				cout << "November " << year << endl;
				break;
			case 12:
				cout << "December " << year << endl;
				break;
		}

		switch (i + 1)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: startingDay = printMonthCalender(31, startingDay);
				break;
			case 4:
			case 6:
			case 9:
			case 11: startingDay = printMonthCalender(30, startingDay);
				break;
			default: startingDay = printMonthCalender(isLeapYear(year) ? 29 : 28, startingDay);
				break;
		}

		startingDay = ((startingDay % 7) == 0) ? 1 : (startingDay + 1);
	}
}

bool isLeapYear(int year)
{
	return 
		(year % 4 == 0)
		? ((year % 100 == 0)
			? ((year % 400 == 0)
				? true
				: false)
			: true)
		: false;
}
