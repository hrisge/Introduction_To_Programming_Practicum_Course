#include <iostream>
using namespace std;

//Task 1
void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

void swap(double& first, double& second)
{
	double temp = first;
	first = second;
	second = temp;
}

//Task 2
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

void simplify(int& numerator, int& denominator)
{
	unsigned toSimplifyWith = gcd(numerator, denominator);
	if (toSimplifyWith == 1)
		return;

	numerator = numerator / toSimplifyWith;
	denominator = denominator / toSimplifyWith;
}

unsigned absN(int n)
{
	if (n < 0)
		return -n;
	return n;
}

unsigned lcm(int n, int k)
{
	if (n < 0)
		n = absN(n);
	if (k < 0)
		k = absN(k);

	return ((n * k) / gcd(n, k));
}

void sum(int firstNumerator, int firstDenominator, int secondNumerator, int secondDenominator, int& resultNumerator, int& resultDenominator)
{
	resultNumerator = 0;
	resultDenominator = 1;
	simplify(firstNumerator, firstDenominator);
	simplify(secondNumerator, secondDenominator);

	resultDenominator = lcm(firstDenominator, secondDenominator);
	resultNumerator = (firstNumerator * (firstDenominator / resultDenominator)) + (secondNumerator * (secondDenominator / resultDenominator));
}

//Task 3
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

unsigned int reverse(unsigned int n)
{
	unsigned reversedNumber = 0;

	while (n != 0)
	{
		unsigned int lastDigit = n % 10;
		(reversedNumber *= 10) += lastDigit;
		n /= 10; //removes the last digit
	}
	return reversedNumber;

}


void removeAtIndex(int& n, int k)
{
	int len = getLength(n);
	if (len < k)
		return;

	int whereTo = len - k;
	int remainder = 0;
	for (unsigned i = 0; i < whereTo; ++i)
	{
		remainder = ((remainder * 10) + (n % 10));
		n = n / 10;
	}

	remainder = reverse(remainder);
	n = n / 10;
	n = (n * power(10, whereTo)) + remainder;
}

//Task 4

void splitInOddsAndEvens(int number, int& resultEven, int& resultOdd)
{
	resultEven = 0;
	resultOdd = 0;
	unsigned reversedNum = reverse(number);
	bool isCurrentPosOdd = true;
	while (reversedNum != 0)
	{
		unsigned digitToAdd = reversedNum % 10;
		reversedNum = reversedNum / 10;

		if (isCurrentPosOdd)
		{
			resultOdd = resultOdd * 10 + digitToAdd;
			isCurrentPosOdd = false;
			continue;
		}

		resultEven = resultEven * 10 + digitToAdd;
		isCurrentPosOdd = true;
	}
}

//Task 5
void cutNumberInInterval(int& number, unsigned i, unsigned j)
{
	unsigned len = getLength(number);
	if (j > len || i >= j)
		return;

	number = number % power(10, (len - i + 1));
	number = number / power(10, (len - j));
}

//Task 6
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

//This solution could be optimised by not using getDigitOnPosition
void swapDigitsOnPos(int& n, int& m, int index)
{
	unsigned lenN = getLength(n), lenM = getLength(m);
	if (index >= lenN || index >= lenM)
		return;

	unsigned digitN = getDigitOnPosition(n, index), digitM = getDigitOnPosition(m, index);
	unsigned cutterN = power(10, lenN - index), cutterM = power(10, lenM - index);
	unsigned remainderN = n % cutterN, remainderM = m % cutterM;

	n = n / (cutterN * 10);
	m = m / (cutterM * 10);

	n = n * 10 + digitM;
	m = m * 10 + digitN;

	n = n * cutterN + remainderN;
	m = m * cutterM + remainderM;
}

//Task 7
bool validationOfANumber(int number, int n, int& countOfZeros)
{
	while (number != 0)
	{
		int digit = number % 10;
		if (digit == 1)
		{
			n--;
			number = number / 10;
			continue;
		}
		else if (digit == 0)
		{
			n--;
			countOfZeros++;
			number = number / 10;
			continue;
		}

		return false;
	}

	countOfZeros += n;
	return (n >= 0);
}

bool validationOfTwoNumbers(int first, int second, int n)
{
	int zerosInFirst = 0, zerosInSecond = 0;
	bool okFirst = validationOfANumber(first, n, zerosInFirst);
	bool okSecond = validationOfANumber(second, n, zerosInSecond);

	return okFirst && okSecond && (zerosInFirst == zerosInSecond);
}

int counterOfMissmatchedZeros(int first, int second, int n)
{
	int result = 0;
	while (n != 0)
	{
		int lastDigitOfFirst = first % 10, lastDigitOfSecond = second % 10;
		if (!lastDigitOfFirst)
		{
			if (lastDigitOfFirst != lastDigitOfSecond)
				result++;
		}

		first = first / 10;
		second = second / 10;
		n--;
	}

	return result;
}

int countOfSwaps()
{
	int n;
	cin >> n;
	int first, second;
	cin >> first >> second;

	bool okay = validationOfTwoNumbers(first, second, n);

	if (okay)
		return counterOfMissmatchedZeros(first, second, n);

	return -1;
}

int main()
{

}