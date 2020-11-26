//
// Created by Comrade Sanerin on 11/27/2020.
//
#include <iostream>
#include "MyString.h"

std::ostream& operator<<(std::ostream &out, const MyString &arrStr){
    out << arrStr.string;
    return out;
}

std::istream& operator>>(std::istream &in, MyString &arrStr){
    in.peek();
    std::streamsize size=in.rdbuf()->in_avail();
    if(size>0){
        arrStr.SetLength(size);
        for(std::streamsize i=0;i<size;i++) in.get(arrStr.string[i]);
        arrStr[size-1] = '\0';
    }
    return in;
}
