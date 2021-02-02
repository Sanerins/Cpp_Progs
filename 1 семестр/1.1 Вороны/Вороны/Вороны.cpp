
#include <iostream>

int main()
{
    setlocale(LC_ALL, "");
    std::cout << "Сколько ворон сидит на суке? ";
    int input = 0;
    std::cin >> input;
    int x;
    while (input < 0 or std::cin.fail()) {
        std::cout << "Количество ворон введено некорректно ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        std::cin >> input;
    }
    x = input % 10;
    if (x == 0 or x > 4 or (input % 100 > 10 and input % 100 < 20)) {
        std::cout << input << " ворон";
    }
    else if (x == 1) {
        std::cout << input << " ворона";
    }
    else if (x > 1 and x < 5) {
        std::cout << input << " вороны";
    }
}