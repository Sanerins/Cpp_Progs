//
// Created by Comrade Sanerin on 11/26/2020.
//

#include <windows.h>
#include <iomanip>
#include <fstream>
#include "Array.h"
#include "MyString.h"
#include "Dish.h"
#include "Cuisine.h"
#include "Exceptions.h"
#undef max
MyString rows = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
using namespace std;

void ShowTable(Array<Cuisine> &cuisines);

void AddToCuisine(Array<Cuisine> &cuisines, Dish &dish);

void ShowCuisines(Array<Cuisine> &cuisines);

void ShowDish(Array<Cuisine> &cuisines);

void LoadSave(Array<Cuisine> &);

void WriteTable(Array<Cuisine> &cuisines);

void SaveMenu(Array<Cuisine> &cuisines);

void ShowMax(Array<Cuisine> &cuisines);

void ShowMin(Array<Cuisine> &cuisines);

int main() {
    {
        setlocale(LC_ALL, "");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
    }
    cout << "����� ���������� � ������������������� ���� ����!" << endl;
    Array<Cuisine> cuisines;
    LoadSave(cuisines);
    int i = 1;
    double input;
    Dish dish;
    while(i != 0) {
        try {
            cout << "����������, �������, ��� �� �� ������ �������:" << endl;
            cout << "[1] �������� ����� ������� � ����" << endl;
            cout << "[2] ������� �������� ���������� ����� �� ����" << endl;
            cout << "[3] ������� �������� ����������� ����� �� ����" << endl;
            cout << "[4] ���������� ��� ����� � �� ��������" << endl;
            cout << "[5] ������� ������� ��������� � �����" << endl;
            cout << "[6] ������� ������� ��������� � ��������� ����" << endl;
            cout << "[7] ������� ���� ���������� � ������� ����" << endl;
            cout << "[0] ��� ������ �� ���������" << endl;
            cout << "" << endl;
            cin >> input;
            i = input;
            if(cin.fail()
            or i != input
            or i < 0
            or i > 7) throw BadChoise();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (i) {
                case (0):
                    break;
                case (1):
                    cin >> dish;
                    if(cin.fail()) throw BadDish();
                    if(dish.getCalories() <= 0 or dish.getCookingTime() <= 0) throw NegativeNumInDish();
                    AddToCuisine(cuisines, dish);
                    break;
                case (2):
                    ShowMax(cuisines);
                    break;
                case (3):
                    ShowMin(cuisines);
                    break;
                case (4):
                    ShowCuisines(cuisines);
                    break;
                case (5):
                    ShowTable(cuisines);
                    break;
                case (6):
                    WriteTable(cuisines);
                    break;
                case (7):
                    SaveMenu(cuisines);
                    break;
            }
        }
        catch(BadChoise &problem){
            i = 1;
            input = 0;
            cout << problem.Text();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        }
        catch(BadDish &problem){
            i = 1;
            input = 0;
            cout << problem.Text();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        }
        catch(NegativeNumInDish &problem){
            i = 1;
            input = 0;
            cout << problem.Text();
            if(cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        catch(BadFile &problem){
            i = 1;
            input = 0;
            cout << problem.Text();
        }
    }
    cout << "������� ��� �� ������������� ���� ���������!" << endl;
    return 0;
}

void ShowMax(Array<Cuisine> &cuisines) {
    if(cuisines.Length() < 1){
        cout << "� ����� ���� ��� �� ������ �����!" << endl;
    }
    else{
        int maxCalories = INT_MIN;
        int maxNum = 0;
        for(int i = 0; i < cuisines.Length(); i++){
            if((cuisines[i]).getDishes().FindMax().getCalories() > maxCalories){
                maxCalories = (cuisines[i]).getDishes().FindMax().getCalories();
                maxNum = i;
            }
        }
        cout << "���������� ������������ � �����: " << (cuisines[maxNum]).getDishes().FindMax() << endl;
    }
}

void ShowMin(Array<Cuisine> &cuisines) {
    if(cuisines.Length() < 1){
        cout << "� ����� ���� ��� �� ������ �����!" << endl;
    }
    else{
        int minCalories = INT_MAX;
        int minNum = 0;
        for(int i = 0; i < cuisines.Length(); i++){
            if((cuisines[i]).getDishes().FindMin().getCalories() < minCalories){
                minCalories = (cuisines[i]).getDishes().FindMin().getCalories();
                minNum = i;
            }
        }
        cout << "���������� ������������ � �����: " << (cuisines[minNum]).getDishes().FindMin() << endl;
    }
}

void SaveMenu(Array<Cuisine> &cuisines) {
    cout << "������� ��������� ����������..." << endl;
    ofstream save;
    save.open("saves.txt", ios::trunc);
    int cuisineCounter = cuisines.Length();
    for (int i = 0; i < cuisineCounter; i++) {
        int dishCounter = (cuisines[i]).GetLength();
        for (int j = 0; j < dishCounter; j++) {
            save << ((cuisines[i]).getDishes())[j];
            if(i != (cuisineCounter - 1) or (j != dishCounter - 1)) save << "\n";
        }
    }
    cout << "��������� ���������� ������� ���������!" << endl;
}

void LoadSave(Array<Cuisine> &cuisines) {
    cout << "������� ����� ���� saves.txt � ����..." << endl;
    ifstream save;
    save.open("saves.txt");
        if (save.is_open()) {
            int i = 2;
            double input;
            Dish dish;
            while(i !=0 and i != 1) {
                try {
                    cout << "���� ������� ������!" << endl;
                    cout << "������ �� �� ������� �� ���� ������?" << endl;
                    cout << "[1] ��" << endl;
                    cout << "[0] ���" << endl;
                    cin >> input;
                    i = input;
                    if(cin.fail()
                       or i != input
                       or i < 0
                       or i > 1) throw BadChoise();
                    switch (i) {
                        case (0):
                            break;
                        case (1):
                            while (!save.eof()) {
                                save >> dish;
                                save.get();
                                cout << dish;
                                AddToCuisine(cuisines, dish);
                            }
                            break;
                    }
                    save.close();
                }
                catch (BadChoise &problem) {
                    input = 0;
                    i = 2;
                    cout << problem.Text();
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
                }
            }
        }

        else {
            cout << "���� �� ��� ������" << endl;
        }
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
                if(cin.fail()) throw BadDish();
                std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
                if(dish < (cuisines[i].getDishes()).Length()) cout << (cuisines[i].getDishes())[dish];
                break;
            }
        }
    }
}

void WriteTable(Array<Cuisine> &cuisines) {
    ofstream table;
    MyString filename;
    cout << "������� �������� ����� ������� (.txt � ����� ������ �� ����)" << endl;
    cin >> filename;
    if(cin.fail()
    or filename == "saves") throw BadFile();
    filename.ChangeSpaces();
    table.open((filename+".txt").GetCharList());
    cout << "���� ������, ������� ������� ����������..." << endl;
    int space = 26;
    int len = 4 + (space+1)*(cuisines.Length()) - cuisines.Length();
    for (int i = 0; i <len; i++) table << "_";
    table << endl;
    table << " � " << "|";
    for(int i = 0; i < cuisines.Length(); i++){
        table << setw(space/2 - 1) << "";
        table << rows[i];
        cuisines[i].setRow(rows[i]);
        table << setw(space/2 - 1) << "";
        table << "|";
    }
    table << endl;
    for (int i = 0; i <len; i++) table << "-";
    table << endl;
    table << "   " << "|";
    for(int i = 0; i < cuisines.Length(); i++){
        int gap = (space-((cuisines[i]).getName().Length()))/2;
        table << setw(gap) << "";
        table << cuisines[i];
        table << setw(space - gap - ((cuisines[i]).getName().Length())) << "";
        table << "|";
    }
    table << endl;
    for (int i = 0; i <len; i++) table << "-";
    table << endl;
    if (cuisines.Length()==0) { }
    else {
        for (int i = 0; i < (cuisines[cuisines.Length() - 1]).GetLength(); i++) {
            table << " ";
            table << i << " |";
            for (int j = 0; j < cuisines.Length(); j++) {
                Array<Dish> &currDishes = (cuisines[j]).getDishes();
                Dish &currDish = currDishes[i];
                if (currDishes.Length() > i) {
                    int gap = (space-(currDish.getName().Length()))/2;
                    table << setw(gap) << "";
                    table << currDish.getName();
                    table << setw(space - gap - (currDish.getName().Length())) << "";
                    table << "|";
                } else table << setw(space) << "|";
            }
            table << endl;
            for (int m = 0; m < len; m++) table << "-";
            table << endl;
        }
    }
    table.close();
    cout << "������� ������� ��������!" << endl;
}
