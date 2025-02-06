#include <iostream>
using namespace std;

int main()
{
	double element = 1.0 / 2;
	unsigned int count = 0;
	cin >> count;

	for (size_t i = 0; i < count; i++)
	{
		element = (element * element + 1) / 2;
	}

	cout << element;
}