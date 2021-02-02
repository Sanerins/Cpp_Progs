#include <iostream>

int main()
{
    setlocale(LC_ALL, "");
    std::cout << "Программа для определения наибольшего монотонно возрастающего пр-ка посл-ти. Для завершения ввода - 0 \n";
    int input, a_before;
    double raw_input;
    a_before = INT_MAX;
    int unum = 0, max_num = 0, num = 0;
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
        if (input > a_before) {
            unum += 1;
        }
        else {
            if (max_num < unum) {
                max_num = unum;
            }
            unum = 0;
        }
        a_before = input;
    }
    if (unum > max_num) {
        max_num = unum;
    }
    if (num > 1) {
        if (max_num > 0) {
            std::cout << "Длина максимальной возрастающей последовательности: " << (max_num + 1);
        }
        else std::cout << "Возрастающей последовательности обнаружено не было";
    }
    else {
        std::cout << "Не было введено достаточного числа чисел \n ";
    }
}