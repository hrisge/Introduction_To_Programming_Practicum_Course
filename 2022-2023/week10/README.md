# Задачи 16.12.2022

## Задача първа
```cpp
#include<iostream>

void initPointer(char* toInitialize) {
    toInitialize = new char[26 + 1];

    for (size_t i = 97; i < 123; i++)
        toInitialize[i - 97] = (char)(i);

    toInitialize[26] = '\0';    
}

int main() {
    char* result = nullptr;
    initPointer(result);
    std::cout << result;
    delete[] result;
}
```
Какво ще изведе кодът? Има ли някакви грешки в него и ако да какви.

## Задача втора
На стандартния вход се подават две естествени числа n и m. След това се чете матрица с n корлони и m реда. Да се изведе индекса на реда с най - голяма сума. 

## Задача трета
Доцент Хистограмов въвежда от стандартния вход две естествени числа n и k. След това въвежда 2 масива от n цели числа между 0 и k. Нека n < 10000 и k < 1000. Да се провери дали първия масив е пермутация на втория. Входът не е гарантирано валиден.

## Задача четвърта
Доцент Хистограмов сега въвежда низ представляващ естествено число. Да се напише функция, която връща низ в следния формат:
```
Вход:

"23423"

Изход:

"2х2,2х3,1х4"
```
За изходния стринг да е заделена точно толкова памет колкото са символите.

## Задача пета
От стандартния вход се въвежда естествено число n. След това на нови редове се въвеждат два низа с дължина n. Да се напише функция, която връща низ, представляващ най - дългия общ префикс на двата входни масива.

```
Вход:
5
aaabb
aabab

Изход:
Низ с дължина 3 и стойност {'a', 'a', '\0'}.
```

## Задача шеста
На стандартния вход се въвежда естествено число n и масив с n елемента. Да се напише функция, която отстранява всички елементи от масива, за които е вярно, че са по - малки едновременно от двата си съседа. След края на програмата в масива не трябва да има такива елементи.

Бонус: Изходният масив да заема точно толкова памет, колкото му е нужна да запише числата останали след прилагането на функцията.
