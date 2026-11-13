#include <iostream>
#include "item.h"

using namespace std;

cameraItem::cameraItem() {
	name = "";
	price = 0.0;
	minInv = 0;
	stock = 0;
}

cameraItem::cameraItem(string myName, double myPrice, int myMinInv, int myStock) {
	name = myName;
	price = myPrice;
	minInv = myMinInv;
	stock = myStock;
}

string cameraItem::getName() const {
	return name;
}
double cameraItem::getPrice() const {
	return price;
}
int cameraItem::getMinInv() const {
	return minInv;
}
int cameraItem::getStock() const {
	return stock;
}
void cameraItem::setName(string myName) {
	name = myName;
}
void cameraItem::setPrice(double myPrice) {
	price = myPrice;
}
void cameraItem::setMinInv(int myMinInv) {
	minInv = myMinInv;
}
void cameraItem::setStock(int myStock) {
	stock = myStock;
}

ostream& operator<<(ostream& out, const cameraItem& item) {
	out << item.getName() << " " << item.getPrice() << " " << item.getMinInv() << " " << item.getStock() << endl;
	return out;
}

istream& operator>>(istream& in, cameraItem& item) {
	string name;
	double price;
	int minInv, stock;
	in >> name >> price >> minInv >> stock;
	item.setName(name); item.setPrice(price); item.setMinInv(minInv); item.setStock(stock);
	return in;
}