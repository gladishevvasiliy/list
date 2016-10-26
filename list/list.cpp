// list.cpp: определяет точку входа для консольного приложения.
#include "stdafx.h"
#include "list.h"



DoubleLinkedList::DoubleLinkedList()
{
	head = NULL;
	tail = NULL;
}

DoubleLinkedList::~DoubleLinkedList()
{}

bool DoubleLinkedList::isEmpty()
{
	if (head == NULL && tail == NULL)
		return true;
	else return false;
}

void DoubleLinkedList::add(int num) {
	elem *curr = new elem;
	curr->num = num;
	if (isEmpty()) {
		curr->prev = NULL;
		curr->next = NULL;
		head = curr;
		tail = curr;		
	}
	else {
		curr->num = num;
		curr->prev = NULL;
		curr->next = head;
		head = curr;
	}
}

void DoubleLinkedList::append(int num) {
	elem *curr = new elem;
	if (isEmpty()) {
		curr->num = num;
		curr->next = NULL;
		curr->prev = NULL;
		tail = head = curr;

	}
	else {
		curr->num = num;
		tail->next = curr;
		curr->prev = tail;		
		tail = curr;
		curr->next = NULL;
	}
}

void DoubleLinkedList::addAfter(int numBefore, int num) {

	if (isEmpty()) return;
	else
	{
		elem* curr = find(numBefore), *newList = new elem();
		newList->num = num;
		newList->prev = curr;
		newList->next = curr->next;
		curr->next->prev = newList;
		curr->next = newList;
	}
}

DoubleLinkedList::elem* DoubleLinkedList::find(int num)
{
	if (isEmpty()) return NULL;
	else
	{
		elem* curr = head;
		while (curr != NULL && curr->num != num)
		{
			curr = curr->next;
		}
		return curr;
	}
}

void DoubleLinkedList::printList()
{
	elem* curr = head;
	while (curr != NULL)
	{
		cout << curr->num << " ";
		curr = curr->next;
	}
	cout << endl;
}

void DoubleLinkedList::sortList() {
	if (isEmpty()) {
		cout << "list is empty" << endl;
	}
	else {
		elem* curr = head;
		while (curr->next) {
			if (curr->num > curr->next->num) {
				swapList(curr->num, curr->next->num);
				/*int num = curr->num;
				curr->num = curr->next->num;
				curr->next->num = num;*/
				sortList();
			}
			else curr = curr->next;
		}	
	}
}

void DoubleLinkedList::swapList(int &num1, int &num2){
		int tmp = num1;
		num1 = num2;
		num2 = tmp;
}

DoubleLinkedList::elem* DoubleLinkedList::searchList(int num) {
	if (isEmpty()) {
		cout << "list is empty" << endl;
	}
	else {
		elem* curr = head;
		while (curr->num != num && curr != NULL) {
			curr = curr->next;
		}
		return curr;
	}

}

void DoubleLinkedList::deleteElem(int num){
	if (isEmpty()) cout << "not list" << endl;
	else{
		elem* curr = searchList(num);
		if (curr->prev != NULL && curr->next != NULL){
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr;
			return;
		}
		if (curr->prev == NULL && curr->next != NULL){
			head = curr->next;
			delete curr;
			return;
		}
		if (curr->prev != NULL && curr->next == NULL){
			tail = curr->prev;
			delete curr;
			return;
		}
		if (curr->prev == NULL && curr->next == NULL){
			delete curr;
			head = NULL;
			tail = NULL;
			return;
		}
	}
}