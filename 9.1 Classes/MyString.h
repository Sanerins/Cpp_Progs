//
// Created by Comrade Sanerin on 11/27/2020.
//
#ifndef INC_9_1_CLASSES_MYSTRING_H
#define INC_9_1_CLASSES_MYSTRING_H
#include <iostream>
class MyString{
private:
    int _size;
    int _currSize;
    wchar_t *_string;

    void CheckSize() {
        if(_currSize == _size){
            int size = (int)(_size * 1.5 + 0.5);
            wchar_t *temp = new wchar_t[size];
            for(int i=0; i < _currSize; i++) {
                temp[i] = _string[i];
            }
            delete [] _string;
            _string = temp;
            _size = size;
        }
    }

    void SetLength(long long length){
        if(_string) delete [] _string;
        _string = new wchar_t[length];
        _currSize = length;
        _size=length;
    }

public:

    MyString(): _size(5), _currSize(1), _string(new wchar_t[_size]){
        _string[0] = '\0';
    }

    ~MyString(){
        delete [] _string;
    }

    int Length() {return _currSize;}

    int MaxLength() {return _size;}

    void Upend(wchar_t unit){
        Insert(unit, _currSize - 1);
    }

    void Insert(wchar_t unit, int place = 0){
        CheckSize();
        if(place > _currSize - 1){
            place = _currSize - 1;
        }
        for(int i = _currSize - 1; i >= place; i--){
            _string[i + 1] = _string[i];
        }
        _currSize++;
        _string[place] = unit;
    }

    wchar_t& operator[](int place){
        return _string[place];
    }

    MyString& operator=(const wchar_t* str){
        int len = 1;
        const wchar_t* temp = str;
        while(*str){
            len++;
            str++;
        }
        this->SetLength(len);
        for(int i = 0; i < len; i++){
            (*this)[i] = temp[i];
        }
        return *this;
    }

    friend std::wostream& operator<<(std::wostream &out, const MyString &arrStr);

    friend std::wistream& operator>>(std::wistream &in, MyString &arrStr);

};

#endif //INC_9_1_CLASSES_MYSTRING_H
