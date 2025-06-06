#include <iostream>

using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);

bool isPerfect(int num);

int outCountDivs;

int outSumDivs;

int main()
{
	int num;

	cout << "Input a positive integer M (>=2): " << endl;
	cout << ">> ";
	cin >> num;
	cout << "Printing all perfect numbers between 2 and M, "
		<< "and all pairs of amicable numbers that are between 2 and M (both numbers wil be in the range): " << endl;

	for (int i = 0; i < num; i++)
	{
		if ((i + 1) <= 2)
			continue;

		if (isPerfect(i + 1))
			cout << (i + 1) << " is a perfect number." << endl;
		else if ((i + 1) < outSumDivs)
		{
			int _outCountDivs, _outSumDivs;

			analyzeDividors(outSumDivs, _outCountDivs, _outSumDivs);
			if ((i + 1) == _outSumDivs)
				cout << "(" << (i + 1) << ", " << outSumDivs << ") are amicable numbers." << endl;
		}
	}

	return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{
	outCountDivs = -1;
	outSumDivs = -num;

	for (int i = 1; i < sqrt(num); i++)
	{
		if (num % i == 0)
		{
			outCountDivs++;
			if (i == (num / i))
				outSumDivs += i;
			else
			{
				outCountDivs++;
				outSumDivs += (i + (num / i));
			}
		}
	}
}

bool isPerfect(int num)
{
	if (num <= 2)
		return false;

	analyzeDividors(num, outCountDivs, outSumDivs);

	return (num == outSumDivs);
}
