//
// Created by Comrade Sanerin on 08.12.2020.
//

#ifndef INC_9_1_CLASSES_EXCEPTIONS_H
#define INC_9_1_CLASSES_EXCEPTIONS_H

#include <exception>
#include "MyString.h"

struct BadChoise : public std::exception {
    MyString Text() throw(){
        return "�� ������ ������������ ������ ��������� � ���� �����!\n";
    }
};

struct BadDish : public std::exception {
    MyString Text() throw(){
        return "����� ���� ������� �����������!\n";
    }
};

struct BadFile : public std::exception {
    MyString Text() throw(){
        return "��� ����� ���� ������� �����������!\n";
    }
};

#endif //INC_9_1_CLASSES_EXCEPTIONS_H
