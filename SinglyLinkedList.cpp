/* This space is left intentionally to improve readability */

/* This .cpp file contains the definition of Singly Linked List
We have made this class generic by using 'template' keyword
having 'X' as a placeholder for the datatype */

#include <iostream>
#include "List.cpp"

using namespace std;

template <class X>
class SinglyLinkedList: public List<X> { // class singlylinkedlist starts

private:

	// class node starts

	class Node {

	public:
		X info; // data in node
		Node* next; // pointer to next node

		Node(X val = 0, Node * ptr = NULL) { // constructor for node
			this->info = val;
			this->next = ptr;
		}
	}; // class node ends

	int len; // length of node variable

	Node* head; // pointer to head
	Node* tail; // pointer to tail

public:

	// Constructor defition starts here

	SinglyLinkedList() {
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

	// thid function add node with the provided value at the end of the linked list
	void addNodeEnd(X val) {

		Node* newNode = new Node(val);

		len++; // length increases as new node is added

		if (head == NULL) { // if no node is present
			head = tail = newNode;
		}
		else { // if there are any nodes
			tail->next = newNode;
			tail = newNode;
		}
	}

	// this function add node with the respective value at the given index
	virtual void addNode(X val, int index = 0) {		// By default, it inserts the data at the start

		if (index == len) // adds node at end because index is same as len i.e the number of nodes already present
			addNodeEnd(val);

		else if (index >= 0 && index < len) { // adds somwhere in between

			Node* current = head, *prev = NULL;


			for (int i = 0; i < index; i++) {
				prev = current;
				current = current->next;
			}

			Node* newNode = new Node(val, current);
			if (head == NULL) { // if no node present
				head = tail = newNode;
			}
			else if (!prev) {
				head = newNode;
			}
			else {
				prev->next = newNode;
			}
			len++;
		}
		else {
			cout << "Invalid index. Please try again." << endl;
		}
	} // function addNode ends

	  // deletes the node which has same value as the value provided
	void deleteNode(X val) {		// Delete node by value

		Node* ptr, *delNode;

		if (isEmpty()) { // if list is empty 
			cout << "Delete operation cannot be done. List is empty." << endl;
		}
		else if (head->info == val) { // if the provided value is present at the first node
			ptr = head;
			head = head->next;
			delete ptr;
			len--; // decrement length because node is demolished
		}
		else { // if value is in between somwhere
			ptr = head;
			int i = 0;
			while (ptr->next->info != val && i < len - 1) { // finds the node where the value is present
				ptr = ptr->next;
				i++;
			}
			if (i != len - 1) { // delete the node where value is found
				delNode = ptr->next;
				ptr->next = ptr->next->next;
				delete delNode;
				len--;
			}
			else { // value is not in the list
				cout << "Value does not exist." << endl;
			}
		}
	} // end function delete by value

	void deleteNodeAt(int index) {			// Delete node by the respective index 

		if (!isEmpty()) {
			if (index >= 0 && index < len) {
				Node* current = head, *prev = NULL;

				for (int i = 0; i < index; i++) {
					prev = current;
					current = current->next; // stores the node in current that is to be deleted
				}
				prev->next = current->next;
				if (!current->next) {			// Adjusting tail
					tail = prev;
				}
				delete current; // delete the node
				len--; // decrement length
			}
			else {
				cout << "Invalid index." << endl;
			}
		}
		else
			cout << "List is empty." << endl;
	} // function ends

	void deleteFirst() { // delete first node 

		Node* ptr;
		if (!isEmpty()) {
			ptr = head;
			head = head->next;
			if (!head) {			// If there is only 1 node in the list
				tail = head;
			}
			delete ptr;
			len--;
		}
		else { // list is empty
			cout << "List is empty." << endl;
		}
	} // end function

	void displayList() { // this function displays all the data of the nodes

		Node* ptr = head;

		if (!isEmpty()) {
			while (ptr) {
				cout << ptr->info << " "; // prompt for output
				ptr = ptr->next; // ptr points to next node now
			}
			cout << endl;
		}
		else {
			cout << "The list is empty." << endl;
		}
	} // end function

	void searchFor(X val) { // this function search for the given value and display the index at which it is found

		if (!isEmpty()) {
			Node* ptr = head;
			int index = 0;
			int flag = 0;

			do {
				if (ptr->info == val) {
					if (!flag) {
						cout << "Found at following indicies:\n"; // prompt for output
					}
					cout << "Index: " << index << endl;
					flag = 1; // flag true / 1 now i.e number found
				}
				ptr = ptr->next;
				index++;
			} while (ptr);

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
};