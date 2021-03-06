#include "stdafx.h"
#include <iostream>

using namespace std;

class node {
public:
	int value;
	node *next;
	node() {
		next = NULL;
	}
};
class list {
	node *pHead;
	node *pTail;
public:
	list() {
		pHead = NULL;
		pTail = NULL;
	}
	void print() {
		node *temp = this->pHead;
		while (temp != NULL) {
			cout << temp->value << endl;
			temp = temp->next;
		}
	}
	void add(const int value) {
		if (this->pHead == NULL) {
			this->pHead = new node();
			this->pTail = this->pHead;
			this->pTail->value = value;
		}
		else {
			this->pTail->next = new node();
			this->pTail = this->pTail->next;
			this->pTail->value = value;
		}
		this->pTail->next = NULL;
	}
	void add(const int value, const unsigned int index) {
		node *newnode = new node();
		newnode->value = value;
		newnode->next = NULL;
		int i = 0;
		if (index == 0) {
			newnode->next = this->pHead;
			this->pHead = newnode;
		}
		else {
			node *ptr = this->pHead;
			while (ptr->next != NULL && i < index - 1) {
				ptr = ptr->next;
				i++;
			}
			newnode->next = ptr->next;
			ptr->next = newnode;
		}
	}
	void remove(const unsigned int index) {
		if (this->pHead != NULL) {
			int i = 0;
			if (index == 0) {
				node *temp = this->pHead;
				this->pHead = this->pHead->next;
				temp->next = NULL;
				delete temp;
			}
			else {
				node *temp = this->pHead;
				while (temp->next != NULL && i < index - 1) {
					temp = temp->next;
					i++;
				}
				node *n = temp->next;
				temp->next = n->next;
				n->next = NULL;
				delete n;
			}
		}
		return;
	}
};
int main()
{
	list Mylist;
	Mylist.add(2);
	Mylist.add(4);
	Mylist.add(8);
	Mylist.add(10);
	Mylist.add(7, 0);
	Mylist.add(13, 9);
	Mylist.remove(2);
	Mylist.print();
	system("pause");
    return 0;
}

