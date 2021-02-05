
#include <iostream>

double Degree(double x, int a) {
    double degree = 1;
    for (int i = 1; i <= a; i++) {
        degree *= x;
    }
    return(degree);
}

double Taylor(double x, double absError, double numberMax) {
    double sum = 0, curNumb = 1, numerator = 1, denomintor = 2;
    int num = 0;
    std::cout << "Ошибка " << absError << '\n';
    while ((abs(curNumb* Degree(x, num))) >= absError) {
        if (numberMax == num) return(0);
        sum += curNumb * Degree(x, num);
        std::cout << "Степень " << Degree(x, num) << '\n';
        num += 1;
        std::cout << "Число " << curNumb << '\n';
        std::cout << "Общее " << sum << '\n';
        curNumb = -1 * curNumb * (numerator / denomintor);
        numerator += 2;
        denomintor += 2;
        std::cout << "Число для проверки " << abs(curNumb * Degree(x, num)) << '\n';
    }
    return(sum);
}

int main()
{
    setlocale(LC_ALL, "");
    std::cout << "Введите x, absError, numberMax ";
    double x, absError, numberMax;
    std::cin >> x >> absError >> numberMax;
    while (std::cin.fail() or x<-1 or x>1 or absError<0) {
        std::cout << "Ваши ввод некорректен! Пожалуйста, повторите попытку! ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        std::cout << "Введите x, absError, numberMax ";
        std::cin >> x >> absError >> numberMax;
    }
    double sum = Taylor(x, absError, numberMax);
    if (sum == 0) { 
        std::cout << "Превышен введенный вами лимит "; 
    }
    else std::cout << sum;
}
