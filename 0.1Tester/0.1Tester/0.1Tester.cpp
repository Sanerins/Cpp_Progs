#include <iostream>
#include <iomanip>
#include "cmath"
#include <exception>

double Taylor(double x, double absError, unsigned int numberMax) {

    double sum = 1.0;
    double k;
    double value = 1.0;
    int i;
    for (i = 1; i <= numberMax; i++) {
        k = (static_cast<double>(i * 2 - 1)) / (static_cast<double>(i * 2));
        value *= k * x * x;
        sum += value;
    }
    if (std::abs(value) > absError) {
        std::cout << "Заданная точность не может быть достигнута\n";
        throw (std::exception());

    }
    return (sum);
}

int main() {
    setlocale(LC_ALL, "");
    std::cout << "Ряд Тейлора\n";
    std::cout << "Задание номер 4 \nФункция y=(1/sqrt(1-x*x))\n";
    unsigned int numberMax;
    double absError, deltaX, lowBorder, highBorder;
    std::cout << "Введите нижнюю и верхнюю границы значений х\t -1 < x < 1\n";
    std::cin >> lowBorder >> highBorder;

    if (highBorder >= 1.0 or lowBorder <= -1.0) {
        std::cout << "Введены неверные границы, завершение программы\n";
        exit(1);
    }
    else if (highBorder < lowBorder) {
        std::cout << "Меньшее значение больше большего, завершение программы\n";
        exit(1);
    }

    std::cout << "Введите шаг для x\n";
    std::cin >> deltaX;
    if (deltaX == 0) {
        std::cout << "Введено нулевое значеие шага, завершение прогаммы";
        exit(1);
    }
    std::cout << "Введите макисимальное количество итераций для подсчета (число большее 1)\n";
    std::cin >> numberMax;
    std::cout << "Введите минимальную ошибку\n";
    std::cin >> absError;
    if (std::cin.fail()) {
        std::cout << "Ошибка ввода, введено нечисловое значение\n";
        exit(1);
    }
    std::cout << "Должно быть\tНаша функция\n";
    for (double x = lowBorder; x < highBorder; x += deltaX) {
        std::cout << std::setw(8) << 1 / sqrt(1 - x * x) << "\t";
        std::cout << std::setw(8) << Taylor(x, absError, numberMax) << "\n";
    }

    return 0;
}
