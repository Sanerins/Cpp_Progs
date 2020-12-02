//
// Created by Comrade Sanerin on 11/26/2020.
//

#include <windows.h>
#include <iomanip>
#include "Array.h"
#include "MyString.h"
#include "Dish.h"
#include "Cuisine.h"
MyString rows = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
using namespace std;

void ShowTable(Array<Cuisine> &cuisines);

void AddToCuisine(Array<Cuisine> &cuisines, Dish &dish);

void ShowCuisines(Array<Cuisine> &cuisines);

void ShowDish(Array<Cuisine> &cuisines);

int main() {
    {
        setlocale(LC_ALL, "");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
    }
    cout << "����� ���������� � ������������������� ���� ����!" << endl;
    int i = 1;
    Dish dish;
    Array<Cuisine> cuisines;
    while(i != 0){
        cout << "����������, �������, ��� �� �� ������ �������:" << endl;
        cout << "[1] �������� ����� ������� � ����" << endl;
        cout << "[2] ���������� ��� ����� � �� ��������" << endl;
        cout << "[3] ������� ������� ��������� � �����" << endl;
        cout << "[0] ��� ������ �� ���������" << endl;
        cout << "" << endl;
        cin >> i;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (i){
            case(0): break;
            case(1):
                cin >> dish;
                AddToCuisine(cuisines, dish);
                break;
            case(2):
                ShowCuisines(cuisines);
                break;
            case(3):
                ShowTable(cuisines);
                break;
        }
    }
    cout << "������� ��� �� ������������� ���� ���������!" << endl;
    return 0;
}

void AddToCuisine(Array<Cuisine> &cuisines, Dish &dish){
    Cuisine &cur = cuisines.FindTextInArray(dish.getCuisine());
    cur.addDish(dish);
    if(cur.GetLength() == 1){
        cout << "������� ����� �����: " << cur << ". ����� ������� ��������� � ���" << endl;
    }
    else {
        cur.getDishes().Sort();
        cout << "����� ������� ��������� � ����� \"" << cur << "\""<< endl;
        cuisines.Sort();
    }
}

void ShowCuisines(Array<Cuisine>& cuisines){
    int cuisineCounter = cuisines.Length();
    for(int i = 0; i < cuisineCounter; i++){
        int dishCounter = (cuisines[i]).GetLength();
        cout << "�����: " << cuisines[i] << endl;
        for(int j = 0; j < dishCounter; j++){
            cout << ((cuisines[i]).getDishes())[j];
        }
        cout << "\n\n";
    }
}

void ShowTable(Array<Cuisine> &cuisines){
    int space = 26;
    int len = 4 + (space+1)*(cuisines.Length()) - cuisines.Length();
    for (int i = 0; i <len; i++) cout << "_";
    cout << endl;
    cout << " � " << "|";
    for(int i = 0; i < cuisines.Length(); i++){
        cout << setw(space/2 - 1) << "";
        cout << rows[i];
        cuisines[i].setRow(rows[i]);
        cout << setw(space/2 - 1) << "";
        cout << "|";
    }
    cout << endl;
    for (int i = 0; i <len; i++) cout << "-";
    cout << endl;
    cout << "   " << "|";
    for(int i = 0; i < cuisines.Length(); i++){
        int gap = (space-((cuisines[i]).getName().Length()))/2;
        cout << setw(gap) << "";
        cout << cuisines[i];
        cout << setw(space - gap - ((cuisines[i]).getName().Length())) << "";
        cout << "|";
    }
    cout << endl;
    for (int i = 0; i <len; i++) cout << "-";
    cout << endl;
    if (cuisines.Length()==0) { }
    else {
        for (int i = 0; i < (cuisines[cuisines.Length() - 1]).GetLength(); i++) {
            cout << " ";
            cout << i << " |";
            for (int j = 0; j < cuisines.Length(); j++) {
                Array<Dish> &currDishes = (cuisines[j]).getDishes();
                Dish &currDish = currDishes[i];
                if (currDishes.Length() > i) {
                    int gap = (space-(currDish.getName().Length()))/2;
                    cout << setw(gap) << "";
                    cout << currDish.getName();
                    cout << setw(space - gap - (currDish.getName().Length())) << "";
                    cout << "|";
                } else cout << setw(space) << "|";
            }
            cout << endl;
            for (int m = 0; m < len; m++) cout << "-";
            cout << endl;
        }
    }
    if (cuisines.Length()!=0) ShowDish(cuisines);
}

void ShowDish(Array<Cuisine> &cuisines) {
    cout << "������� ����� ������������� ��� ����� � ������� [����� �������] [����� ������]" << endl;
    cout << "�������� ��� ��������� ��������� ���������� � " << (cuisines[0].getDishes())[0].getName() << endl;
    cout << "������� A0" << endl;
    cout << "��� ������ ������ ������� 0" << endl;
    cout << "\n";
    char row = 'A';
    int dish;
    while(row != '0'){
        cin >> row;
        for(int i = 0; i < cuisines.Length(); i++){
            if (cuisines[i].getRow() == row){
                cin >> dish;
                if(dish < (cuisines[i].getDishes()).Length()) cout << (cuisines[i].getDishes())[dish];
                break;
            }
        }
    }
}
