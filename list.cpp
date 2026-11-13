//----- List.cpp -----
#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;

#include "list.h"

string toLower(string word);
//-- Definition of the class constructor
List::List()
	: first(NULL), mySize(0)
{ }

//-- Definition of the copy constructor
List::List(const List & origList)
{
	mySize = origList.mySize;
	first = 0;
	if (mySize == 0) return;
	NodePointer origPtr, lastPtr;
	first = new Node(origList.first->data); // copy first node
	lastPtr = first;
	origPtr = origList.first->next;
	while (origPtr != 0)
	{
		lastPtr->next = new Node(origPtr->data);
		origPtr = origPtr->next;
		lastPtr = lastPtr->next;
	}
}
//-- Definition of the destructor
inline List::~List()
{
	NodePointer prev = first,
		ptr;
	while (prev != 0)
	{
		ptr = prev->next;
		delete prev;
		prev = ptr;
	}
}

//-- Definition of the assignment operator
const List& List::operator=(const List& rightSide)
{
	if (this != &rightSide)  //if not self-assigning
	{
		this->~List();     //de-allocate the nodes on left side operand
		first = NULL;	   //the destructor doesn't do this,as it is usually going away
		mySize = rightSide.mySize;
		if (mySize != 0)
		{
			NodePointer origPtr, lastPtr;
			first = new Node(rightSide.first->data); // copy first node
			lastPtr = first;
			origPtr = rightSide.first->next;
			while (origPtr != 0)
			{
				lastPtr->next = new Node(origPtr->data);
				origPtr = origPtr->next;
				lastPtr = lastPtr->next;
			}
		}
	}
	return *this;
}

void List::insertSorted(ElementType item) {
	NodePointer newNode = new Node;
	newNode->data = item;
	newNode->next = NULL;
	mySize++;

	if (first == NULL || toLower(item.getName()) < toLower(first->data.getName())) {
		newNode->next = first;
		first = newNode;
		return;
	}

	NodePointer ptr = first;

	while (ptr->next != NULL && toLower(ptr->next->data.getName()) < toLower(item.getName())) {
		ptr = ptr->next;
	}

	newNode->next = ptr->next;
	ptr->next = newNode;
}

bool List::erase(string itemName) {
	NodePointer ptr = first;
	NodePointer prev = NULL;

	while (ptr != NULL) {
		if (toLower(ptr->data.getName()) == toLower(itemName)) {
			if (prev == NULL) {
				first = ptr->next;
			}
			else {
				prev->next = ptr->next;
			}
			delete ptr;
			mySize--;
			return true;
		}
		prev = ptr;
		ptr = ptr->next;
	} 
	return false;
}

cameraItem* List::search(string itemName) const {
	NodePointer ptr = first;
	while (ptr != NULL) {
		if (toLower(ptr->data.getName()) == toLower(itemName))
			return &(ptr->data);
		else
			ptr = ptr->next;
	}
	return NULL;
}

void List::display(ostream& out) const {
	for (NodePointer ptr = first; ptr != NULL; ptr = ptr->next) {
		out << ptr->data;
	}
}

void List::displayRev(ostream& out) const {
	Stack stack;
	NodePointer ptr = first;
	while (ptr != NULL) {
		stack.push(ptr->data);
		ptr = ptr->next;
	}
	stack.display(out);
}

//-- Definition of the output operator
ostream & operator<<(ostream & out, const List & aList)
{
	aList.display(out);
	return out;
}

string toLower(string word) {
	string newWord = "";
	for (int i = 0; i < word.length(); i++) {
		newWord += tolower(word[i]);
	}
	return newWord;
}

void List::writeToFile() {
	ofstream outFile("newlist.txt");

	NodePointer ptr = first;

	while (ptr != NULL) {
		outFile << ptr->data;
		ptr = ptr->next;
	}
	outFile.close();
}