#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	bool nBigger;
	nBigger = n > m;

	cout << (n * nBigger) + ((!nBigger) * m);


}
