#include <iostream>
#include<map>

using namespace std;

int main()
{
	string dayOfWeek;
	double rate;
	int hours, minutes, lengthOfCall, time;
	char colon;

	cout << "Please enter the day of the week read as one of the following two character string: Mo Tu We Th Fr Sa Su: " << endl;
	cin >> dayOfWeek;

	cout << "Please enter the time the call started in 24-hour notation, so the time 1:30 P.M. is input as 13:30: " << endl;
	cin >> hours >> colon >> minutes;
	time = 60 * hours + minutes;

	cout << "Please enter the length of the call in minutes: " << endl;
	cin >> lengthOfCall;

	if (dayOfWeek == "Mo" || dayOfWeek == "Tu" || dayOfWeek == "We" || dayOfWeek == "Th" || dayOfWeek == "Fr")
		if (time >= 8 * 60 && time < 18 * 60)
			rate = 0.40;
		else
			rate = 0.25;
	else
		rate = 0.15;

	cout << "The cost of the call is " << lengthOfCall * rate << endl;
	return 0;
}