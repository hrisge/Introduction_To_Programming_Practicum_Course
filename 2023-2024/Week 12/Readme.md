# УП - Практикум 03.01.2024 Седмица 12

**Задача 1:** От стандартния вход се приемат две естествени числа N и M и се чете матрица NxM. Да се напише функция, принтира матрицата, но на мястото на всяко четно число извежда *.

**Пример:**

Вход:
```c++
3 3
1 2 3
4 5 6
7 8 9
```
Изход:
```c++
1 * 3
* 5 *
7 * 9
```

**Задача 2:** От стандартния вход се чете число N и се въвежда матрица NxN от цели числа. Да се изведе сумата на 
* Всички четни елементи над главния диагонал (без него).
* Всички нечетни елементи под главния диагонал (с него).
* Всички елементи на вторичния диагонал повдигнати на квадрат.

**Задача 3:** От стандартния вход се чете естествено число N и две матрици NxN. Напишете функция, събира двете матрици и връща резултата като нова матрица.

**Задача 4:** От стандартния вход се въвеждат две числа N и M. След това от стандартния вход се четат две матрици с размери NxM и MxN. Напишете функция, която връща произведението на двете матрици.

**Задача 5:** Да се напише функция, която приема матрица и индекс **i** и връща нова матрица, за която е заделено точно количество памет, в която липсва **i**-тия ред.

**Пример:**

Вход:
```c++
1 2 3 
4 5 6
7 8 9
2
```
Изход:
```c++
1 2 3 
7 8 9
```

**Задача 6:** Да се напише функция, която приема матрица и индекс **i** и връща нова матрица, за която е заделено точно количество памет, в която липсва **i**-тия стълб.

**Пример:**

Вход:
```c++
1 2 3 
4 5 6
7 8 9
2
```

Изход:
```c++
1 3 
4 6
7 9
```

**Задача 7:** Да се напише функция, която приема матрица и връща транспонираната матрица, за която е заделено точно количество памет.

**Пример:**

Вход:
```c++
1 3 
4 6
7 9
```
Изход:
```c++
1 4 7
3 6 9
```

**Задача 8:** Да се напише функция, която приема стринг **text** и символ **s** и връща матрица, за която е заделено точно количество памет, която съдържа всички думи от **text**, разделени с **s**.

**Пример:**

Вход:
```c++
Hello:my:name:is
:
```
Изход:
```c++
Hello
my
name
is
```

**Задача 9:** Да се напише функция, която приема масив от ребрата на ненасочен граф и връща матрица, за която е заделено точно количество памет, която представлява матрица на съседство на графа.

**Пример:**

Вход:
```c++
0 1
0 2
1 4
1 5
2 3
```

Изход:
```c++
0 1 1 0 0 0 
1 0 0 0 1 1 
1 0 0 1 0 0 
0 0 1 0 0 0 
0 1 0 0 0 0 
0 1 0 0 0 0 
```

**Задача 10:** Да се напише програма, която приема матрица и връща нова матрица, за която е заделено точно количество памет, има 2 пъти по-малко редове и първия ред представлява конкатенация на първия и последния, втория - на втория и предпоследния и т.н. Ако редовете на подадената матрица са нечетен брой, седния ред осава непроменен.

**Пример:**

Вход:
```c++
0 1
0 2
1 4
1 5
2 3
```
Изход:
```c++
0 1 2 3
0 2 1 5
1 4
```

**Задача 11:** Да се напише функция, която приема стринг и връща нова матрица, за която е заделено точно количество памет, в която стрингът е записан зигзагообразно по следния начин:

**Пример:**

Вход:
```c++
PAYPALISHIRING
```
Изход:
```c++
P   A   H   N
A P L S I I G
Y   I   R
```