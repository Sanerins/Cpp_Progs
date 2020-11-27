#include <iostream>

int main()
{
    std::wstring str = L"Пидор с++";
    char c, d = L'\n';

    std::cin.sync_with_stdio(false);
    std::cin.peek();
    std::streamsize size = std::cin.rdbuf()->in_avail();
    std::cout << size << '\n';
    for (int i = 0; i < size; i++) {
        std::cin.get(c);
        std::cout << c;
    }
}
