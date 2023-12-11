#include <iostream>
using namespace std;

constexpr size_t SIZE = 3;

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

    // An example for invalid integer to return when the input is invalid
    return -1;
}

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

    // An example for invalid character to return when the input is invalid
    return '\0';
}

void addTwoNumbersInKSystem(char numberSymbols[], size_t size, unsigned int kSystem)
{
    // Constants that hold our settings for the validation
    const unsigned int MIN_NUMBER_SYSTEM = 0;
    const unsigned int MAX_NUMBER_SYSTEM = 16;

    // Validating the number system. We work with systems between 1 and 16
    if (kSystem == MIN_NUMBER_SYSTEM || kSystem > MAX_NUMBER_SYSTEM)
    {
        cout << "Unsupported number system size";
        return;
    }

    for (int i = size - 1; i >= 0; i--)
    {
        int digitValue = getValueFromDigitSymbol(numberSymbols[i]);

        // Validation for our input. If we reach an invalid symbol, we return and display a message
        if (digitValue == -1 || digitValue >= kSystem)
        {
            // For now we will be printing the error message
            // Later we will show you how to handle errors in a better way
            cout << "An invalid digit symbol has been reached!";
            return;
        }

        digitValue--;

        if (digitValue != -1)
        {
            numberSymbols[i] = getDigitSymbolFromValue(digitValue);
            break;
        }

        numberSymbols[i] = getDigitSymbolFromValue(kSystem - 1);
    }
}

int main()
{
    char number[] = { '1', 'A', '0' };
    addTwoNumbersInKSystem(number, SIZE, 16);

    for (size_t i = 0; i < SIZE; i++)
    {
        cout << number[i];
    }
}