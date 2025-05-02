#include <iostream>

using namespace std;

void main()
{
	double weightRate = 0.453592, heightRate = 0.0254, weight, height, bmi;
	
	cout << "Please enter weight (in pounds): ";
	cin >> weight;
	weight *= weightRate;
	cout << "Please enter height (in inches): ";
	cin >> height;
	height *= heightRate;
	cout << "The weight status is: ";

	bmi = weight / (height * height);

	if (bmi < 18.5)
		cout << "Underweight";
	else if (bmi < 25)
		cout << "Normal";
	else if (bmi < 30)
		cout << "Overweight";
	else
		cout << "Obese";

	return;
}