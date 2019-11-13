/* This space is left intentionally to improve readability */

/* This .cpp file contains the definition of Doubly Linked List
We have made this class generic by using 'template' keyword
having 'X' as a placeholder for the datatype */

#include <iostream>
#include "List.cpp"

using namespace std;

template <class X>
class DoublyLinkedList: public List<X> {

private:

	int len; // list length 

	class Node { // class begins

	public:
		X info; // data in node
		Node* next; // pointer to next node
		Node* prev; // pointer to previous node

		Node(X val = 0, Node* next = NULL , Node* prev = NULL) { // node constructor
			this->info = val;
			this->next = next;
			this->prev = prev;
		} // constructor ends
	}; // class node ends

	Node* head, *tail; // pointers to head and tail of node 

public:

	// constructor definition begins here
	DoublyLinkedList() {
		head = tail = NULL;
		len = 0;
	}

	// member function definition starts 
	bool isEmpty() {
		return head == NULL;
	}

	int length() {
		return this->len;
	}

	// this function adds node with provided value at the start
	void addNodeStart(X val)
	{
		Node* temp = new Node(val); 
		len++;

		if (isEmpty()) // no node in list
		{
			head = tail = temp;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	} // end funtion

	// this function adds node at the end
	void addNodeEnd(X val)
	{
		Node* temp = new Node(val);
		len++;

		if (isEmpty()) // no node present
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	} // end function 

	  // By default, it inserts the node at the start
	void addNode(X val, int index = 0) {		

		if (index == len) // add at end
			addNodeEnd(val);

		else if (index == 0) // add at start
			addNodeStart(val);

		else if (index > 0 && index < len) { // add in between

			Node* current = head, * prev = NULL;

			for (int i = 0; i < index; i++) {
				prev = current;
				current = current->next;
			}

			Node* newNode = new Node(val, current, prev);

			current->prev = newNode;
			prev->next = newNode;
			len++; // increment length
		}
		else { // if given index is not a valid
			cout << "Invalid index. Please try again." << endl;
		}
	} // end function

	// this function deletes first node
	void deleteFirst()
	{
		if (isEmpty()) // no node exists
		{
			cout << "List is Empty!" << endl;
		}
		else
		{
			if (head == tail) // if single node exists
			{
				delete head; 
				head = tail = NULL;
				len--; // decrement length
			}
			else // if multiple nodes are present
			{
				Node* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
				len--;
			}
		}
	} // end function

	// this function deletes the last node
	void deleteLast() {

		if (isEmpty()) // no node exists
		{
			cout << "List is Empty!" << endl;
		}
		else
		{
			if (head == tail) // if single node exists
			{
				delete head;
				head = tail = NULL;
				len--;
			}
			else
			{
				Node* temp = tail;
				tail = tail->prev;
				delete temp;
				tail->next = NULL;
				len--; // decrement length
			}
		}
	} // end function 

	// this function deleted node at provided index
	void deleteNodeAt(int index)	{ 
		
		if (index == 0) // if index is 1 deelte first node
			deleteFirst();

		else if (index == len - 1) // last node deleted
			deleteLast();

		else if (index > 0 && index < len - 1) { 
			if (!isEmpty()) {
				Node* current = head, * prev = NULL;

				for (int i = 0; i < index; i++) {
					prev = current;
					current = current->next;
				}

				prev->next = current->next; // adjusting other pointers
				current->next->prev = prev;

				delete current; // delete current 
				len--; // decerement length
			}
			else {
				cout << "Invalid index." << endl;
			}
		}
		else
			cout << "List is empty." << endl;
	} // end function

	// this function deletes the node which contains the provided value
	void deleteNode(X val) {

		Node* ptr, * delNode;

		if (isEmpty()) {
			cout << "Delete operation cannot be done. List is empty." << endl;
		}
		else if (head->info == val) {
			deleteFirst();
		}
		else if (tail->info == val) {
			deleteLast();
		}
		else { // if value is somewhere in middle
			ptr = head;
			int i = 0;

			while (ptr->next->info != val && i < len - 1) { // finding the index of node where value is present
				ptr = ptr->next;
				i++;
			}
			if (i < len - 1) { // deletes node if value found
				delNode = ptr->next;
				ptr->next = ptr->next->next;
				delNode->next->prev = delNode->prev;
				delete delNode;
				len--;
			}
			else {
				cout << "Value does not exist." << endl;
			}
		}
	} // end function

	// this function displays the list
	void displayList()
	{
		Node* ptr = head;

		if (isEmpty())
		{
			cout << "List is Empty!" << endl; // prompt for output
		}
		else
		{
			while (ptr)
			{
				cout << ptr->info << " "; // prompt for output
				ptr = ptr->next;
			}
			cout << endl;
		}
	} // end function

	// this function searches for index of the given values
	void searchFor(X val) {

		if (!isEmpty()) {
			Node* ptr = head;
			int index = 0;
			int flag = 0;

			do {
				if (ptr->info == val) { // if value is present
					if (!flag) { 
						cout << "Found at following indicies:\n";
					}
					cout << "Index: " << index << endl;
					flag = 1; // set flag to true
				}
				ptr = ptr->next;
				index++;
			} while (ptr);

			if (!flag) { // value not found
				cout << "No node with such value exists" << endl;
			}
		}
		else { 
			cout << "List is empty." << endl;
		}
	} // end function
}; // end class DoublyLinkedList
