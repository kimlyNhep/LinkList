#pragma once
#include <iostream>
using namespace std;

struct node {
	int value;
	node *next = NULL;
};
struct list {
	node *pHead = NULL;
	node *pTail = NULL;
};
void add(list *l, const int val) {
	if (l->pHead == NULL) {
		l->pHead = new node();
		l->pTail = l->pHead;
		l->pTail->value = val;	
	}
	else {
		l->pTail->next = new node();
		l->pTail = l->pTail->next;
		l->pTail->value = val;
	}
	l->pTail->next = NULL;
}
void print(list *l) {
	node *p = l->pHead;
	while (p != NULL) {
		cout << p->value << endl;
		p = p->next;
	}
}
int search(list *l,const int value) {
	node *p = l->pHead;
	int index = 0;
	while (p != NULL) {
		if (p->value == value) {
			return index;
		}
		p = p->next;
		index++;
	}
	return -1;
}
void add(list *l, const int val, const unsigned int pos) {
	node *newptr = new node();
	newptr->next = NULL;
	int i = 0;
	newptr->value = val;
	if (l->pHead == NULL) {
		l->pHead = new node();
		l->pTail = l->pHead;
		l->pTail->value = val;
	}
	else {
		if (pos == 0) {
			newptr->next = l->pHead;
			l->pHead = newptr;
		}
		else {
			node *ptr = l->pHead;
			while (i < pos - 1 && ptr->next != NULL) {
				ptr = ptr->next;
				i++;
			}
			newptr->next = ptr->next;
			ptr->next = newptr;
		}
	}
}
void remove(list *l, const unsigned int index) {
	if (index == 0) {
		if (l->pHead != NULL) {
			node *temp = l->pHead;
			l->pHead = l->pHead->next;
			temp->next = NULL;
			delete temp;
		}
	}
	else {
		node *tmp = l->pHead;
		int i = 0;
		while (tmp->next != NULL && i < index - 1) {
			i++;
			tmp = tmp->next;
		}
		if (tmp->next != NULL) {
			node *n = tmp->next;
			tmp->next = n->next;
			n->next = NULL;
			delete n;
		}
	}
	return;
}