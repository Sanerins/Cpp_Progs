#include <iostream>
#include <windows.h>

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char c;
    std::cout << "Привет мир!" << std::endl;
    std::cin >> c;
    std::cout << c;
    return 0;
}
