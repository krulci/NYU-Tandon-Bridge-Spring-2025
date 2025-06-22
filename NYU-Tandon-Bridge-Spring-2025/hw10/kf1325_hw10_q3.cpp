#include <iostream>
#include <vector>

using namespace std;

void main1();

void main2();

int main()
{
	main1();
	main2();
}

// actually you don't need two delimiter ", ", but I feel like to use it.

void main1()
{
	cout
		<< "Please enter a sequence of positive integers, each in a separate line."
		<< endl
		<< "End you input by typing -1."
		<< endl;

	string num;
	string nums;

	while (true)
	{
		cin
			>> num;

		if (num != "-1")
			nums += (num + ", ");
		else
			break;
	}

	cout
		<< "Please enter a number you want to search."
		<< endl;

	cin
		>> num;

	cout
		<< num
		<< " shows in lines ";

	string curNum;
	bool dontUseComma = false;

	for (int i = 0, j = 0; i < nums.size(); i++)
	{
		if (isspace(nums[i]))
			curNum = "";
		else if (isdigit(nums[i]))
			curNum += nums[i];
		else
		{
			if (curNum == num)
				(!dontUseComma++)
				? cout << (j + 1)
				: cout << ", " << (j + 1);
			j++;
		}
	}

	cout
		<< "."
		<< endl;
}

void main2()
{
	cout
		<< "Please enter a sequence of positive integers, each in a separate line."
		<< endl
		<< "End you input by typing -1."
		<< endl;

	int num;
	vector<int> nums;

	while (true)
	{
		cin
			>> num;

		if (num != -1)
			nums.push_back(num);
		else
			break;
	}

	cout
		<< "Please enter a number you want to search."
		<< endl;

	cin
		>> num;

	cout
		<< num
		<< " shows in lines ";

	bool dontUseComma = false;
	int j = 0;

	for (int curNum : nums)
	{
		if (curNum == num)
			(!dontUseComma++)
			? cout << (j + 1)
			: cout << ", " << (j + 1);
		j++;
	}

	cout
		<< "."
		<< endl;
}
