#include <iostream>

int main()
{
    setlocale(LC_ALL, "");
    int a = 1;
    while (a != 0) {
        std::cout << "Выберете интересующую вас программу\n";
        std::cout << "1. Максимум из трех\n";
        std::cout << "2. Упорядочить три числа\n";
        std::cout << "3. Кол-во совпадающих из трех\n";
        std::cout << "4. Четные и нечетные числа\n";
        std::cout << "5. Координаты четверти\n";
        std::cout << "0. Выход\n";
        std::cin >> a;
        std::cout << "\n\n\n";
        switch (a) {
        case 1: {
            std::cout << "Максимум из трех\n";
            int x, y, z;
            std::cout << "Введите три числа x y z: ";
            std::cin >> x >> y >> z;
            while (std::cin.fail()) {
                std::cout << "Ваши числа некорректны! Пожалуйста, повторите попытку! ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
                std::cin >> x >> y >> z;
            }
            if ((x >= y) and (x >= z)) std::cout << (x);
            else if ((y >= x) and (y >= z)) std::cout << (y);
            else std::cout << (z);
            std::cout << "\n\n\n";
            break;
        }
        case 2: {
            std::cout << "Упорядочить три числа\n";
            int x, y, z, t;
            std::cout << "Введите три числа x y z: ";
            std::cin >> x >> y >> z;
            while (std::cin.fail()) {
                std::cout << "Ваши числа некорректны! Пожалуйста, повторите попытку! ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
                std::cin >> x >> y >> z;
            }
            if (x > y) {
                t = y;
                y = x;
                x = t;
            }
            if (y > z) {
                t = z;
                z = y;
                y = t;
            }
            if (x > y) {
                t = y;
                y = x;
                x = t;
            }
            std::cout << x << " " << y << " " << z;
            std::cout << "\n\n\n";
            break;
        }
        case 3: {
            std::cout << "Кол-во совпадающих из трех\n";
            int x, y, z, k = 0;
            std::cout << "Введите три числа x y z: ";
            std::cin >> x >> y >> z;
            while (std::cin.fail()) {
                std::cout << "Ваши числа некорректны! Пожалуйста, повторите попытку! ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
                std::cin >> x >> y >> z;
            }
            if (x == y) k += 1;
            if (x == z) k += 1;
            if (y == z) k += 1;
            if (k == 1) k += 1;
            std::cout << (k);
            std::cout << "\n\n\n";
            break;
        }
        case 4: {
            std::cout << "Четные и нечетные числа\n";
            int x, y, z, k = 3;
            std::cout << "Введите три числа x y z: ";
            std::cin >> x >> y >> z;
            while (std::cin.fail()) {
                std::cout << "Ваши числа некорректны! Пожалуйста, повторите попытку! ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
                std::cin >> x >> y >> z;
            }
            if (x % 2 == 0) k -= 1;
            if (y % 2 == 0) k -= 1;
            if (z % 2 == 0) k -= 1;
            if ((k != 0) and (k != 3)) std::cout << "ДА";
            else std::cout << "НЕТ";
            std::cout << "\n\n\n";
            break;
        }
        case 5: {
            std::cout << "Координаты четверти\n";
            int x1, y1, x2, y2;
            std::cout << "Введите координаты точек (x1,y1) и (x2,y2): ";
            std::cin >> x1 >> y1 >> x2 >> y2;
            while (std::cin.fail()) {
                std::cout << "Ваши числа некорректны! Пожалуйста, повторите попытку! ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
                std::cin >> x1 >> y1 >> x2 >> y2;
            }
            if (((x1 > 0) and (x2 > 0)) or ((x1 < 0) and (x2 < 0))) {
                if (((y1 > 0) and (y2 > 0)) or ((y1 < 0) and (y2 < 0))) {
                    std::cout << "ДА";
                }
                else std::cout << "НЕТ";
            }
            else std::cout << "НЕТ";
            std::cout << "\n\n\n";
            break;
        }
        }
    }
}