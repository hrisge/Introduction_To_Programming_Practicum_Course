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

    return '\0';
}

// Here I will make the function of type BOOL
// This will allow us to send a status code - if the function failed or not
// true - the function was successful
// false - the function failed
bool addTwoNumbersInKSystem(
    // CONST ARRAYS!!! WE DO NOT CHANGE THEM!!!
    const char firstNumber[], 
    const char secondNumber[], 
    size_t size,
    unsigned int kSystem,
    char result[]
)
{
    const unsigned int MIN_NUMBER_SYSTEM = 0;
    const unsigned int MAX_NUMBER_SYSTEM = 16;

    if (kSystem == MIN_NUMBER_SYSTEM || kSystem > MAX_NUMBER_SYSTEM)
    {
        cout << "Unsupported number system size";
        return false; // Status code for error
    }
    
    unsigned int carry = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        int firstDigitValue = getValueFromDigitSymbol(firstNumber[i]);
        if (firstDigitValue == -1 || firstDigitValue >= kSystem)
        {
            cout << "Invalid digit symbol reached in first number!";
            return false; // Status code for error
        }

        int secondDigitValue = getValueFromDigitSymbol(secondNumber[i]);
        if (secondDigitValue == -1 || secondDigitValue >= kSystem)
        {
            cout << "Invalid digit symbol reached in second number!";
            return false; // Status code for error
        }

        unsigned int currentSum = firstDigitValue + secondDigitValue + carry;

        result[i + 1] = getDigitSymbolFromValue(currentSum % kSystem);
        carry = currentSum / kSystem;
    }

    result[0] = getDigitSymbolFromValue(carry);
    return true; // Status code for success
}

int main()
{
    char firstNumber[] = { '3', '0', '1' };
    char secondNumber[] = { '2', 'F', 'F' };
    char result[SIZE + 1];

    // Here we use the status code for further validation
    // We do not print the result if the function failed
    bool isSuccessful = addTwoNumbersInKSystem(firstNumber, secondNumber, SIZE, 16, result);

    if (isSuccessful)
    {
        for (size_t i = 0; i < SIZE + 1; i++)
        {
            cout << result[i];
        }
    }
}