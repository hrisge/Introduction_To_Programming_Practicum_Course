#include <iostream>
using namespace std;

// A test array size
constexpr size_t SIZE = 3;

// Function for converting a symbol which resembles a digit into the value of the digit
/*
    '0' -> 0
    '1' -> 1
    ...
    '9' -> 9
    'A' -> 10
    'B' -> 11
    ...
    'F' -> 15
*/
int getValueFromDigitSymbol(char symbol)
{
    if (symbol >= '0' && symbol <= '9')
    {
        return symbol - '0';
    }

    if (symbol >= 'A' && symbol <= 'F')
    {
        return symbol - 'A' + 10;
    }

    return -1;
}

// Function for converting a value into a symbol which resembles a digit
/*
    0 -> '0'
    1 -> '1'
    ...
    9 -> '9'
    10 -> 'A'
    11 -> 'B'
    ...
    15 -> 'F'
*/
char getDigitSymbolFromValue(int index)
{
    if (index >= 0 && index <= 9)
    {
        return index + '0';
    }

    if (index >= 10 && index <= 15)
    {
        return index + 'A' - 10;
    }

    return '\0';
}

// Function for adding 1 to the given value in K-number system
void addTwoNumbersInKSystem(char numberSymbols[], size_t size, unsigned int kSystem)
{
    // We start from the last digit (just like we add in decimal)
    for (int i = size - 1; i >= 0; i--)
    {
        // We get the value of the given digit symbol and increase it
        int digitValue = getValueFromDigitSymbol(numberSymbols[i]);
        digitValue++;

        // If the new value is less than the given K-system, we have no carry and we can break
        if (digitValue < kSystem)
        {
            numberSymbols[i] = getDigitSymbolFromValue(digitValue);
            break;
        }

        // Since we have reached the value of the K-system,
        // we set the current digit to 0 and add 1 to the previous digit by repeating the loop
        numberSymbols[i] = getDigitSymbolFromValue(0);
    }
}

int main()
{
    // Sample code for testing
    char number[] = { '1', '9', 'F' };
    addTwoNumbersInKSystem(number, SIZE, 16);


    // Printing the result
    for (size_t i = 0; i < SIZE; i++)
    {
        cout << number[i];
    }
}