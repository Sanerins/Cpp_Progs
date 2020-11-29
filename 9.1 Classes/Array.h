//
// Created by Comrade Sanerin on 11/26/2020.
//
#ifndef INC_9_1_CLASSES_ARRAY_H
#define INC_9_1_CLASSES_ARRAY_H
#include "MyString.h"
template <typename T>
class Array{
private:
    int _size;
    int _currSize;
    T *_array;

    void CheckSize() {
        if(_currSize == _size){
            int size = (int)(_size * 1.5 + 0.5);
            T *temp = new T[size];
            for(int i=0; i < _currSize; i++) {
                temp[i] = _array[i];
            }
            delete [] _array;
            _array = temp;
            _size = size;
        }
    }

public:

    Array(int size = 5):_size(size){
        _array = new T[size];
        _currSize = 0;
    }

    ~Array(){
        //delete [] _array;
    }

    int Length() {return _currSize;}

    int MaxLength() {return _size;}

    void Insert(T &unit, int place = 0){
        CheckSize();
        if(place > _currSize){
            place = _currSize;
        }
        for(int i = _currSize-1; i >= place; i--){
            _array[i + 1] = _array[i];
        }
        _currSize++;
        _array[place] = unit;
    }

    void Upend(T &unit){
        Insert(unit, _currSize);
    }

    T& FindTextInArray(MyString m){
        for(int i = 0; i < _currSize; i++){
            if (_array[i] == m) return _array[i];
        }
        T unit;
        unit = m;
        Upend(unit);
        return _array[_currSize-1];
    }

    T& FindMax(){
        T max = _array[0];
        int num = 0;
        for(int i = 1; i < _currSize; i++){
            if (max<_array[i]) {
                num = i;
                max = _array[i];
            }
        }
        return _array[num];
    }

    T& FindMin(){
        T min = _array[0];
        int num = 0;
        for(int i = 1; i < _currSize; i++){
            if (min>_array[i]) {
                num = i;
                min = _array[i];
            }
        }
        return _array[num];
    }

    void Sort(){
        T temp;
        for(int i = 0; i<_currSize; i++){
            temp = _array[i];
            T min = _array[i];
            int iMin = i;
            for(int j = i+1; j < _currSize; j++){
                if(min>_array[j]) {
                    min = _array[j];
                    iMin = j;
                }
            }
            _array[i] = min;
            _array[iMin] = temp;
        }
    }

    T& operator[](int place){
        return _array[place];
    }

};

#endif //INC_9_1_CLASSES_ARRAY_H
