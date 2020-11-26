//
// Created by Comrade Sanerin on 11/27/2020.
//

#ifndef INC_9_1_CLASSES_MYSTRING_H
#define INC_9_1_CLASSES_MYSTRING_H

class MyString{
private:
    int _size;
    char *string;

    void Expand() {
        char *temp = new char[_size + 1];
        for(int i=0; i < _size; i++) {
            temp[i] = string[i];
        }
        delete string;
        string = temp;
    }

    void SetLength(std::streamsize length){
        string = new char[length];
        _size = length;
    }

public:

    MyString(){
    }

    ~MyString(){
        delete string;
    }

    int Length() {return _size;}

    void Upend(char unit){
        Insert(unit, _size-1);
    }

    void Insert(char unit, int place = 0){
        Expand();
        if(place > _size-1){
            place = _size-1;
        }
        for(int i = _size-1; i >= place; i--){
            string[i + 1] = string[i];
        }
        _size++;
        string[place] = unit;
    }

    char& operator[](int place){
        return string[place];
    }

    friend std::ostream& operator<<(std::ostream &out, const MyString &arrStr);

    friend std::istream& operator>>(std::istream &in, MyString &arrStr);
};

#endif //INC_9_1_CLASSES_MYSTRING_H
