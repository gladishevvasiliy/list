#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace std;

class DoubleLinkedList
{
private:
	struct elem {
		int num;
		elem* prev;
		elem* next;
	};
	elem* head, *tail;


public:

	DoubleLinkedList();

	~DoubleLinkedList();

	bool isEmpty();

	void add(int num);

	void append(int num);

	void addAfter(int numBefore, int num);

	elem* find(int num);

	void printList();

	void sortList();

	void swapList(int &num1, int &num2);

	elem* searchList(int num);

	void deleteElem(int num);
};
