/* This space is left intentionally to improve readability */

/* This .cpp file contains the definition of Singly Circular Linked List
We have made this class generic by using 'template' keyword
having 'X' as a placeholder for the datatype */

#include <iostream>
#include "List.cpp"

using namespace std;

template <class X>
class SinglyCircularLinkedList: public List<X> { // class starts

private:

	class Node { // class node starts

	public:
		X info; // data in node
		Node* next; // pointer to next node

		// constructor definition
		Node(X val = 0, Node * ptr = NULL) {
			this->info = val;
			this->next = ptr;
		}
	}; // end class

	int len; // length of list

	Node* head; // pointers to head and tail
	Node* tail;

public:

	// Construction defition starts here
	SinglyCircularLinkedList() {
		head = tail = NULL;
		len = 0;
	}

	// Member function's definition starts here

	bool isEmpty() {
		return head == NULL;
	}

	int length() {
		return this->len;
	}

	// add node function at end
	void addNodeEnd(X val) {

		Node* newNode = new Node(val);

		len++; // lenght incremented

		if (isEmpty()) { // add at start
			head = tail = newNode;
			tail->next = head;
		}
		else { // add at end
			tail->next = newNode;
			tail = newNode;
			tail->next = head;
		}
	} // end function

	// this add the node at given index, by default inserts at the start
	void addNode(X val, int index = 0) {

		if (index == len)		// in case user enters the end index
			addNodeEnd(val);

		else if (index >= 0 && index < len) { 

			Node* current = head, * prev = NULL;

			for (int i = 0; i < index; i++) { 
				prev = current;
				current = current->next; // pointer to next node
			}

			Node* newNode = new Node(val, current);

			if (isEmpty()) { // if no node
				head = tail = newNode;
				tail->next = head; // tail points to head for circular
			}
			else if (!prev) {
				head = newNode;
				tail->next = head;
			}
			else {
				prev->next = newNode;
			}
			len++; // length increment
		}
		else {
			cout << "Invalid index. Please try again." << endl;
		}
	} // end function

	// this function deletes the node by value
	void deleteNode(X val) {

		Node* ptr, * delNode;

		if (isEmpty()) { // no node present
			cout << "Delete operation cannot be done. List is empty." << endl;
		}
		else if (head->info == val) { // if value present
			ptr = head;
			head = head->next;
			tail->next = head;
			delete ptr;
			len--; //decrement length
		}
		else {
			ptr = head;
			int i = 0;
			while (ptr->next->info != val && i < len - 1) {	// searches for given value
				ptr = ptr->next;
				i++;
			}
			if (i < len - 1) {
				delNode = ptr->next;
				ptr->next = ptr->next->next;
				if (tail == delNode) {
					tail = ptr;
				}
				delete delNode; // deletes the node
				len--;
			}
			else {
				cout << "Value does not exist." << endl;
			}
		}
	} // end function

	// this deletes the node by given index
	void deleteNodeAt(int index) {

		if (index == 0) // if index is 1 
			deleteFirst();

		else if (index >= 0 && index < len) {
			if (!isEmpty()) {
				Node* current = head, * prev = NULL;

				for (int i = 0; i < index; i++) {
					prev = current;
					current = current->next;
				}
				prev->next = current->next;
				if (current == tail) {			// Adjusting tail
					tail = prev;
				}
				delete current;
				len--; // decrement length
			}
			else {
				cout << "Invalid index." << endl;
			}
		}
		else {
			cout << "List is empty." << endl;
		}
	} // end function

	// this function deletes first node
	void deleteFirst() {

		Node* ptr;
		if (!isEmpty()) {
			ptr = head;
			if (len == 1) {			// If there is only 1 node in the list
				delete ptr;
				head = tail = NULL;
			}
			else { // if multiple nodes
				head = head->next;
				tail->next = head;
				delete ptr;
			}
			len--;
		}
		else {
			cout << "List is empty." << endl;
		}
	} // end function

	// this function displays the list elements
	void displayList() {

		Node* ptr = head;

		if (!isEmpty()) {
			do {
				cout << ptr->info << " "; // prompt for output
				ptr = ptr->next;
			} while (ptr != head);
			cout << endl;
		}
		else {
			cout << "The list is empty." << endl;
		}
	} // end function

	// searches for given value and returns the index of given values
	void searchFor(X val) {

		if (!isEmpty()) { 
			Node* ptr = head;
			int index = 0;
			int flag = 0; // flag set to false when found will be true

			do {
				if (ptr->info == val) { // if value exists in list
					if (!flag) {
						cout << "Found at following indicies:\n";
					}
					cout << "Index: " << index << endl;
					flag = 1; // flag true
				}
				ptr = ptr->next;
				index++;
			} while (ptr != head);

			if (!flag) {
				cout << "No node with such value exists" << endl;
			}
		}
		else {
			cout << "List is empty." << endl;
		}
	} // end function

	void deleteLast() {
		deleteNodeAt(len-1);
	}

	void addNodeStart(X val) {
		addNode(val);
	}
}; // end class SinglyCircularLinkedList
