#include <iostream>
using namespace std;

int main()
{
    unsigned int count = 0;
    cin >> count;

	unsigned int sum = 0;
	unsigned int max = 0;
	for (size_t i = 0; i < count; i++)
	{
		unsigned int current = 0;
		cin >> current;

		if (max < current)
		{
			max = current;
		}

		sum += current;
	}

	if (sum - max == max)
	{
		cout << "Yes: " << max;
	}
	else
	{
		cout << "No";
	}
}