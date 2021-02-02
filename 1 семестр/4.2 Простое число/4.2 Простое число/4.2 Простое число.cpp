
#include <iostream>

bool isPrime(int a) {
    for(int i = 2; i<=sqrt(a); i++){
        if (a%i == 0) return false;
    }
    if (a == 1) return(false);
    return(true);
}

int main()
{
    setlocale(LC_ALL, "");
    std::cout << "Пожалуйста, введите сначала число ";
    int number;
    std::cin >>  number;
    while (std::cin.fail()) {
        std::cout << "Ваши ввод некорректен! Пожалуйста, повторите попытку! ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        std::cout << "Пожалуйста, введите сначала цифру a, а потом число b";
        std::cin >> number;
    }
    bool contain = isPrime(number);
    if (contain) {
        std::cout << "Простое";
    }
    else {
        std::cout << "Не простое";
    }
}
