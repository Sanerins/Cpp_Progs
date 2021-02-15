//
// �������� �������:   �������� ������� ������ �� ������� 
//
#include "DoubleLinkedList.h"
#include <iostream>

//������� ��� ������ ��������� � ������������ �����������
DoubleLinkedList testFunction(DoubleLinkedList src)
{

	return src;
}

int main()
{
	DoubleLinkedList list;   // �������� ������� ������
	list.insertHead(2);      // ���������� ���������
	list.insertHead(3);
	list.insertHead(1);
	std::cout << list;          // ������ ���������
	list.insertTail(5);   // ���������� � �����
	list.insertTail(9);
	list.insertHead(2);
	std::cout << list;          // ������ ���������

	std::cout << ((list.searchItem(1)) ? "1 is found" : "1 is not found") << std::endl; //�������� ������ ���������
	std::cout << ((list.searchItem(8)) ? "8 is found" : "8 is not found") << std::endl;
	std::cout << list;          // ������ ���������
	list.replaceItem(2, 15, 1); //������ ���� 2 �� 15
	std::cout << list;          // ������ ���������
	list.replaceItem(9, 8); //������ ����� 9 �� 8
	std::cout << list;          // ������ ���������
	std::cout << ((list.searchItem(8)) ? "8 is found" : "8 is not found") << std::endl;
	DoubleLinkedList list1(list);  // ����������� ������ (����������� �����������)
	std::cout << list;
	std::cout << list1;
	std::cout << "Equality check: " << (list == list1) << "\n";
	list1.insertHead(4);         // ���������� ��������
	list1.insertHead(5);         // ���������� ��������
	std::cout << list1;
	list1.deleteHead();          // �������� ���������
	std::cout << list1;
	list1.deleteTail();          //�������� ������
	std::cout << list1;
	std::cout << "Equality check: " << (list == list1) << "\n";
	list.insertList(list1);  //������� ������ �����
	std::cout << "Final lists \n";
	std::cout << list;
	std::cout << list1;
	list.deleteItem(15, 1); //�������� ���� 15
	list.deleteItem(5, 0); //�������� ����� 5
	std::cout << list;
	list1 = list; //�������� ����������� ������������
	std::cout << list;
	std::cout << list1;
	std::cout << "Final check: \n";
	//DoubleLinkedList list2(testFunction(list1)); //����������� ��������
	DoubleLinkedList list2(std::move(list1)); //����������� ��������
	std::cout << list1 << " ������ ���� \n";
	std::cout << list2;
	//DoubleLinkedList list3 = testFunction(list1); //�������� ��������
	DoubleLinkedList list3 = std::move(list2); //�������� ��������
	std::cout << list2 << " ������ ���� \n";
	std::cout << list3;
	list3 = (testFunction(list3)); //�������� �� ������ ��� ��������
	std::cout << list3;
	return 0;
}