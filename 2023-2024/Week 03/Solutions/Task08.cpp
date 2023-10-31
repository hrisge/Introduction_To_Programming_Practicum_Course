#include <iostream>
using namespace std;

int main()
{
	unsigned h1, h2, min1, min2;
	cin >> h1 >> min1 >> h2 >> min2;

	//We won't check if the input is valid

	for (int i = min1; i < 60; i++)
		cout << h1 << ':' << i << endl;

	for (int i = h1; i < h2; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			if (j < 10)
				cout << i << ":0" << j << endl;

			else
				cout << i << ':' << j << endl;
		}
	}

	for (int i = 0; i < min2; i++)
	{
		if (i < 10)
			cout << h2 << ":0" << i << endl;

		else
			cout << h2 << ':' << i << endl;
	}
}