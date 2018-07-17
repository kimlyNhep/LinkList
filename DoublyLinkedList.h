#pragma once
template <class Type>
class node {
public:
	Type value;
	node <Type>*next;
	node <Type>*prev;
	node() {
		next = NULL;
		prev = NULL;
	}
};
template <class Type>
class DoublyLinkedList
{
	int count;
	node <Type>*pHead;
	node <Type>*pTail;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void Add(Type);
	void Add(Type, int);
	void print();
	void Remove();
	void Remove(int);
};

