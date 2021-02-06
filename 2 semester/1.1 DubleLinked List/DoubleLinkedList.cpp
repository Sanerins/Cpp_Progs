#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - ������ ������� ������ ����� ����� - ���������� ������� ������  
//
#include <iostream>

// ����������� "�� ���������" - �������� ������� ������ - ��. �������� ������
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

// ����������� "�����������" � �������� ����� ���������� ������
 // DoubleLinkedList::DoubleLinkedList (const DoubleLinkedList::DoubleLinkedList & src) {}

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

void DoubleLinkedList::insertList(DoubleLinkedList* src){

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
//  int DoubleLinkedList::�ount()const{ return count_; }

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

//�������� ����������� ������������
DoubleLinkedList& DoubleLinkedList::operator= (const DoubleLinkedList &src){

}

//�������� ������������� ������������
DoubleLinkedList& DoubleLinkedList::operator= (DoubleLinkedList &&src){

}

//�������� ������ ������

std::ostream& operator<<(std::ostream& out, DoubleLinkedList& src){
    DoubleLinkedList::Node* x = src.head_;
    while (x != nullptr){
        out << x->item_ << " ";
    }
    out << " ";
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
