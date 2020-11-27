//
// Created by Comrade Sanerin on 11/27/2020.
//
#include "MyString.h"

std::wostream& operator<<(std::wostream &out, const MyString &arrStr){
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

std::wistream& operator>>(std::wistream &in, MyString &arrStr){
    while(in.peek()){
        wchar_t c;
        c = in.get();
        arrStr.Upend(c);
        //std::cout << c;
        if(in.peek()=='\n') break;
    }
    //std::cout << "Hooray!";
    return in;
}
