#include <iostream>
using namespace std;

int main()
{
	const double EPSILON = 1e-6; // The same as 0.000001


	double inputNumber = 0;
	cin >> inputNumber;

	int numberWithoutDecimalPart = inputNumber;

	// We do not need the absolute value. Input number will always be larger than the number without decimal part
	if ((inputNumber - numberWithoutDecimalPart) < EPSILON)
	{
		cout << "Integer";
	}
	else
	{
		cout << "Not an integer";
	}
}
