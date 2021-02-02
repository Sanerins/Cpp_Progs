
#include <iostream>

int Counter(int x) {
    int count = 0;
    while (x != 0) {
        if (x % 2 == 1) count += 1;
        x = x / 2;
    }
    return(count);
}

int main()
{
    setlocale(LC_ALL, "");
    int x = 1;
    bool input;
    while (x != 0) {
        while (true) {
            std::cout << "Введите число \n";
            std::cin >> x;
            if (std::cin.fail()) {
                std::cout << "Ваши ввод некорректен! Пожалуйста, повторите попытку! ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
            }
            else break;
        }
        if (x!=0) std::cout << "В двоичной записи единиц - " << Counter(x) << '\n';
    }
}
