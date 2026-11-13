# cpp-inventory-system
A menu-driven C++ camera inventory program using a sorted linked list and file input/output.

## Features

- Display inventory in alphabetical or reverse-alphabetical order
- Add, edit, and delete inventory items
- Search for an item
- Store each item's name, price, minimum inventory level, and quantity
- Load inventory data from a text file and save updates to an output file

## Implementation

The inventory is stored in a sorted singly linked list. A stack is used to display the list in reverse order. Inventory records are read from `Inventory.txt` and saved to `newlist.txt`.

## Build and run

Open `cpp-inventory-system.slnx` in Visual Studio with C++ desktop development tools installed, then build and run the project.

The program expects `inventory.txt` to be available in its working directory.
