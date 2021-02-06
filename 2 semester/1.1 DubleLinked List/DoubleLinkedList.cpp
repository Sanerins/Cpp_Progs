#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - Дважды связный список целых чисел - реализация методов класса  
//
#include <iostream>

// Конструктор "по умолчанию" - создание пустого списка - см. Описание класса
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

// Конструктор "копирования" – создание копии имеющегося списка
 // DoubleLinkedList::DoubleLinkedList (const DoubleLinkedList::DoubleLinkedList & src) {}

// Вставить сформированный узел в хвост списка
void DoubleLinkedList::insertTail(Node* x) 
{
	if (tail_ != nullptr) {
        tail_->next_ = x;
    }
	tail_ = x;
	count_++;
}

// Вставить сформированный узел в начало списка
void DoubleLinkedList::insertHead(Node* x)  
{   // x->prev_ == nullptr,  x->next_ == nullptr  
	x->next_ = head_;
	if (head_ != nullptr) {
		// список был НЕ пуст – новый элемент будет и первым, и последним
		head_->prev_ = x;
	}
	else {
		// список был пуст – новый элемент будет и первым, и последним
		tail_ = x;
	}
	head_ = x;
	count_++;  // число элементов списка увеличилось
}

void DoubleLinkedList::insertList(DoubleLinkedList* src){

}

// Удаление заданного узла 
void DoubleLinkedList::deleteNode(Node* x)
{
	if (x == nullptr) {
		throw ("DoubleLinkedList::deleteNode  - неверно задан адрес удаляемого узла");
	}
	if (x->prev_ != nullptr) {
		// удаляется НЕ голова списка
		(x->prev_)->next_ = x->next_;
	}
	else {
		// удаляется голова списка,  второй элемент становится первым
		head_ = x->next_;
	}
	if (x->next_ != nullptr) {
		// удаляется НЕ хвост
		(x->next_)->prev_ = x->prev_;
	}
	else {
		// удаляется хвост
		tail_ = x->prev_;
	}
	delete x;      // 
	count_--;     // число элементов списка уменьшилось
}

// Поиск узла (адрес) с заданным значением  
DoubleLinkedList::Node* DoubleLinkedList::searchNode(int item)
{
	Node* x = head_;
	while (x != nullptr && x->item_ != item) {
		x = x->next_;
	}
	return x;
}

// Замена информации узла на новое 
DoubleLinkedList::Node* DoubleLinkedList::replaceNode(DoubleLinkedList::Node* x, int item)
{
    x->item_ = item;
	return x; // !!!!!
}

// количество элементов списка
//  int DoubleLinkedList::сount()const{ return count_; }

// Доступ к информации головного узла списка
int DoubleLinkedList::headItem() const
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - список пуст!");
}

int& DoubleLinkedList::headItem()
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - список пуст!");
}

// Доступ к информации хвостового узла списка
int DoubleLinkedList::tailItem() const
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - список пуст!");
}
int& DoubleLinkedList::tailItem()
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - список пуст!");
}

// Вставить элемент в голову списка
void DoubleLinkedList::insertHead(int item)
{   // создаем новый элемент списка и добавляем в голову 
	insertHead(new Node(item));
}


// Вставить элемент в хвост списка
void DoubleLinkedList::insertTail(int item)
{   // создаем новый элемент списка и добавляем в хвост 
	insertTail(new Node(item));
}

// Удалить элемент с головы списка
bool DoubleLinkedList::deleteHead()
{
	if (head_ == nullptr) {
		return 0;  // список пуст, удалений нет
	}
	deleteNode(head_);
	return 1;      // список был НЕ пуст, удаление головы
}

// Удалить элемент из хвоста списка
bool DoubleLinkedList::deleteTail()
{
	if (tail_ == nullptr){
	    return 0;
	}
	deleteNode(tail_);
	return 1;
}

// Удаление узла с заданным значением  
bool DoubleLinkedList::deleteItem(const int item, const bool all)
{
	if(searchItem(item)){
	    if(all){
	        while(searchItem(item)){
                Node *x = searchNode(item);
                deleteNode(x);
	        }
	    }
	    else {
            Node *x = searchNode(item);
            deleteNode(x);
        }
	    return 1;
	}
	else{
	    return 0;
	}
}

// Поиск записи с заданным значением  
bool DoubleLinkedList::searchItem(int item)
{   // возвращаем TRUE, если узел найден 
	return (searchNode(item) != nullptr);
}


// Замена информации узла на новое 
bool DoubleLinkedList::replaceItem(const int itemOld,const int itemNew, const bool all)
{
    if(searchItem(itemOld)){
        if(all){
            while(searchItem(itemOld)){
                Node *x = searchNode(itemOld);
                deleteNode(x);
            }
        }
        else {
            Node *x = searchNode(itemOld);
            deleteNode(x);
        }
        return 1;
    }
    else{
        return 0;
    }
}

// Вывод элементов списка в текстовом виде в стандартный выходной поток 
void DoubleLinkedList::outAll()
{
	Node* current = head_;       // Указатель на элемент
	while (current != nullptr) {
		std::cout << current->item_ << ' ';
		current = current->next_;  // Переход к следующему элементу
	}
	std::cout << std::endl;
}

// Деструктор списка	
DoubleLinkedList::~DoubleLinkedList()
{
	Node* current = nullptr;   // указатель на элемент, подлежащий удалению
	Node* next = head_;        // указатель на следующий элемент
	while (next != nullptr) {  // пока есть еще элементы в списке
		current = next;
		next = next->next_;    // переход к следующему элементу
		delete current;        // освобождение памяти
	}
}

//Оператор копирующего присваивания
DoubleLinkedList& DoubleLinkedList::operator= (const DoubleLinkedList &src){

}

//Оператор перемещающего присваивания
DoubleLinkedList& DoubleLinkedList::operator= (DoubleLinkedList &&src){

}

//Оператор вывода списка

std::ostream& operator<<(std::ostream& out, DoubleLinkedList& src){
    DoubleLinkedList::Node* x = src.head_;
    while (x != nullptr){
        out << x->item_ << " ";
    }
    out << " ";
    return out;
}

//Оператор сравнения списков

bool DoubleLinkedList::operator==(const DoubleLinkedList &src){
    Node* x = head_;
    Node* y = src.head_;
    if(count_ != src.count_){
        return 0;
    }
    else{
        while(x != nullptr){
            if(x->item_ != y->item_){
                return 0;
            }
            else{
                x = x->next_;
                y = y->next_;
            }
        }
    }
    return 1;
}
