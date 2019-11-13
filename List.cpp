/* This space is left intentionally to improve readability */

/* This .cpp file contains the definition of list class
which will be the super class of all other linked list classes */

#pragma once

template <class X>
class List {

public:

	virtual bool isEmpty() = 0;

	virtual int length() = 0;

	virtual void addNodeEnd(X val) = 0;

	virtual void addNode(X val, int index) = 0;

	virtual void addNodeStart(X val) = 0;

	virtual void deleteFirst() = 0;

	virtual void deleteLast() = 0;

	virtual void deleteNode(X val) = 0;

	virtual void deleteNodeAt(int index) = 0;

	virtual void displayList() = 0;

	virtual void searchFor(X val) = 0;
};