
#include <iostream>

int main()
{
    setlocale(LC_ALL, "");
    float a = 0;
    while (a != (a + 1)) a = a + 1;
    std::cout << a << "\n";
    std::cout << (a + 1);
}