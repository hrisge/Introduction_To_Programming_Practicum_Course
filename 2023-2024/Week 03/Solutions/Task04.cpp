#include <iostream>
using namespace std;

int main()
{
	unsigned n, m, result = 0;

	cin >> n >> m;

	if (m < n)
	{
		unsigned temp = m;
		m = n;
		n = temp;
	}

	for (unsigned i = n; i <= m; i++)
	{
		bool isPrime = true;
		double sqrtOfNumberToCheck = sqrt(i);

		for (int j = 2; j <= sqrtOfNumberToCheck; j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
			result += i;
	}

	cout << result;


}