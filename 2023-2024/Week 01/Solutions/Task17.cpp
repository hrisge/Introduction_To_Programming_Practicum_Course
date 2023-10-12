#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	(n < 10 && cout << n) || (n < 100 && cout << (n % 10) + 1) || (cout << (n / 10));

}
