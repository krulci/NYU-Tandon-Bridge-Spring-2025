#include <iostream>
#include <vector>

using namespace std;

// index 0 is minimum
// index 1 is maximum
template <typename T>
vector<T> divideAndConquer(const vector<T>& items);

int main()
{
	vector<int> integers = {
	   37, 82, 14, 65, 29, 91, 53, 7, 44, 68,
	   21, 56, 88, 13, 72, 39, 95, 60, 2, 50,
	   77, 31, 86, 11, 48, 63, 25, 79, 58, 17,
	   92, 35, 70, 8, 41, 84, 19, 66, 23, 99,
	   54, 27, 73, 46, 81, 16, 90, 33, 75, 5
	};

	try {
		vector<int> result = divideAndConquer(integers);
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

	vector<double> doubles = {
	   37.5, 82.1, 14.3, 65.7, 29.9, 91.2, 53.4, 7.8, 44.6, 68.0,
	   21.2, 56.5, 88.8, 13.9, 72.3, 39.6, 95.1, 60.4, 2.7, 50.5,
	   77.6, 31.3, 86.9, 11.4, 48.2, 63.8, 25.1, 79.7, 58.6, 17.5,
	   92.4, 35.8, 70.2, 8.3, 41.7, 84.9, 19.6, 66.1, 23.3, 99.0,
	   54.2, 27.7, 73.5, 46.8, 81.3, 16.2, 90.6, 33.9, 75.4, 5.1
	};

	try {
		vector<double> result = divideAndConquer(doubles);
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

template <typename T>
vector<T> divideAndConquer(const vector<T>& items)
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
		vector<T> item1(items.begin(), items.begin() + mid);
		vector<T> item2(items.begin() + mid, items.end());
		vector<T> result1 = divideAndConquer(item1);
		vector<T> result2 = divideAndConquer(item2);
		return { min(result1[0], result2[0]), max(result1[1], result2[1]) };
	}
}
