#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double valA, valB, valC;
	double determinant;

	cout << "Please enter value of a: ";
	cin >> valA;
	cout << "Please enter value of b: ";
	cin >> valB;
	cout << "Please enter value of c: ";
	cin >> valC;

	cout << "This equation has";


	determinant = valB * valB - 4 * valA * valC;

	cout.setf(cout.fixed);
	cout.setf(cout.showpoint);
	cout.precision(1);

	if (valA == 0)
		if (valB == 0)
			if (valC != 0)
				cout << " no solution";
			else
				cout << " infinite number of solutions";
		else
			cout << " one real solution x = " << -valC / valB;
	else
		if (determinant > 0)
			cout << " two real solutions x = " << (-valB + sqrt(determinant)) / (2 * valA) << ", and x = " << (-valB - sqrt(determinant)) / (2 * valA);
		else if (determinant == 0)
			cout << " one real solution x = " << -valB / (2 * valA);
		else
			cout << " no real solution";

	cout << endl;
	return 0;
}