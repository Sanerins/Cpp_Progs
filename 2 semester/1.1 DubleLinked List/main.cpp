//
// Тестовая функция:   проверка методов работы со списком 
//
#include "DoubleLinkedList.h"
#include <iostream>

//Функция для вызова оператора и конструктора перемещения
DoubleLinkedList testFunction(DoubleLinkedList src)
{

	return src;
}

int main()
{
	DoubleLinkedList list;   // Создание пустого списка
	list.insertHead(2);      // Добавление элементов
	list.insertHead(3);
	list.insertHead(1);
	std::cout << list;          // Печать элементов
	list.insertTail(5);   // Добавление в конец
	list.insertTail(9);
	list.insertHead(2);
	std::cout << list;          // Печать элементов

	std::cout << ((list.searchItem(1)) ? "1 is found" : "1 is not found") << std::endl; //Проверка поиска элементов
	std::cout << ((list.searchItem(8)) ? "8 is found" : "8 is not found") << std::endl;
	std::cout << list;          // Печать элементов
	list.replaceItem(2, 15, 1); //Замена всех 2 на 15
	std::cout << list;          // Печать элементов
	list.replaceItem(9, 8); //Замена одной 9 на 8
	std::cout << list;          // Печать элементов
	std::cout << ((list.searchItem(8)) ? "8 is found" : "8 is not found") << std::endl;
	DoubleLinkedList list1(list);  // Копирование списка (конструктор копирования)
	std::cout << list;
	std::cout << list1;
	std::cout << "Equality check: " << (list == list1) << "\n";
	list1.insertHead(4);         // Добавление элемента
	list1.insertHead(5);         // Добавление элемента
	std::cout << list1;
	list1.deleteHead();          // Удаление головного
	std::cout << list1;
	list1.deleteTail();          //Удаление хвоста
	std::cout << list1;
	std::cout << "Equality check: " << (list == list1) << "\n";
	list.insertList(list1);  //Вставка нового листа
	std::cout << "Final lists \n";
	std::cout << list;
	std::cout << list1;
	list.deleteItem(15, 1); //Удаление всех 15
	list.deleteItem(5, 0); //Удаление одной 5
	std::cout << list;
	list1 = list; //Оператор копирующего присваивания
	std::cout << list;
	std::cout << list1;
	std::cout << "Final check: \n";
	//DoubleLinkedList list2(testFunction(list1)); //Конструктор переноса
	DoubleLinkedList list2(std::move(list1)); //Конструктор переноса
	std::cout << list1 << " Пустой лист \n";
	std::cout << list2;
	//DoubleLinkedList list3 = testFunction(list1); //Оператор переноса
	DoubleLinkedList list3 = std::move(list2); //Оператор переноса
	std::cout << list2 << " Пустой лист \n";
	std::cout << list3;
	list3 = (testFunction(list3)); //Проверка на утечку при непустом
	std::cout << list3;
	return 0;
}