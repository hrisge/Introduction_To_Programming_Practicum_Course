# Малко контролно по УП, 26.11.2025

## Задача 01

Какво ще изведе следният кодов фрагмент:

```cpp
#include <iostream>

int foo(int const &x) {
  return x+3;
}
int main() {
  int x = 10;
  std::cout << foo(x+1) << std::endl;
  std::cout << foo(x)   << std::endl;
}
```

## Задача 02

Какви са (потенциалните) проблеми в следния кодов фрагмент:

```cpp
 1. short& square(int n) {
 2.  return n^2;
 3. }
 4.
 5. void add1(int& x) {
 6.   return x++;
 7. }
 8.
 9. int main() {
10.   std::cout << square(256) << std::endl;
11.   int const x = 20;
12.   int& y = x;
13.   add1(y);
14.
```

Запишете редовете, в които виждате проблем, и какъв е той.

## Задача 03

Пренапишете следния кодов фрагмент, така че да работи правилно
и да спазва добрите практики в програмирането:

```cpp
unsigned getSize(char arr[]) {
  return sizeof(arr);
}

char toLower(char &c) {
  return c += 'A' - 'a';
}

int main() {
  unsigned n;
  std::cin >> n;

  char str[n];
  for (unsigned i = 0; i < n; ++i)
    std::cin >> str[i];

  for (unsigned i = 0; i <= n; i++) {
    str[i] = toLower(str[i]);
  }

  std::cout << str << std::endl;
}
```

## Задача 04

Да се напише функция, която приема масив от цели числа
и пренарежда елементите му по такъв начин, че всички
ненулеви елементи да се намират преди всички нули.

```cpp
int arr[]{5,7,0,2,0,3,7,2,0,0};
moveZeroes(arr, sizeof(arr)/sizeof(int));
// [5,7,2,3,7,2,0,0,0,0]
```
