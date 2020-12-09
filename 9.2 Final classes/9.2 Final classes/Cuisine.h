//
// Created by Comrade Sanerin on 11/27/2020.
//
#include "Dish.h"
#include "Array.h"
#ifndef INC_9_1_CLASSES_CUISINE_H

class Cuisine{
private:

    MyString _name;
    char _row;
    Array<Dish> _Dishes;

public:

    Cuisine(){
        _name = "NULL";
        _row = 'A';
    }

    Cuisine(MyString &name):_name(_name){
        _row = 'A';
    };

    ~Cuisine(){
    }

    MyString &getName() {
        return _name;
    }

    void setName(MyString &name) {
        _name = name;
    }

    char getRow() const {
        return _row;
    }

    void setRow(char &row) {
        _row = row;
    }

    Array<Dish> &getDishes() {
        return _Dishes;
    }

    void addDish(Dish &dish) {
        _Dishes.Upend(dish);
    }

    int GetLength(){
        return _Dishes.Length();
    }

    Cuisine& operator=(MyString &c){
        this->_name = c;
        return *this;
    }

    Cuisine& operator=(Cuisine &c){
        this->_name = c._name;
        this->_row = c._row;
        this->_Dishes = c._Dishes;
        return *this;
    }

    bool operator>(Cuisine &a);

    bool operator<(Cuisine &a);

    bool operator!=(Cuisine &a);

    bool operator==(Cuisine &a);

    bool operator==(MyString &a);

    bool operator^(Cuisine &a);

    bool operator&&(Cuisine &a);

    bool operator||(Cuisine &a);

    friend std::ostream& operator<<(std::ostream &out, const Cuisine &cuisine);

};

#define INC_9_1_CLASSES_CUISINE_H

#endif //INC_9_1_CLASSES_CUISINE_H
