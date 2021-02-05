#include <iostream>

int main()
{
    setlocale(LC_ALL, "");
    std::cout << "Пожалуйста, введите коэфециенты a,b,c уравнения вида ax^2+bx+c=0 ";
    double a, b, c;
    std::cin >> a >> b >> c;
    while (std::cin.fail() or a == 0) {
        std::cout << "Ваши числа некорректны! Пожалуйста, повторите попытку! ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        std::cout << "Пожалуйста, введите коэфециенты a,b,c уравнения вида ax^2+bx+c=0 \n";
        std::cin >> a >> b >> c;
    }
    double D = b * b - 4 * a * c;
    if (D < 0) {
        D = sqrt(-D) / (2 * a);
        int x = -b / (2 * a);
        if (D < 0) D = -D;
        std::cout << "У вашего уравнения два корня: \"" << x << " + " << D << " * i\" и \"" << x << " - " << D << " * i\"";
    }
    else if (D == 0) {
        int x = -b / (2 * a);
        std::cout << "У вашего уравнения один двойной корень: " << x;
    }
    else {
        D = sqrt(D);
        int x1 = (-b + D) / (2 * a);
        int x2 = (-b - D) / (2 * a);
        std::cout << "У вашего уравнения два корня: " << x1 << " и " << x2;
    }
    return 0;
}