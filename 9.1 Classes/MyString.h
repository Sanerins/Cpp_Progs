//
// Created by Comrade Sanerin on 11/27/2020.
//
#include <iostream>
#ifndef INC_9_1_CLASSES_MYSTRING_H
#define INC_9_1_CLASSES_MYSTRING_H
class MyString{
private:
    int _size;
    int _currSize;
    char *_string;

    void CheckSize() {
        if(_currSize == _size){
            int size = (int)(_size * 1.5 + 0.5);
            char *temp = new char[size];
            for(int i=0; i < _currSize; i++) {
                temp[i] = _string[i];
            }
            if(_string[0] != NULL) delete [] _string;
            _string = temp;
            _size = size;
        }
    }

    void SetLength(long long length){
        if(_string[0] != NULL) delete [] _string;
        _string = new char[length];
        _currSize = length;
        _size=length;
    }

public:

    MyString(): _size(5), _currSize(1), _string(new char[_size]){
        _string[0] = '\0';
    }

    MyString(const char* str){
        _string = new char [0];
        int len = 1;
        const char* temp = str;
        while(*str){
            len++;
            str++;
        }
        this->SetLength(len);
        for(int i = 0; i < len; i++){
            (*this)[i] = temp[i];
        }
    }

    MyString& operator=(const char* str){
        int len = 1;
        const char* temp = str;
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

    MyString& operator=(const MyString& str){
        this->_size = str._size;
        this->_currSize = str._currSize;
        _string = new char[_size];
        for(int i = 0; i < _currSize; i++){
            this->_string[i] = str._string[i];
        }
        return *this;
    }

    MyString& operator+=(MyString a){
        int size = 0;
        int maxSize = a.MaxLength() + this->MaxLength();
        char *temp = this->_string;
        _string = new char[maxSize];
        while(*temp){
            this->_string[size]=*temp;
            size++;
            temp++;
        }
        for(int i=0; i < a.Length(); i++){
            _string[size]=a[i];
            size++;
        }
        this->_currSize = size;
        this->_size=maxSize;
        return *this;
    }

    MyString& operator+=(const char* a){
        int len = 1;
        const char* temp = (a);
        while(*a){
            len++;
            a++;
        }
        for(int i = 0; i < len; i++){
            this->Upend(temp[i]);
        }
        return *this;
    }

    char& operator[](int place){
        return _string[place];
    }

    bool operator==(MyString &a);

    friend std::ostream& operator<<(std::ostream &out, const MyString &arrStr);

    friend std::istream& operator>>(std::istream &in, MyString &arrStr);

    friend MyString operator+(MyString& a, MyString& b);

    friend MyString operator+(MyString& a, const char* b);

    ~MyString(){
        //if(_string[0] != NULL) delete [] _string;
    }

    int Length() {return _currSize;}

    int MaxLength() {return _size;}

    void Upend(char unit){
        Insert(unit, _currSize - 1);
    }

    void Insert(char unit, int place = 0){
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

};

#endif //INC_9_1_CLASSES_MYSTRING_H
