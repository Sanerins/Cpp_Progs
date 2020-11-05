
#include <iostream>
#include <cmath>

double Degree(double x, int a) {
    double degree = 1;
    for (int i = 1; i <= a; i++) {
        degree *= x;
    }
    return(degree);
}

int Period(int x) {
    int per = 1;
    while (x != 0) {
        per *= x;
        x -= 1;
    }
    return(per);
}

double Taylor(double x, double absError, int numberMax) {
    int degree = 3;
    double sum = x;
    int num = 1,negative = -1;
    while (abs(Degree(x, degree) / Period(degree)) >= absError) {
        num += 1;
        if (num > numberMax) {
            throw "\nПревышен введенный вами лимит\n\n";
        }
        sum += negative * (Degree(x, degree) / Period(degree));
        negative = -negative;
        degree += 2;
    }

    return(sum);
}

int main()
{
    setlocale(LC_ALL, "");
    double xMin, xMax, pace, absError;
    int numberMax;
    while (true) {
        std::cout << "Программа для нахождения значения Sin(x) \n";
        std::cout << "Введите минимальный и максимальный элемент, который надо вывести, а так же шаг интервала.\nЗатем введите absError, numberMax \n";
        std::cin >> xMin >> xMax >> pace >> absError >> numberMax;
        if (
            std::cin.fail()
            or xMax <= -1 or xMax >= 1
            or xMin <= -1 or xMin >= 1
            or xMin > xMax
            or pace <= 0
            or absError <= 0
            or numberMax <= 0
            ) {
            std::cout << "Ваши ввод некорректен! Пожалуйста, повторите попытку! \n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        }
        else break;
    }
    while (xMin <= xMax) {
        try {
            double sum = Taylor(xMin, absError, numberMax);
            std::cout << "Число: " << xMin << "\nЗначение, вычисленное стандартной функцией: " << sin(xMin) << "\nЗначение, вычисленное моей функцией: " << sum << "\n\n\n";
        }
        catch (const char* msg) {
            std::cout << msg;
        }
        xMin += pace;
        xMin = round(xMin * 10000) / 10000;
    }
}
