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
    }

    Cuisine(MyString name):_name(_name){};

    ~Cuisine(){
    }

    const MyString &getName() const {
        return _name;
    }

    void setName(const MyString &name) {
        _name = name;
    }

    char getRow() const {
        return _row;
    }

    void setRow(char row) {
        _row = row;
    }

    const Array<Dish> &getDishes() const {
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

    bool operator>(Cuisine &a);

    bool operator<(Cuisine &a);

    bool operator!=(Cuisine &a);

    bool operator==(Cuisine &a);

    bool operator==(MyString &a);

    bool operator^(Cuisine &a);

    bool operator&&(Cuisine &a);

    bool operator||(Cuisine &a);

};

#define INC_9_1_CLASSES_CUISINE_H

#endif //INC_9_1_CLASSES_CUISINE_H
