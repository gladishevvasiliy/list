#include "stdafx.h"
#include "list.h"


int main() {

	DoubleLinkedList list;
	for (int i = 0; i < 10; i++)
	{
		list.add(i);
	}
	list.printList();

	list.addAfter(3, 4);
	list.printList();

	list.append(5);
	list.printList();

	list.sortList();
	list.printList();

	cout << list.searchList(4) << endl;

	list.deleteElem(1);
	list.printList();

	_getch();
	return 0;
}