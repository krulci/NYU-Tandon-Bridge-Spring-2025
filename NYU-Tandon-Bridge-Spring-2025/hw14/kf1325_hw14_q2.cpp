#include <iostream>
#include <vector>

using namespace std;

// index 0 is minimum
// index 1 is maximum
vector<int> divideAndConquer(const vector<int>& items);

int main()
{
	vector<int> items = {
	   37, 82, 14, 65, 29, 91, 53, 7, 44, 68,
	   21, 56, 88, 13, 72, 39, 95, 60, 2, 50,
	   77, 31, 86, 11, 48, 63, 25, 79, 58, 17,
	   92, 35, 70, 8, 41, 84, 19, 66, 23, 99,
	   54, 27, 73, 46, 81, 16, 90, 33, 75, 5
	};

	try {
		vector<int> result = divideAndConquer(items);
		cout 
			<< "Minimum: " 
			<< result[0] 
			<< endl;
		cout 
			<< "Maximum: " 
			<< result[1] 
			<< endl;
	}
	catch (const exception& e) {
		cout 
			<< "Error: " 
			<< e.what() 
			<< endl;
	}
	return 0;
}

vector<int> divideAndConquer(const vector<int>& items)
{
	if (items.empty())
		throw invalid_argument("Input vector must not be empty!");
	else if (items.size() == 1)
		return { items[0], items[0] };
	else if (items.size() == 2)
	{
		if (items[0] > items[1])
			return { items[1], items[0] };
		else
			return items;
	}
	else
	{
		int mid = items.size() / 2;
		vector<int> item1(items.begin(), items.begin() + mid);
		vector<int> item2(items.begin() + mid, items.end());
		vector<int> result1 = divideAndConquer(item1);
		vector<int> result2 = divideAndConquer(item2);
		return { min(result1[0], result2[0]), max(result1[1], result2[1]) };
	}
}
