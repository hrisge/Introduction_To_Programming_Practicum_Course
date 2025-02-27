# УП - Практикум 15.11.2024 Седмица 7

**Задача 1:** Да се направи функция, която извежда на екрана двоичната репрезентация на 32 битово число записано в десетична бройна система.

**Пример:**
Вход:
```c++
10
```
Изход:
```c++
00000000000000000000000000001010
```

**Задача 2:** Напишете функция, която приема цяло число и връща броя на 1-ците в двоичния му запис.

**Пример:**
Вход: 
```c++
189
```
Изход: 
```c++
6
```

**Задача 3:** Да се напише функция, която приема число в десетична бройна система и число k <= 16 и k > 0. Функцията извежда на стандартния изход числото в k-ична бройна система

**Пример:**
Вход:
```c++
167 12
```
Изход:
```c++
11B // 167 in base 10 is equal to 11B in base 12
```

**Задача 4:** Да се напише функция, която приема число в трoична бройна система и го връща в осмична **без да използва масив.**

**Пример:**
Вход:
```c++
11120
```
Изход:
```c++
173
```

**Задача 5:** Да се напише функция, която приема число в дванайсетична бройна система и го връща в тринайсетична **с масив.**

**Пример:**
Вход:
```c++
23
```
Изход:
```c++
21
```

**Задача 6:**
Да се напише функция, която приема осем битово число в двоична бройна система, представено като int и връща числото, умножено по -1.

**Пример 1:**
Вход:
```c++
00001010 // 10
```
Изход:
```c++
11110110 // -10
```

**Пример 2:**
Вход:
```c++
11111111 // -1
```
Изход:
```c++
00000001 // 1
```

**Задача 7:** Да се напише функция, която приема число от тип unsigned int (32 бита) и K - бройна система (<= 16-ична). Функцията да връща дали числото е палиндром в дадената бройна система.

**Пример:**
Вход:
```c++
7 2
```
Изход:
```c++
true // 7 = 111 in binary
```

**Задача 8:** Да се напише функция, която приема два масива от символи, големината им и числа К и N. Масивите са съответно две числа - първото в К-ична, второто в N-ична бройна система. Функцията да връща дали числата са равни.

**Пример:**
Вход:
```c++
[3, 4, 5] 3 8
[E, 5] 2 16
```
Изход:
```c++
true //345(8) = 229(10) = E5(16)
```

**Задача 9:** Конвертори на бройни системи:
1. Да се напише функция, която приема число в N-ична бройна система и го връща в K-ична бройна система **без да използва масив.** (N и K са най-много 10).
   
2. Да се напише функция, която приема число в N-ична бройна система и го връща в K-ична бройна система **с масив.** (N и K са най-много 36 - с други думи са бройни системи само с цифри от 0 до 9 и букви от A до Z).
