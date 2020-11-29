//
// Created by Comrade Sanerin on 11/26/2020.
//

#include <windows.h>
#include "Array.h"
#include "MyString.h"
#include "Dish.h"
#include "Cuisine.h"
MyString rows = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
using namespace std;

int main() {
    {
        setlocale(LC_ALL, "");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
    }

    Array<Cuisine> Cuisines;
    Dish dish;
    for(int i = 0; i < 1; i++){
        cin >> dish;
        Cuisines.FindTextInArray(dish.getCuisine()).addDish(dish);
    }

    return 0;
}
