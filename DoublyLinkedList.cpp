#include "stdafx.h"
#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

template <class Type> DoublyLinkedList<Type>::DoublyLinkedList()
{
	pHead = pTail = NULL;
	count = 0;
}


template <class Type> DoublyLinkedList<Type>::~DoublyLinkedList()
{

}

template <class Type> void DoublyLinkedList<Type>::Add(Type value)
{
	if (count == 0) {
		pHead = pTail = new node<Type>();
		pTail->value = value;
		pTail->next = NULL;
		pTail->prev = NULL; 
	}
	else {
		pTail->next = new node<Type>();
		pTail->next->prev = pTail;
		pTail = pTail->next;
		pTail->value = value;
		pTail->next = NULL;
	}
	count++;
}
template <class Type> void DoublyLinkedList<Type>::Add(Type value, int index)
{
	if (count == 0 || index >= count) Add(value);
	else if (index <= 0) {
		node <Type>*tmp = new node<Type>();
		tmp->value = value;
		tmp->next = pHead;
		tmp->prev = NULL;
		pHead->prev = tmp;
		pHead = tmp;
	}
	else {
		int i = 0;
		node <Type>*tmp = new node<Type>();
		tmp->value = value;
		node <Type>*ptr = pHead;
		while (i < index - 1 && ptr != NULL) {
			ptr = ptr->next;
			i++;
		}
		if (ptr->next != NULL) {
			tmp->next = ptr->next;
			ptr->next->prev = tmp;
			tmp->prev = ptr;
			ptr->next = tmp;
			count++;
		}
	}
}
template <class Type> void DoublyLinkedList<Type>::print()
{
	node <Type>*temp = pHead;
	while (temp != NULL) {
		cout << temp->value << endl;
		temp = temp->next;
	}
}
template <class Type> void DoublyLinkedList<Type>::Remove()
{
	if (pHead != NULL) {
		node <Type>*temp = pTail;
		pTail = temp->prev;
		temp->prev->next = NULL;
		temp->prev = NULL;
		delete temp;
	}
	count--;
}
template <class Type> void DoublyLinkedList<Type>::Remove(int index)
{
	node <Type>*temp = pHead;
	int i = 0;
	while (temp != NULL && i < index) {
		temp = temp->next;
		i++;
	}
	if (temp != NULL) {
		if (temp->prev != NULL)	temp->prev->next = temp->next;
		if (temp == pHead) pHead = pHead->next;
		if (temp == pTail) pTail = pTail->prev;
		temp->next = NULL;
		temp->prev = NULL;
		delete temp;
		count--;
	}
}
int main() {
	DoublyLinkedList <float>list;
	list.Add(2.4);
	list.Add(5.2);
	list.Add(7.6);
	list.Add(9.6, 6);
	list.Remove(2);
	list.print();
	system("pause");
	return 0;
}