#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "item.h"
using namespace std;

typedef cameraItem ElementType;
class List {
private:
	class Node {
	public:
		ElementType data;
		Node* next;

		Node()
			: next(0) {
		}

		Node(ElementType dataValue)
			: data(dataValue), next(0) {
		}
	}; //--- end of Node class

	typedef Node* NodePointer;

public:
	//------ List OPERATIONS
	List();    //default constructor, creates an empty list
	List(const List& origList);  //copy constructor - avoids shallow copies
	~List();  //destructor - avoids memory leak
	const List& operator=(const List& rightSide);  //overloaded assignment operator
	
	void insertSorted(ElementType);
	bool erase(string itemName);
	cameraItem* search(string itemName) const;

	void display(ostream& out) const;
	void displayRev(ostream& out) const;

	void writeToFile();
private:
	//------ DATA MEMBERS
	NodePointer first;
	int mySize;
}; //--- end of List class

ostream& operator<<(ostream& out, const List& aList);
//istream & operator>>(istream & in, List & aList);
#endif