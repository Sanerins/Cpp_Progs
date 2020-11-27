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
        delete [] _array;
    }

    int Length() {return _currSize;}

    int MaxLength() {return _size;}

    void Insert(T unit, int place = 0){
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

    void Upend(T unit){
        Insert(unit, _currSize);
    }

    T& operator[](int place){
        return _array[place];
    }

};

#endif //INC_9_1_CLASSES_ARRAY_H
