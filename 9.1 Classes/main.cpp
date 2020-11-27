//
// Created by Comrade Sanerin on 11/26/2020.
//

//#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include "Array.h"
#include "MyString.h"
#include "Dish.h"
#include "Cuisine.h"
using namespace std;

int main() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    //setlocale(LC_CTYPE,"utf8");
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    wchar_t t;
    MyString str1;
    //MyString str2;
    for(int i = 0; i<100; i++) {
        wcout << "Строка: " << "\"" << str1 << "\"" << ". Длина: " << str1.Length() << ". Максимальная длинна: " << str1.MaxLength() << endl;
        wcin >> t;
        str1.Upend(t);
    }
    return 0;
}
