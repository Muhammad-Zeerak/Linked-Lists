/* This space is left intentionally to improve readability */

/* This .cpp file contains the definition of Doubly Circular Linked List
We have made this class generic by using 'template' keyword
having 'X' as a placeholder for the datatype */

#include <iostream>
#include "List.cpp"

using namespace std;

template <class X>
class DoublyCircularLinkedList: public List<X> { // class DoublyCircularLinkedList starts

private:

	int len; // length of list

	class Node { // class node starts

	public:
		X info; // value in node
		Node* next; // pointer to next node
		Node* prev; // pointer to previous node

		Node(X val = 0, Node * next = NULL, Node * prev = NULL) { // constructor of node
			this->info = val;
			this->next = next;
			this->prev = prev;
		} // constructor ends
	}; // end class node

	Node* head, * tail; // pointer to head and tail

public:

	// constructor definition starts here
	DoublyCircularLinkedList() {
		head = tail = NULL;
		len = 0;
	}

	// memeber function definition starts here
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
			tail->next = head; // adjusting tail
			tail->prev = head;
		}
		else
		{
			temp->next = head;
			temp->prev = tail;
			head->prev = temp;
			head = temp;
			tail->next = head;
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
			tail->next = head;
			tail->prev = head; //adjusting tail
		}
		else
		{
			tail->next = temp; // adjusting tail
			temp->prev = tail;
			tail = temp;
			tail->next = head;
			head->prev = tail;
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

			current->prev = newNode; // new node added here
			prev->next = newNode;
			len++; // length incremented
		}
		else {
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
				head->prev = tail; // adjusting head and tail
				tail->next = head;
				delete temp; // delete node
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
				tail->next = head; // adjusting tail and head
				head->prev = tail;
				len--; // decrement length
			}
		}
	} // end function 

	  // this function deleted node at provided index
	void deleteNodeAt(int index = 0) {

		if (index == 0) // if index is 1 deelte first node
			deleteFirst();

		else if (index == len) // last node deleted
			deleteLast();

		else if (index > 0 && index < len) {
			if (!isEmpty()) {
				Node* current = head, * prev = NULL;

				for (int i = 0; i < index; i++) {
					prev = current;
					current = current->next;
				}

				prev->next = current->next; // adjusting other pointers
				current->next->prev = prev;

				delete current; // delete node
				len--;
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

		if (isEmpty()) { // no node present
			cout << "Delete operation cannot be done. List is empty." << endl;
		}
		else if (head->info == val) { // first node has value
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
			if (i != len - 1) {// deletes node if value found
				delNode = ptr->next;
				ptr->next = ptr->next->next;
				delNode->next->prev = delNode->prev;
				delete delNode;
				len--; // decrement length
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
			do {
				cout << ptr->info << " "; // prompt for output
				ptr = ptr->next;
			} while (ptr != head);
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
			} while (ptr != head);

			if (!flag) { // value not found
				cout << "No node with such value exists" << endl;
			}
		}
		else {
			cout << "List is empty." << endl;
		}
	} // end function
}; // end class DoublyCircularLinkedList