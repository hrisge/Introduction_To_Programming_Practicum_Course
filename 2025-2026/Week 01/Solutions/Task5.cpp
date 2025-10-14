#include <iostream>
using namespace std;

int main()
{
    int x1, x2, x3, x4, x5;
    cin >> x1 >> x2 >> x3 >> x4 >> x5;
    int sum = 0;
    sum = (x1 * (x1 % 2)) + (x2 * (x2 % 2)) + (x3 * (x3 % 2)) + (x4 * (x4 % 2)) + (x5 * (x5 % 2));
    cout << sum;
}
