/* This space is left intentionally to improve readability */

/* This .cpp file contains the definition of main */

#include<iostream>
#include<string>

#include "SinglyCircularLinkedList.cpp"
#include "SinglyLinkedList.cpp"
#include "DoublyLinkedList.cpp"
#include "DoublyCircularLinkedList.cpp"

using namespace std;

string type = "";

int getType() {

	int choice;
	string listChoice = "";

	do {
		cout << "\nSelect your data type\n\n1. Int\n2. Char\n3. Float\n4. Long\n\nChoice: ";
		cin >> choice;

	} while (choice < 1 || choice > 4);

	system("cls");
	listChoice += to_string(choice);

	do {
		cout << "\nSelect your list type\n\n1. Singly\n2. Singly Circular\n3. Doubly\n4. Doubly Circular\n\nChoice: ";
		cin >> choice;
	} while (choice < 1 || choice > 4);

	listChoice += to_string(choice);
	return stoi(listChoice);
}

template <class X>
List<X>* makeList(int choice) {

	switch (choice) {
	case 1:
		type = "Singly List";
		return new SinglyLinkedList<X>;
	case 2:
		type = "Singly Circular List";
		return new SinglyCircularLinkedList<X>;
	case 3:
		type = "Doubly List";
		return new DoublyLinkedList<X>;
	case 4:
		type = "Doubly Circular List";
		return new DoublyCircularLinkedList<X>;
	}
}

template <class X>
void insertValue(List<X>* ptr, int choice) {

	X val;
	int index;

	cout << "\nEnter a value to insert: ";
	cin >> val;

	switch (choice) {
	case 1:
		ptr->addNodeStart(val);
		break;
	case 2:
		cout << "\nEnter an index: ";
		cin >> index;
		ptr->addNode(val, index);
		break;
	case 3:
		ptr->addNodeEnd(val);
		break;
	default:
		cout << "Invalid command.\n";
	}
}

template <class X>
void deleteValue(List<X>* ptr, int choice) {

	int index;
	switch (choice) {
	case 1:
		ptr->deleteFirst();
		break;
	case 2:
		cout << "\nEnter index of node: ";
		cin >> index;
		ptr->deleteNodeAt(index);
		break;
	case 3:
		ptr->deleteLast();
		break;
	default:
		cout << "Invalid command.\n";
	}
}

template <class X>
void startProgram(List<X>* ptr) {

	int choice;
	X val;

	while (true) {
		system("cls");
		cout << type << endl;
		cout << "\n\n1. Insert a value\n2. Delete a value\n3. Search For a value\n4. Display list\n5. Exit\n\nChoice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			cout << type << endl;
			cout << "\n\n1. Insert at head\n2. Insert at an index\n3. Insert at tail\n\nChoice:";
			cin >> choice;
			insertValue(ptr, choice);
			cout << "List: ";
			ptr->displayList();
			system("pause");
			break;
		case 2:
			system("cls");
			cout << type << endl;
			cout << "\n\n1. Delete head node\n2. Delete node at an index\n3. Delete tail node\n\nChoice: ";
			cin >> choice;
			deleteValue(ptr, choice);
			cout << "List: ";
			ptr->displayList();
			system("pause");
			break;
		case 3:
			cout << type << endl;
			cout << "\n\nEnter a value to search: ";
			cin >> val;
			ptr->searchFor(val);
			cout << endl;
			system("pause");
			break;
		case 4:
			cout << type << endl;
			cout << "\n\nList: ";
			ptr->displayList();
			cout << endl;
			system("pause");
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "Please enter a valid command.\n";
			system("pause");
		}
	}
}

int main()
{
	List<int>* listPtr1;
	List<char>* listPtr2;
	List<float>* listPtr3;
	List<long>* listPtr4;

	int choice = getType();

	switch (choice / 10) {

	case 1:
		listPtr1 = makeList<int>(choice % 10);
		type += " for int";
		startProgram<int>(listPtr1);
		break;
	case 2:
		listPtr2 = makeList<char>(choice % 10);
		type += " for char";
		startProgram<char>(listPtr2);
		break;
	case 3:
		listPtr3 = makeList<float>(choice % 10);
		type += " for float";
		startProgram<float>(listPtr3);
		break;
	case 4:
		listPtr4 = makeList<long>(choice % 10);
		type += " for long";
		startProgram<long>(listPtr4);
		break;
	}	
}