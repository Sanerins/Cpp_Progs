#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - ������ ������� ������ ����� ����� - ���������� ������� ������  
//
#include <iostream>

// ����������� "�� ���������" - �������� ������� ������ - ��. �������� ������
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

//����������� �����������, �������� ����� ������
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

//����������� �����������, �������� ������, �� ���������� �������
 DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& src): count_(src.count_), head_(src.head_), tail_(src.tail_) {
    src.head_ = nullptr;
    src.tail_ = nullptr;
    src.count_ = 0;
}

// �������� �������������� ���� � ����� ������
void DoubleLinkedList::insertTail(Node* x) 
{
	if (tail_ != nullptr) {
        tail_->next_ = x;
    }
	tail_ = x;
	count_++;
}

// �������� �������������� ���� � ������ ������
void DoubleLinkedList::insertHead(Node* x)  
{   // x->prev_ == nullptr,  x->next_ == nullptr  
	x->next_ = head_;
	if (head_ != nullptr) {
		// ������ ��� �� ���� � ����� ������� ����� � ������, � ���������
		head_->prev_ = x;
	}
	else {
		// ������ ��� ���� � ����� ������� ����� � ������, � ���������
		tail_ = x;
	}
	head_ = x;
	count_++;  // ����� ��������� ������ �����������
}

//������� ����� ������� ������ � ������ ������ ����� �����������
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

// �������� ��������� ���� 
void DoubleLinkedList::deleteNode(Node* x)
{
	if (x == nullptr) {
		throw ("DoubleLinkedList::deleteNode  - ������� ����� ����� ���������� ����");
	}
	if (x->prev_ != nullptr) {
		// ��������� �� ������ ������
		(x->prev_)->next_ = x->next_;
	}
	else {
		// ��������� ������ ������,  ������ ������� ���������� ������
		head_ = x->next_;
	}
	if (x->next_ != nullptr) {
		// ��������� �� �����
		(x->next_)->prev_ = x->prev_;
	}
	else {
		// ��������� �����
		tail_ = x->prev_;
	}
	delete x;      // 
	count_--;     // ����� ��������� ������ �����������
}

// ����� ���� (�����) � �������� ���������  
DoubleLinkedList::Node* DoubleLinkedList::searchNode(int item)
{
	Node* x = head_;
	while (x != nullptr && x->item_ != item) {
		x = x->next_;
	}
	return x;
}

// ������ ���������� ���� �� ����� 
DoubleLinkedList::Node* DoubleLinkedList::replaceNode(DoubleLinkedList::Node* x, int item)
{
    x->item_ = item;
	return x; // !!!!!
}

// ���������� ��������� ������
//  int DoubleLinkedList::count()const{ return count_; }

// ������ � ���������� ��������� ���� ������
int DoubleLinkedList::headItem() const
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - ������ ����!");
}

int& DoubleLinkedList::headItem()
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - ������ ����!");
}

// ������ � ���������� ���������� ���� ������
int DoubleLinkedList::tailItem() const
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - ������ ����!");
}
int& DoubleLinkedList::tailItem()
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - ������ ����!");
}

// �������� ������� � ������ ������
void DoubleLinkedList::insertHead(int item)
{   // ������� ����� ������� ������ � ��������� � ������ 
	insertHead(new Node(item));
}


// �������� ������� � ����� ������
void DoubleLinkedList::insertTail(int item)
{   // ������� ����� ������� ������ � ��������� � ����� 
	insertTail(new Node(item));
}

// ������� ������� � ������ ������
bool DoubleLinkedList::deleteHead()
{
	if (head_ == nullptr) {
		return 0;  // ������ ����, �������� ���
	}
	deleteNode(head_);
	return 1;      // ������ ��� �� ����, �������� ������
}

// ������� ������� �� ������ ������
bool DoubleLinkedList::deleteTail()
{
	if (tail_ == nullptr){
	    return 0;
	}
	deleteNode(tail_);
	return 1;
}

// �������� ���� � �������� ���������  
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

// ����� ������ � �������� ���������  
bool DoubleLinkedList::searchItem(int item)
{   // ���������� TRUE, ���� ���� ������ 
	return (searchNode(item) != nullptr);
}


// ������ ���������� ���� �� ����� 
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

// ����� ��������� ������ � ��������� ���� � ����������� �������� ����� 
void DoubleLinkedList::outAll()
{
	Node* current = head_;       // ��������� �� �������
	while (current != nullptr) {
		std::cout << current->item_ << ' ';
		current = current->next_;  // ������� � ���������� ��������
	}
	std::cout << std::endl;
}

// ���������� ������	
DoubleLinkedList::~DoubleLinkedList()
{
	Node* current = nullptr;   // ��������� �� �������, ���������� ��������
	Node* next = head_;        // ��������� �� ��������� �������
	while (next != nullptr) {  // ���� ���� ��� �������� � ������
		current = next;
		next = next->next_;    // ������� � ���������� ��������
		delete current;        // ������������ ������
	}
}

void DoubleLinkedList::purify()
{
    Node* current = nullptr;   // ��������� �� �������, ���������� ��������
    Node* next = head_;        // ��������� �� ��������� �������
    while (next != nullptr) {  // ���� ���� ��� �������� � ������
        current = next;
        next = next->next_;    // ������� � ���������� ��������
        delete current;        // ������������ ������
    }
}

//�������� ����������� ������������
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
//����� ��� copy and swap ���������
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

//�������� ������������� ������������
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

//�������� ������ ������
std::ostream& operator<<(std::ostream& out, DoubleLinkedList& src){
    DoubleLinkedList::Node* x = src.head_;
    while (x != nullptr){
        out << x->item_ << " ";
        x = x->next_;
    }
    out << "\n";
    return out;
}

//�������� ��������� �������
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
