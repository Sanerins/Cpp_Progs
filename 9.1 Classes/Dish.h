//
// Created by Comrade Sanerin on 11/27/2020.
//
#include "MyString.h"
#ifndef INC_9_1_CLASSES_DISH_H
#define INC_9_1_CLASSES_DISH_H

class Dish{
private:
    MyString _name;
    int _calories;
    MyString _cuisine;
    int _cookingTime;
public:

    Dish(){
        _name = "Не указано";
        _calories = 0;
        _cuisine = "Не указано";
        _cookingTime = 0;
    };

    Dish(MyString name, int calories = 0, MyString cuisine = "Не указано", int cookingTime = 0):
    _name(name), _calories(calories), _cuisine(cuisine), _cookingTime(cookingTime) {}

    Dish(Dish& c):
    _name(c._name), _calories(c._calories), _cuisine(c._cuisine), _cookingTime(c._cookingTime) {}

    Dish& operator=(Dish &c){
        if(this == &c) return *this;
        this->_name = c._name;
        this->_calories = c._calories;
        this->_cuisine = c._cuisine;
        this->_cookingTime = c._cookingTime;
        return *this;
    }

    Dish& operator+=(Dish &c){
        this->_name+=c._name;
        this->_calories+=c._calories;
        this->_cuisine+=c._cuisine;
        this->_cookingTime+=c._cookingTime;
        return  *this;
    }

    ~Dish(){};

    MyString &getName() {
        return _name;
    }

    void setName(MyString &name) {
        _name = name;
    }

    int getCalories() const {
        return _calories;
    }

    void setCalories(int calories) {
        _calories = calories;
    }

    const MyString &getCuisine() const {
        return _cuisine;
    }

    void setCuisine(MyString &cuisine) {
        _cuisine = cuisine;
    }

    int getCookingTime() const {
        return _cookingTime;
    }

    void setCookingTime(int cookingTime) {
        _cookingTime = cookingTime;
    }

    bool operator>(Dish &a);

    bool operator<(Dish &a);

    bool operator!=(Dish &a);

    bool operator==(Dish &a);

    bool operator^(Dish &a);

    bool operator&&(Dish &a);

    bool operator||(Dish &a);

    Dish& operator++();

    Dish operator++(int);

    Dish& operator--();

    Dish operator--(int);

    friend std::ostream& operator<<(std::ostream &out, Dish &cur);

    friend std::istream& operator>>(std::istream &in, Dish &cur);

    friend Dish operator+(Dish &a, Dish &b);
};

#endif //INC_9_1_CLASSES_DISH_H
