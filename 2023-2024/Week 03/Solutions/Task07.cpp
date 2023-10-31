#include <iostream>
using namespace std;

int main()
{
	int n, res;
	do
	{
		res = 0;
		cin >> n;

		while (n != 0)
		{
			res = res + (n % 10);
			n = n / 10;
		}


		if (res % 10 == 0)
			cout << "Bad number";
	} while (res % 10 != 0);

}