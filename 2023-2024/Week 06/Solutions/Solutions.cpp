#include <iostream>
using namespace std;

constexpr int SIZE = 20;

//Task 1
double average(const int array[], unsigned size)
{
    double sum = 0;
    for (unsigned i = 0; i < size; i++)
        sum += array[i];

    return (sum / size);
}

//Task 2
bool isSorted(const int array[], unsigned size)
{
    if (size <= 1)
        return true;

    int howSorted;   // -1 - Downgrading, 1 - Upgrading, 0 - Undefined

    if (array[0] == array[1])
        howSorted = 0;
    else if (array[0] < array[1])
        howSorted = -1;
    else
        howSorted = 1;

    size = size - 1;
    for (unsigned i = 1; i < size; ++i)
    {
        if (howSorted == -1 && array[i] >= array[i + 1])
            continue;
        else if (howSorted == 1 && array[i] <= array[i + 1])
            continue;
        else if (howSorted == 0 && array[i] == array[i + 1])
            continue;                                                    //The first 3 cases can and should be united in one, but we do it like that so the code can be read easily
        else if (howSorted == 0 && array[i] > array[i + 1])
        {
            howSorted = -1;
            continue;
        }
        else if (howSorted == 0 && array[i] < array[i + 1])
        {
            howSorted = 1;
            continue;
        }
        else
            return false;
    }
    return true;
}

//Task 3
void minAndMax(const int array[], unsigned size, int& min, int& max)
{
    min = INT16_MIN; // The lowest value of Integer
    max = INT16_MAX; // The highest value of Integer

    for (unsigned i = 0; i < size; ++i)
    {
        if (array[i] < min)
            min = array[i];
        else if (array[i] > max)
            max = array[i];
    }
}

//Task 4
void removeElAtIndex(int array[], unsigned size, unsigned index) //Notice that this time the array is not CONST because we will change it
{
    if (index >= size)
        return;
    
    size = size - 1;
    for (unsigned i = index; i < size; i++)
        array[i] = array[i + 1];

    array[size] = INT16_MIN; // We do this so we flag this this cell as invalid
}

//Task 5
bool isPalindrome(const int array[], unsigned size)
{
    if (size < 2)
        return true;

    for (unsigned i = 0, j = 0; i <= j; i++, j--)
    {
        if (array[i] != array[j])
            return false;
    }
    return true;
}

//Task 6
unsigned longestContinuity(const int array[], unsigned size)
{
    unsigned maxLen = 0, currentMaxLen=1;
    if (size == 1)
        return 1;


    for (unsigned i = 1; i < size; ++i)
    {
        if (array[i] == array[i - 1])
            currentMaxLen++;
        else
        {
            if (currentMaxLen > maxLen)
                maxLen = currentMaxLen;

            currentMaxLen = 0;      
        }
    }
    if (currentMaxLen > maxLen)
        maxLen = currentMaxLen;

    return maxLen;
}

//Task 7
void swap(int& first, int& second)
{
    int temp = first;
    first = second;
    second = temp;
}

void reverse(int array[], unsigned size)
{
    unsigned half = size / 2;
    for (unsigned i = 0; i <= half; i++)
        swap(array[i], array[size - i - 1]);
}

//Task 8
void removeNegative(int array[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        if (array[i] < 0)
        {
            for (unsigned j = i + 1; j < size; ++j)
            {
                if ((j == size - 1) && array[j] < 0)
                    return;
                else if (array[j] > 0)
                {
                    swap(array[i], array[j]);
                    break;
                }
            }
        }
    }
}

//Task 9
void increaseByOne(int array[])
{
    if (array[4] == 9)
    {
        array[4] = 0;
        for (int i = 3; i >= 0; ++i)
        {
            if (array[i] == 9)
                array[i] = 0;
            else
            {
                ++array[i];
                break;
            }
        }
    }
    else
        ++array[9];
}

//Task 10
bool isDigitInNummber(int number, int digit)
{
    while (number != 0)
    {
        if (number % 10 == digit)
            return true;

        number = number / 10;
    }
}

bool filterArray(int array[], unsigned size)
{
    for (unsigned i = 0; i < 10 && i < size; i++)
    {
        if (isDigitInNummber(array[i], i))
            array[i] = 0;
    }
}

//Task 11
int mostCommonNumber(const int array[], unsigned size)
{
    int currentMostCommonNumber, currentCount = 0;
    
    for (int i = 0; i < size; i++)
    {
        int currentOcurances = 1;
        for (int j = 0; j < size; j++)
        {
            if (array[j] == array[i])
                currentOcurances++;
        }

        if (currentOcurances > currentCount)
        {
            currentMostCommonNumber = array[i];
            currentCount = currentOcurances;
        }
    }

    return currentMostCommonNumber;
}

//Task 12
void occurances(const int array[], unsigned size=20)
{
    int occurances[SIZE];

    for (int i = 0; i < SIZE; ++i)
        occurances[i] = 0;

    for (int i = 0; i < size; ++i)
        occurances[array[i]]++;

    for (int i = 0; i < size; ++i)
        cout << i << " - " << occurances[i];
}

//Task 12.5
int missingNumberSlow(const int array[])
{
    bool buff[SIZE];
    for (int i = 0; i < SIZE; ++i)
        buff[i] = false;

    for (int i = 0; i < SIZE; ++i)
        buff[array[i]] = true;

    for (int i = 0; i < SIZE; ++i)
    {
        if (!array[i])
            return array[i];
    }
}

int missingNumberSlow(const int array[])
{
    int sum = (SIZE * SIZE / 2);
    int sumArr = 0;
    
    for (int i = 0; i < SIZE; ++i)
        sumArr += array[i];

    return sum - sumArr;
}

//Task 15
bool isArrSubarray(const int array[], unsigned size1, const int subArray[], unsigned size2)
{
    unsigned indexToLook = 0;
    for (unsigned i = 0; i < size1; ++i)
    {
        if (indexToLook == size2)
            return true;

        if (array[i] == subArray[indexToLook])
            indexToLook++;

        else
            indexToLook = 0;
    }

    return indexToLook == size2;
}

int main()
{

}