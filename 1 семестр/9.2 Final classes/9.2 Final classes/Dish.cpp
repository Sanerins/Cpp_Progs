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

std::ofstream& operator<<(std::ofstream &out, Dish &cur){
    out << cur._name << std::endl;
    out << cur._cuisine << std::endl;
    out << cur._calories << std::endl;
    out << cur._cookingTime << std::endl;
    return  out;
}

std::ostream& operator<<(std::ostream &out, Dish &cur){
    out << "�����: " << cur._name << " | �����: " << cur._cuisine << " | �������: " << cur._calories << " | ����� �������������: " << cur._cookingTime << " �����" << std::endl;
    return  out;
}

std::istream& operator>>(std::istream &in, Dish &cur){
    std::cout << "�����: ";
    in >> cur._name;
    cur._name.DelSpaces();
    std::cout << "�����: ";
    in >> cur._cuisine;
    cur._cuisine.DelSpaces();
    std::cout << "�������: ";
    in >> cur._calories;
    std::cout << "����� �������������: ";
    in >> cur._cookingTime;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return in;
}

std::ifstream& operator>>(std::ifstream &file, Dish &cur){
    file >> cur._name;
    cur._name.DelSpaces();
    file >> cur._cuisine;
    cur._cuisine.DelSpaces();
    file >> cur._calories;
    file >> cur._cookingTime;
    file.get();
    return file;
}

Dish operator+(Dish &a, Dish &b){
    Dish c;
    c._calories=c._calories;
    c._name = a._name + b._name;
    c._cuisine = a._cuisine + b._cuisine;
    return c;
}