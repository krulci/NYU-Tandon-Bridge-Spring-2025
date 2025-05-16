#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int num, guess, min = 1, max = 100, count = 5;

	srand(time(0));

#ifdef _DEBUG
	num = 25;
#else
	num = (rand() % 100) + 1;
#endif

	cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

	while (count > 0)
	{
		cout << "Range: [" << min << ", " << max << "], Number of guesses left : " << count << endl;
		cout << "Your guess: ";
		cin >> guess;
		if (guess != num)
		{
			(count == 1)
				? cout << "Out of guesses! My number is " << num << endl
				: cout << "Wrong! My number is " << (guess < num ? "bigger." : "smaller.") << endl;

			if (!(guess < min) && !(guess > max))
				if (guess < num)
					min = guess + 1;
				else
					max = guess - 1;
		}
		else
		{
			cout << "Congrats! You guessed my number in " << count << " guesses." << endl;
			break;
		}
		count--;
		cout << endl;
	}
}