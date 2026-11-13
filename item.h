#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

struct cameraItem {
public:
	cameraItem();
	cameraItem(string, double, int, int);

	string getName() const;
	double getPrice() const;
	int getMinInv() const;
	int getStock() const;

	void setName(string);
	void setPrice(double);
	void setMinInv(int);
	void setStock(int);

private:
	string name;
	double price;
	int minInv, stock;
};

ostream& operator<<(ostream&, const cameraItem&);
istream& operator>>(istream&, cameraItem&);

#endif