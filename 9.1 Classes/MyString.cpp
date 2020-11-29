//
// Created by Comrade Sanerin on 11/27/2020.
//
#include "MyString.h"

std::ostream& operator<<(std::ostream &out, const MyString &arrStr){
    out << arrStr._string;
    return out;
}

//std::istream& operator>>(std::istream &in, MyString &arrStr){
//    in.sync_with_stdio(false);
//    in.peek();
//    std::streamsize size=in.rdbuf()->in_avail();
//
//    if(size>0){
//        arrStr.SetLength(size);
//        for(std::streamsize i=0;i<size;i++) in.get(arrStr._string[i]);
//        arrStr[size-1] = '\0';
//    }
//    in.sync_with_stdio(true);
//    return in;
//}

std::istream& operator>>(std::istream &in, MyString &arrStr){
    arrStr.SetLength(1);
    arrStr[0] = '\0';
    while(in.peek()){
        char c;
        in.get(c);
        arrStr.Upend(c);
        if(in.peek()=='\n') break;
    }
    in.get();
    //std::cout << "Hooray!";
    return in;
}

MyString operator+(MyString& a, MyString& b){
    MyString c;
    int size = 0;
    int maxSize = a.MaxLength() + b.MaxLength();
    c._string = new char[maxSize];
    for(int i=0; i < a.Length()-1; i++){
        c._string[size]=a[i];
        size++;
    }
    for(int i=0; i < b.Length()-1; i++){
        c._string[size]=b[i];
        size++;
    }
    c._currSize = size;
    c._size=maxSize;
    return c;
}

bool MyString::operator==(MyString &a){
    return *this == a;
}

MyString operator+(MyString& a, const char* b){
    int len = 1;
    const char* temp = b;
    while(*b){
        len++;
        b++;
    }
    for(int i = 0; i < len; i++){
        a.Upend(temp[i]);
    }
    return a;
}
