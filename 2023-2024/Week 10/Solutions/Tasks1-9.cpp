#include <iostream>
using namespace std;

const constexpr int LETTERS = 'z' - 'a' + 1;
const constexpr int DIGITS = 10;
const constexpr int MAX_SIZE = 1024;

int strLen(const char* str)
{
	if (!str)
		return 0;

	unsigned result = 0;
	while (*str)
	{
		result++;
		str++;
	}
	return result;
}

//Task 1
bool isPalindrome(const char* arr)
{
	if (!arr)
		return 0;

	unsigned len = strLen(arr);
	const char* end = arr + len - 1;

	while (arr < end)
	{
		if (*arr != *end)
			return false;

		arr++;
		end--;
	}

	return true;
}

//Task 2
void smallToCapital(char& ch)
{
	ch = ch - 'a' + 'A';
}

void capitalToSmall(char& ch)
{
	ch = ch + 'a' - 'A';
}

bool isLetterSmall(char ch)
{
	return ('a' <= ch && ch <= 'z');
}

bool isLetterCapital(char ch)
{
	return ('A' <= ch && ch <= 'Z');
}

void convertStringLetters(char* str)
{
	if (!str)
		return;

	while (*str)
	{
		if (isLetterSmall(*str))
			smallToCapital(*str);
		else if (isLetterCapital(*str))
			capitalToSmall(*str);

		str++;
	}
}

//Task 3
void fillBoolWithZeros(bool* arr, int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = false;
}

bool areLettersUnique(const char* str)
{
	if (!str)
		return false;

	bool letters[LETTERS];
	fillBoolWithZeros(letters, LETTERS);

	while (*str)
	{
		if (letters[*str - 'a'] == true)
			return false;
		else
			letters[*str - 'a'] = true;

		str++;
	}

	return true;
}

//Task 4
void insertLetter(const char* text, char* result, char symbol, int index)
{
	if (!text || !result)
		return;

	for (int i = 0; i < index; i++)
		result[i] = text[i];

	result[index] = symbol;
	text += index;
	result = result + index + 1;
	
	while (*text)
	{
		*result = *text;
		result++;
		text++;
	}

	*result = '\0';
}

//Task 5
void fillIntegerWithZeros(int* array, int size)
{
	for (int i = 0; i < size; i++)
		array[i] = 0;
}

int convertCharToInt(char ch)
{
	return  ch - '0';
}

char convertIntToChar(int num)
{
	return num + '0';
}

int reverseNumber(int number)
{
	int res = 0;
	while (number != 0)
	{
		res = 10 * res + (number % 10);
		number = number / 10;
	}
	return res;
}

void digitOccurrences(const char* str, char* result)
{
	if (!str || !result)
		return;

	int digitsCount[DIGITS];
	fillIntegerWithZeros(digitsCount, DIGITS);

	while (*str)
	{
		digitsCount[convertCharToInt(*str)]++;
		str++;
	}

	int indexToFill = 0;
	for (int i = 0; i < DIGITS; i++)
	{
		int reversedNum = reverseNumber(digitsCount[i]);
		do
		{
			result[indexToFill] = convertIntToChar(reversedNum % 10);
			reversedNum = reversedNum / 10;
			indexToFill++;
		} while (reversedNum != 0);

		result[indexToFill++] = 'x';
		result[indexToFill++] = convertIntToChar(i);
		result[indexToFill++] = ',';
	}
	result[indexToFill] = '\0';
}

//Task 6 
void difference(const char* str1, const char* str2, char* res)
{
	if (!str1 || !str2 || !res)
		return;

	bool letters1[LETTERS];
	bool letters2[LETTERS];

	fillBoolWithZeros(letters1, LETTERS);
	fillBoolWithZeros(letters2, LETTERS);

	while (*str1)
	{
		letters1[convertCharToInt(*str1)] = true;
		str1++;
	}

	while (*str2)
	{
		letters2[convertCharToInt(*str2)] = true;
		str2++;
	}

	for (int i = 0; i < LETTERS; i++)
	{
		if (letters1[i] != letters2[i])
		{
			*res = i + 'a';
			res++;
		}
	}

	*res = '\0';
}

//Task 7
void capitalWords(char* str)
{
	if (!str)
		return;

	bool toChange = true;
	while (*str)
	{
		if (toChange && isLetterSmall(*str))
		{
			smallToCapital(*str);
			toChange = false;
		}
		else if (*str == ' ')
			toChange = true;

		str++;
	}
}

//Task 8
void strCopy(char* dest, const char* source)
{
	if (!dest || !source)
		return;

	while (*source)
	{
		*dest = *source;
		dest++;
		source++;
	}

	*dest = '\0';
}

void removeChar(char* arr, char ch)
{
	if (!arr)
		return;

	char buff[MAX_SIZE];
	size_t len = strlen(arr);
	char buffCnt = 0;
	
	for (size_t i = 0; i < len; ++i)
	{
		if (arr[i] != ch)
		{
			buff[buffCnt] = arr[i];
			++buffCnt;
		}
	}
	
	buff[buffCnt] = '\0';
	strCopy(arr, buff);
}

//Task 9
void fromCapital(char* str)
{
	if (!str)
		return;

	while (*str)
	{
		if (isLetterCapital(*str))
			capitalToSmall(*str);
	}
}

void validation(char* arr)
{
	fromCapital(arr);
	size_t len = strLen(arr);
	for (size_t i = 0; i < len; ++i)
	{
		if(!isLetterSmall(arr[i]))
		{
			removeChar(arr, arr[i]);
			--i;
			len = strLen(arr);
		}
	}
}

void sort(char* str)
{
	if (!str)
		return;

	validation(str);
	int counter[LETTERS];

	fillIntegerWithZeros(counter, LETTERS);
	size_t len = strLen(str);
	for (size_t i = 0; i < len; ++i)
		counter[str[i] - 'a'] += 1;

	char buff[MAX_SIZE];
	*buff = '\0';

	unsigned indexToPut = 0;
	for (unsigned i = 0; i < LETTERS; ++i)
	{
		char letterToPut = i + 'a';
		for (unsigned j = 0; j < counter[i]; ++j)
		{
			buff[indexToPut] = letterToPut;
			++indexToPut;
		}
	}
	strcpy(str, buff);
}

int main()
{
	
}
