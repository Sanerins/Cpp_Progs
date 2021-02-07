#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - Дважды связный список целых чисел - реализация методов класса  
//
#include <iostream>

// Конструктор "по умолчанию" - создание пустого списка - см. Описание класса
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

//Конструктор копирования, создание копии списка
 DoubleLinkedList::DoubleLinkedList (const DoubleLinkedList &src) {
    if(!src.head_){
        count_ = 0;
        head_ = nullptr;
        tail_ = nullptr;
        return;
    }
    count_ = 0;
    head_ = new Node(src.head_->item_);
    tail_ = nullptr;
    Node* current = head_;
    Node* srcCurrent = src.head_;
    for(int i = 1; i < src.count_; i++){
        current->next_ = new Node(srcCurrent->next_->item_);
        current->next_->prev_ = current;
        current = current->next_;
        srcCurrent = srcCurrent ->next_;
    }
    tail_ = current;
    count_ = src.count_;
    return;
}

//Конструктор перемещения, создание одного, не сохранения другого
 DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& src): count_(src.count_), head_(src.head_), tail_(src.tail_) {
    src.head_ = nullptr;
    src.tail_ = nullptr;
    src.count_ = 0;
}

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

//Вставка узлов другого списка в первый список путем перемещения
void DoubleLinkedList::insertList(DoubleLinkedList& src){
//    for(int i = 0; i < src->count_; i++){
//        insertTail(src->head_);
//        src->deleteHead();
//    }
    if(src.head_ == nullptr){
        return;
    }
    else if(head_ == nullptr){
        swap(src);
        return;
    }
    else {
        src.head_->prev_ = tail_;
        tail_->next_ = src.head_;
        src.head_ = nullptr;
        tail_ = src.tail_;
        src.tail_ = nullptr;
        count_ += src.count_;
        src.count_ = 0;
    }
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
//  int DoubleLinkedList::count()const{ return count_; }

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
                replaceNode(searchNode(itemOld), itemNew);
            }
        }
        else {
            replaceNode(searchNode(itemOld), itemNew);
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

void DoubleLinkedList::purify()
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
    if(*this == src){
        return *this;
    }
    else{
        DoubleLinkedList tempList(src);
        swap(tempList);
        return *this;
    }
}
//Метод для copy and swap алгоритма
void DoubleLinkedList::swap(DoubleLinkedList &src) {
    Node* tempHead = head_;
    Node* tempTail = tail_;
    int tempCount = count_;
    head_ = src.head_;
    tail_ = src.tail_;
    count_ = src.count_;
    src.head_ = tempHead;
    src.tail_ = tempTail;
    src.count_ = tempCount;
}

//Оператор перемещающего присваивания
DoubleLinkedList& DoubleLinkedList::operator= (DoubleLinkedList &&src){
    if(head_ != nullptr){
        purify();
    }
    head_ = src.head_;
    tail_ = src.tail_;
    count_ = src.count_;
    src.head_ = nullptr;
    src.tail_ = nullptr;
    src.count_ = 0;
    return *this;
}

//Оператор вывода списка
std::ostream& operator<<(std::ostream& out, DoubleLinkedList& src){
    DoubleLinkedList::Node* x = src.head_;
    while (x != nullptr){
        out << x->item_ << " ";
        x = x->next_;
    }
    out << "\n";
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
