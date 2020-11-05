#include <iostream>

int main()
{
    setlocale(LC_ALL, "");
    std::cout << "Пожалуйста, введите число, которое вы хотите перевести в римскую систему счисления ";
    int a;
    std::cin >> a;
    while (std::cin.fail() or a > 400) {
        std::cout << "Ваше число некорректно! Пожалуйста, повторите попытку ввода! \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        std::cout << "Пожалуйста, введите число, которое вы хотите перевести в римскую систему счисления \n";
        std::cin >> a;
    }
    if (a == 400) std::cout << ("CD");
    else {
        while (a >= 100) {
            std::cout << ("C");
            a -= 100;
        }
        if (a >= 90) {
            std::cout << ("XC");
            a -= 90;
        }
        while (a >= 50) {
            std::cout << ("L");
            a -= 50;
        }
        if (a >= 40) {
            std::cout << ("XL");
            a -= 40;
        }
        while (a >= 10) {
            std::cout << ("X");
            a -= 10;
        }
        if (a == 9) {
            std::cout << ("IX");
            a -= 9;
        }
        while (a >= 5) {
            std::cout << ("V");
            a -= 5;
        }
        if (a == 4) {
            std::cout << ("IV");
            a -= 4;
        }
        while (a >= 1) {
            std::cout << ("I");
            a -= 1;
        }
    }
}