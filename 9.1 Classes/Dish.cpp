//
// Created by Comrade Sanerin on 28.11.2020.
//
#include "Dish.h"

bool Dish::operator>(Dish &a){
    return this->_calories>a._calories;
}

bool Dish::operator<(Dish &a){
    return this->_calories<a._calories;
}

bool Dish::operator!=(Dish &a){
    return this->_calories!=a._calories;
}

bool Dish::operator==(Dish &a){
    return this->_calories==a._calories;
}

bool Dish::operator^(Dish &a){
    return this->_calories^a._calories;
}

bool Dish::operator&&(Dish &a){
    return this->_calories&&a._calories;
}

bool Dish::operator||(Dish &a){
    return this->_calories||a._calories;
}

Dish& Dish::operator++(){
    _calories++;
    return *this;
}

Dish Dish::operator++(int){
    Dish Temp = *this;
    ++(*this);
    return (Temp);
}

Dish& Dish::operator--(){
    _calories--;
    return *this;
}

Dish Dish::operator--(int){
    Dish Temp = *this;
    --(*this);
    return (Temp);
}

std::ostream& operator<<(std::ostream &out, Dish &cur){
    out << "Блюдо: " << cur._name << " | кухня: " << cur._cuisine << " | калории: " << cur._calories << " | время приготовления: " << cur._cookingTime << " минут" << std::endl;
    return  out;
}

std::istream& operator>>(std::istream &in, Dish &cur){
    std::cout << "Блюдо: ";
    in >> cur._name;
    std::cout << "Кухня: ";
    in >> cur._cuisine;
    std::cout << "Калории: ";
    in >> cur._calories;
    std::cout << "Время приготовления: ";
    in >> cur._cookingTime;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return in;
}

Dish operator+(Dish &a, Dish &b){
    Dish c;
    c._calories=c._calories;
    c._name = a._name + b._name;
    c._cuisine = a._cuisine + b._cuisine;
    return c;
}