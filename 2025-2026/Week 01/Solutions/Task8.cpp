#include <iostream>
using namespace std;

int main()
{
	char a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	cout << (((a + b + c + d + e + f) % 3) == 0);
}
