#include <iostream>
using namespace std;

void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

unsigned int gcd(unsigned int first, unsigned int second)
{
	if (first < second)
	{
		swap(first, second);
	}

	while (second != 0)
	{
		int temp = first % second;
		first = second;
		second = temp;
	}

	return first;
}

int main()
{
	unsigned int elementsCount = 0;
	cin >> elementsCount;

	if (elementsCount == 0)
	{
		cout << "No input given!";
		return 0;
	}

	unsigned int totalGcd = 0;
	cin >> totalGcd;

	for (size_t i = 1; i < elementsCount; i++)
	{
		unsigned int currentElement = 0;
		cin >> currentElement;

		totalGcd = gcd(totalGcd, currentElement);
	}

	cout << (totalGcd == 1);

	return 0;
}