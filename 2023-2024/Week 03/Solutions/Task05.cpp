#include <iostream>
using namespace std;

int main()
{
	unsigned n, m;
	cin >> n >> m;

	while (n < 0 || n > 255 || m < 0 || m>255)
	{
		cout << "Ivalid input. Try again!";
		cin >> n >> m;
	}

	for (int i = n; i <= m; i++)
	{
		char a = i;
		cout << a << endl;
	}
}