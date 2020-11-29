//
// Created by Comrade Sanerin on 28.11.2020.
//

#include "Cuisine.h"

bool Cuisine::operator>(Cuisine &a){
    return this->_Dishes.Length()>a._Dishes.Length();
}

bool Cuisine::operator<(Cuisine &a){
    return this->_Dishes.Length()<a._Dishes.Length();
}

bool Cuisine::operator!=(Cuisine &a){
    return this->_Dishes.Length()!=a._Dishes.Length();
}

bool Cuisine::operator==(Cuisine &a){
    return this->_Dishes.Length()==a._Dishes.Length();
}

bool Cuisine::operator==(MyString &a){
    return this-> _name == a;
}

bool Cuisine::operator^(Cuisine &a){
    return this->_Dishes.Length()^a._Dishes.Length();
}

bool Cuisine::operator&&(Cuisine &a){
    return this->_Dishes.Length()&&a._Dishes.Length();
}

bool Cuisine::operator||(Cuisine &a){
    return this->_Dishes.Length()||a._Dishes.Length();
}
