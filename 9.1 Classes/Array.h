//
// Created by Comrade Sanerin on 11/26/2020.
//
#ifndef INC_9_1_CLASSES_ARRAY_H
#define INC_9_1_CLASSES_ARRAY_H

template <typename T>
class Array{
private:
    int _size;
    int _currSize;
    T *array;

    void CheckSize() {
        if(_currSize == _size){
            int size = (int)(_size * 1.5 + 0.5);
            T *temp = new T[size];
            for(int i=0; i < _currSize; i++) {
                temp[i] = array[i];
            }
            delete array;
            array = temp;
            _size = size;
        }
    }

public:

    Array(int size = 5):_size(size){
        array = new T[size];
        _currSize = 0;
    }

    ~Array(){
        delete array;
    }

    int Length() {return _currSize;}

    void Insert(T unit, int place = 0){
        CheckSize();
        if(place > _currSize){
            place = _currSize;
        }
        for(int i = _currSize-1; i >= place; i--){
            array[i+1] = array[i];
        }
        _currSize++;
        array[place] = unit;
    }

    void Upend(T unit){
        Insert(unit, _currSize);
    }

    T& operator[](int place){
        return array[place];
    }

};

#endif //INC_9_1_CLASSES_ARRAY_H
