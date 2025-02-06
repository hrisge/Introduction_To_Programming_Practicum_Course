# УП - Контролно Практикум 11.10.2023 Седмица 1

**Въпрос 1:** Какво ще се отпечата на конзолата?
```c++
#include <iostream>

int main()
{
    int first = 7;
    int second = 2;

    std::cout << 2 * first / (second * (25 / 10)) << std::endl;
    std::cout << 2 * first / (second * 2.5) << std::endl;
}
```

**Въпрос 2:** Какво ще се отпечата на конзолата?
```c++
#include <iostream>

int main()
{
    double first = 3.75;
    double second = 5.36;
    int result = first + second;

    std::cout << result << std::endl;
}
```

**Въпрос 3:** Какъв ще е резултата след изпълнение на логическите операции?
```c++
#include <iostream>

int main()
{
    std::cout << (true && (!true || (!false && !!true || 0))) << std::endl;
}
```

**Въпрос 4:** При изпълнение на този код, ще се хвърли ли грешка?
```c++
#include <iostream>

int main()
{
    int num = 5;
    std::cout << ((num == 5) && (num >= 3) || (num / !num)) << std::endl;
}
```