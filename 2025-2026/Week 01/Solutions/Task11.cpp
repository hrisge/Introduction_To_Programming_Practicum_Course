#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	// Тук разчитаме, че входните данни са валидни интервали, т.е. нямаме интервал от вида [10, 5]
	return (a < c && c < b) || (a < d && d < b);

}
