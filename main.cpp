#include <iostream>
#include <fstream>
#include <string>
#include "item.h"
#include "list.h"

using namespace std;

int main() {
	ifstream inFile("inventory.txt");

	List list;
	cameraItem item;

	if (!inFile) {
		cerr << "Error opening file.\n";
		exit(1);
	}

	// Read items from file and insert them into the list in sorted order
	while (inFile >> item) {
		list.insertSorted(item);
	}

	int choice = 0;

	// Continue running until user chooses to exit
	while (choice != 6) {
		cout << "Camera Inventory System\n\n";
		cout << "1. Display Inventory (Alphabetical)\n";
		cout << "2. Display Inventory (Reverse Alphabet)\n";
		cout << "3. Add Item\n";
		cout << "4. Delete Item\n";
		cout << "5. Edit Item\n";
		cout << "6. Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:
			list.display(cout);
			cout << "\n\n";
			break;
		case 2:
			list.displayRev(cout);
			cout << "\n\n";
			break;
		case 3: {
			string name; int minInv; int stock; double price;
			cout << "Enter item name: ";
			cin >> name;
			cout << "Enter price: ";
			cin >> price;
			cout << "Enter minimum inventory stock: ";
			cin >> minInv;
			cout << "Enter quantity: ";
			cin >> stock;
			list.insertSorted(cameraItem(name, price, minInv, stock));
			cout << "\nItem added successfully.\n\n\n";
			break;
		}
		case 4: {
			string itemName;
			cout << "Enter an item name to delete: ";
			cin >> itemName;
			bool check = list.erase(itemName);
			if (check)
				cout << "\nItem deleted successfully.\n\n\n";
			else
				cout << "\nError -- Item not found.\n\n\n";
			break;
		}
		case 5: {
			string itemName, newItemName;
			double newPrice;
			int newMinInv, newStock;
			cout << "Enter item name to edit: ";
			cin >> itemName;

			cameraItem* test = list.search(itemName);

			if (test == NULL) {
				cout << "\nItem not found.\n\n";
				break;
			}

			cout << "\n(Current: " << test->getName() << ", " << test->getPrice() << ", " << test->getMinInv() << ", " << test->getStock() << ")\n\n";

			cout << "Enter new item name: ";
			cin >> newItemName;
			cout << "Enter new price: ";
			cin >> newPrice;
			cout << "Enter new minimum inv: ";
			cin >> newMinInv;
			cout << "Enter new stock: ";
			cin >> newStock;

			list.erase(itemName);
			list.insertSorted(cameraItem(newItemName, newPrice, newMinInv, newStock));
			cout << "\nItem updated successfully.\n\n\n";
			break;
		}
		case 6:
			break;
		default:
			cout << "Error! Invalid.\n\n\n";
			break;
		}
	}

	list.writeToFile();
	inFile.close();
	cout << "Saving inventory to newlist.txt...\n";
	cout << "Program terminated.\n";
}