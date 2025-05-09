#include <iostream>

using namespace std;

int main()
{
	float priceOfItem1, priceOfItem2, taxRate, basePrice, discountedPrice, totalPrice;
	char isMember;

	cout << "Enter price of first item: ";
	cin >> priceOfItem1;

	cout << "Enter price of second item: ";
	cin >> priceOfItem2;

	cout << "Does customer have a club card? (Y/N): ";
	cin >> isMember;

	cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
	cin >> taxRate;

	basePrice = priceOfItem1 + priceOfItem2;

	discountedPrice = priceOfItem1 < priceOfItem2 ? priceOfItem1 * 0.5 + priceOfItem2 : priceOfItem1 + priceOfItem2 * 0.5;
	discountedPrice = (1 - ((isMember == 'Y' || isMember == 'y') ? 0.10 : 0)) * discountedPrice;

	totalPrice = discountedPrice * (1 + taxRate / 100);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);
	cout << "Base price: " << basePrice << endl;
	cout << "Price after discounts: " << discountedPrice << endl;
	cout.precision(5);
	cout << "Total price: " << totalPrice << endl;

	return 0;
}