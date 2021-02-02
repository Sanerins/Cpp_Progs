
#include <iostream>

bool isContain(int a, int b) {
    while (b > 0) {
        if (b % 10 == a) {
            return(true);
        }
        b = b / 10;
    }
    return(false);
}

int main()
{
    setlocale(LC_ALL, "");
    std::cout << "Пожалуйста, введите сначала цифру a, потом число b ";
    int digit, number;
    std::cin >> digit >> number;
    while (std::cin.fail() or digit < 0 or digit>9) {
        std::cout << "Ваши ввод некорректен! Пожалуйста, повторите попытку! ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        std::cout << "Пожалуйста, введите сначала цифру a, а потом число b";
        std::cin >> digit >> number;
    }
    bool contain = isContain(digit, number);
    if (contain) {
        std::cout << "Содержит";
    }
    else {
        std::cout << "Не содержит";
    }
}
