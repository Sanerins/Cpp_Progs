#include <iostream>

int main()
{
    setlocale(LC_ALL, "");
    std::cout << "Для завершения ввода чисел введите 0 \n";
    double raw_input;
    int input, sum = 0, num = 0, plus_num = 0, plus_sum = 0, max, maxI = 0, min, minI = 0;
    min = INT_MAX;
    max = -INT_MAX;
    while (true) {
        std::cout << "Пожалуйста, введите число: \n";
        while (true) {
            std::cin >> raw_input;
            input = raw_input;
            if (std::cin.fail()) {
                std::cout << "Ваше число некорректно! Пожалуйста, повторите попытку ввода! \n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
                std::cout << "Пожалуйста, введите число: \n";
            }
            else if (input != raw_input) {
                std::cout << "Ваше число некорректно! Пожалуйста, повторите попытку ввода! \n";
                std::cout << "Пожалуйста, введите число: \n";
            }
            else break;
        }
        if (input == 0) break;
        num += 1;
        sum += input;
        if (input > max) {
            max = input;
            maxI = num;
        }
        if (input > 0) {
            if (input < min) {
                min = input;
                minI = num;
            }
            plus_num += 1;
            plus_sum += input;
        }
    }
    if (num != 0) {
        double middle;
        double x = sum;
        middle = x / num;
        std::cout << "Сумма: " << sum << "\n";
        std::cout << "Среднее арифметическое: " << middle << "\n";
        if (plus_num > 0) {
            x = plus_sum;
            middle = x / plus_num;
            std::cout << "Среднее арифметическое положительных: " << middle << "\n";
        }
        else std::cout << "Среднее арифметическое положительных чисел отсутствует, их не было \n";
        std::cout << "Максимальное значение: " << max << " Его номер: " << maxI << "\n";
        if (plus_num > 0) {
            std::cout << "Минимальное положительное: " << min << " Его номер: " << minI << "\n";
        }
        else std::cout << "Минимум среди положительных чисел отсутствует, пол. чисел не было \n ";
    }
    else {
        std::cout << "Не было введено ни одного числа \n ";
    }
};