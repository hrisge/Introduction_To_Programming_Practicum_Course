#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int hundreds = n / 100;
	n = n % 100;

	int tens = n / 10;
	n = n % 10;

	int res = n * 100 + tens * 10 + hundreds + 1;
	cout << res;
}
