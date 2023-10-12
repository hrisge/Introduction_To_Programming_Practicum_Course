#include <iostream>
using namespace std;

int main()
{
	float a, b, c;
	cin >> a >> b >> c;

	cout << (a + b > c) && (a + c > b) && (b + c > a);
}
