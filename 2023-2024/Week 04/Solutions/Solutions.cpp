#include <iostream>
using namespace std;


//task1
unsigned absN(int n)
{
	if (n < 0)
		return -n;
	return n;
}

//task 2
bool isDigit(char a)
{
	return ((a >= '0') && (a <= '9'));
}

bool isLower(char a)
{
	return ((a >= 'a') && (a <= 'z'));
}

bool isUpper(char a)
{
	return ((a >= 'A') && (a <= 'Z'));
}

//task 3
char toUpper(char a)
{
	if (!isLower(a))
		return a;

	return a - 'a' + 'A';
}

char toLower(char a)
{
	if (!isUpper(a))
		return a;

	return a + 'a' - 'A';
}

//task 4
unsigned toNumber(char a)
{
	if (!isDigit(a))
		return a;

	return a - 48;
}

char toCharacter(int num)
{
	if (num > 9 || num < 0)
		return num;

	return num + '0';
}

//task 5
int power(int base, unsigned int exponent)
{
	int result = 1;

	if (!base)
		return base;

	if (!exponent)
		return exponent;

	for (unsigned i = 0; i < exponent; i++)
		result = result * base;

	return result;
}

//task 6
unsigned gcd(int n, int k)
{
	if (n < k)
	{
		int temp = n;
		n = k;
		k = temp;
	}

	while (k != 0)
	{
		int mod = n % k;
		n = k;
		k = mod;
	}

	return n;
}

//task 7
bool isPrime(int num)
{

	if (num <= 1)
		return false;

	bool isPrime = true;
	double rootOfNum = sqrt(num);

	for (unsigned i = 0; i <= rootOfNum; i++)
	{
		if (num % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	return isPrime;
}

//task 8
unsigned getLength(int number)
{
	unsigned result = 0;

	if (!number)
		return ++result;

	while (number != 0)
	{
		++result;
		number = number / 10;
	}

	return result;
}

//task 9
int getDigitOnPosition(int number, unsigned position)
{
	unsigned len = getLength(number);
	if (position > len)
		return -1;

	//We convert the number to possitive because if we have (-123, 1) the program will return -1
	number = absN(number);

	unsigned whereTo = len - position;
	for (unsigned i = 0; i < whereTo; i++)
		number = number / 10;

	return number % 10;
}

//task 10
unsigned lcm(int n, int k)
{
	if (n < 0)
		n = absN(n);
	if (k < 0)
		k = absN(k);

	return ((n * k) / gcd(n, k));
}

//task 11
unsigned concat(unsigned first, unsigned second)
{
	//Here we take advantage of the fact that the function takes 2 unsigned numbers and we don't need to look after corner cases
	first = first * power(10, getLength(second));
	return first + second;
}

//task 12
int sumInIntervalSlow(int start, int finish)
{
	int result = 0;
	for (int i = start; i <= finish; ++i)
		result += i;
	return result;
}

int sumInIntervalFast(int start, int finish)
{
	return ((finish - start + 1) * start + ((finish - start + 1) * (finish - start) / 2));
}

//task 13
bool isSquareRootVar1(int number)
{
	double root = sqrt(number), epsilon = 1e-6;

	int rootInt = root;
	return (root - rootInt < epsilon);
}

bool isSquareRootVar2(int number)
{
	double root = sqrt(number);
	int rootInt = root;
	return ((rootInt * rootInt) == number);
}


//task 14
bool isTriangleValid(unsigned a, unsigned b, unsigned c)
{
	return ((a + b > c) && (a + c > b) && (b + c > a));
}

unsigned getDist(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 * x2) + (y1 * y2));
}

unsigned perimeter(int x1, int y1, int x2, int y2, int x3, int y3)
{
	unsigned side1 = getDist(x1, y1, x2, y2);
	unsigned side2 = getDist(x1, y1, x3, y3);
	unsigned side3 = getDist(x2, y2, x3, y3);

	if (isTriangleValid(side1, side2, side3))
		return (getDist(x1, y1, x2, y2) + getDist(x1, y1, x3, y3) + getDist(x2, y2, x3, y3));

	return 0;
}

unsigned getArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	unsigned side1 = getDist(x1, y1, x2, y2);
	unsigned side2 = getDist(x1, y1, x3, y3);
	unsigned side3 = getDist(x2, y2, x3, y3);

	if (isTriangleValid(side1, side2, side3))
	{
		double p = (side1 + side2 + side3) / 2;
		return sqrt(p * (p - side1) * (p - side2) * (p - side3));
	}

	return 0;
}

bool isInCircleWithRadius(int x1, int y1, int x2, int y2, int x3, int y3, unsigned r)
{
	unsigned side1 = getDist(x1, y1, x2, y2);
	unsigned side2 = getDist(x1, y1, x3, y3);
	unsigned side3 = getDist(x2, y2, x3, y3);

	if (!isTriangleValid(side1, side2, side3))
		return false;

	return ((getDist(x1, y1, 0, 0) <= r) && (getDist(x2, y2, 0, 0) <= r) && (getDist(x3, y3, 0, 0) <= r));
}


//task 15
unsigned concatDigitAtBack(unsigned n, unsigned digit)
{
	return n * 10 + digit;
}

unsigned countDigitOccurences(unsigned n, unsigned digit)
{
	if (digit == 0 && n == 0)
		return 1;

	unsigned count = 0;
	while (n != 0)
	{
		int lastDigit = n % 10;
		if (lastDigit == digit)
			count++;
		n /= 10;
	}
	return count;
}

unsigned concatCountTimesDigit(unsigned a, unsigned digit, unsigned count)
{
	unsigned result = a;
	for (int i = 0; i < count; i++)
		result = concatDigitAtBack(result, digit);
	return result;
}

unsigned sortDigits(unsigned n)
{
	unsigned result = 0;
	for (int i = 9; i >= 0; i--)
	{
		unsigned count = countDigitOccurences(n, i);
		result = concatCountTimesDigit(result, i, count);
	}
	return result;
}

//task 16
bool isDivisableByValue(int number, int divisor)
{
	return (((number / divisor) * divisor) == number);
}

//task 17
unsigned getRemainder(int first, int second)
{
	return first - (first / second);
}

//task 18
int getDivision(int first, int second)
{
	bool negativeRes = ((first < 0 && second >= 0) || (first >= 0 && second < 0));
	first = absN(first);
	second = absN(second);
	
	first = first - (first % second);
	int result = 0;
	while (first != 0)
	{
		++result;
		first = first - second;
	}
	
	if (negativeRes)
		return -result;

	return result;
}

//task 19
unsigned squareRootToLower(int number)
{
	if (number < 1)
		return 0;

	unsigned result = 0;

	while ((result * result) <= number)
		result++;

	return --result;
}


int main()
{

}